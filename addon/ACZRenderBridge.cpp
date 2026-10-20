#include <Windows.h>
#include <reshade.hpp>

#include <atomic>
#include <cstdint>
#include <mutex>
#include <optional>
#include <shared_mutex>
#include <sstream>
#include <unordered_map>
#include <vector>

namespace
{
	using namespace reshade;
	using namespace reshade::api;

	constexpr uint64_t fnv_offset = 14695981039346656037ull;
	constexpr uint64_t fnv_prime = 1099511628211ull;

	uint64_t fnv1a(uint64_t hash, const void *data, size_t size)
	{
		const auto *bytes = static_cast<const uint8_t *>(data);
		for (size_t i = 0; i < size; ++i)
		{
			hash ^= bytes[i];
			hash *= fnv_prime;
		}
		return hash;
	}

	template <typename T>
	uint64_t fnv_value(uint64_t hash, const T &value)
	{
		return fnv1a(hash, &value, sizeof(value));
	}

	uint64_t hash_shader(const shader_desc &shader)
	{
		if (shader.code == nullptr || shader.code_size == 0)
			return 0;

		uint64_t hash = fnv_offset;
		hash = fnv_value(hash, shader.code_size);
		hash = fnv1a(hash, shader.code, shader.code_size);
		return hash;
	}

	struct pipeline_fingerprint
	{
		uint64_t stable = 0;
		uint64_t vs = 0;
		uint64_t ps = 0;
		uint32_t static_topology = 0;
	};

	std::unordered_map<uint64_t, pipeline_fingerprint> g_pipelines;
	std::shared_mutex g_pipeline_mutex;

	std::atomic<uint64_t> g_present_serial { 0 };
	std::atomic_bool g_hud_bootstrapped { false };

	void on_init_pipeline(
		device *,
		pipeline_layout,
		uint32_t subobject_count,
		const pipeline_subobject *subobjects,
		pipeline pipeline)
	{
		pipeline_fingerprint fp;
		uint64_t stable = fnv_offset;

		for (uint32_t i = 0; i < subobject_count; ++i)
		{
			const pipeline_subobject &sub = subobjects[i];
			stable = fnv_value(stable, sub.type);
			stable = fnv_value(stable, sub.count);

			switch (sub.type)
			{
			case pipeline_subobject_type::vertex_shader:
			case pipeline_subobject_type::geometry_shader:
			case pipeline_subobject_type::pixel_shader:
			{
				const auto *shaders = static_cast<const shader_desc *>(sub.data);
				for (uint32_t n = 0; n < sub.count; ++n)
				{
					const uint64_t shader_hash = hash_shader(shaders[n]);
					stable = fnv_value(stable, shader_hash);

					if (n == 0)
					{
						if (sub.type == pipeline_subobject_type::vertex_shader)
							fp.vs = shader_hash;
						else if (sub.type == pipeline_subobject_type::pixel_shader)
							fp.ps = shader_hash;
					}
				}
				break;
			}

			case pipeline_subobject_type::primitive_topology:
				if (sub.count != 0 && sub.data != nullptr)
				{
					const auto *values = static_cast<const primitive_topology *>(sub.data);
					fp.static_topology = static_cast<uint32_t>(values[0]);
					for (uint32_t n = 0; n < sub.count; ++n)
					{
						const uint32_t value = static_cast<uint32_t>(values[n]);
						stable = fnv_value(stable, value);
					}
				}
				break;

			case pipeline_subobject_type::render_target_formats:
				if (sub.data != nullptr)
				{
					const auto *values = static_cast<const format *>(sub.data);
					for (uint32_t n = 0; n < sub.count; ++n)
					{
						const uint32_t value = static_cast<uint32_t>(values[n]);
						stable = fnv_value(stable, value);
					}
				}
				break;

			case pipeline_subobject_type::depth_stencil_format:
				if (sub.count != 0 && sub.data != nullptr)
				{
					const uint32_t value =
						static_cast<uint32_t>(*static_cast<const format *>(sub.data));
					stable = fnv_value(stable, value);
				}
				break;

			case pipeline_subobject_type::sample_count:
				if (sub.count != 0 && sub.data != nullptr)
					stable = fnv_value(stable, *static_cast<const uint32_t *>(sub.data));
				break;

			default:
				break;
			}
		}

		fp.stable = stable;

		std::unique_lock lock(g_pipeline_mutex);
		g_pipelines[pipeline.handle] = fp;
	}

	void on_destroy_pipeline(device *, pipeline pipeline)
	{
		std::unique_lock lock(g_pipeline_mutex);
		g_pipelines.erase(pipeline.handle);
	}

	pipeline_fingerprint lookup_pipeline(uint64_t handle)
	{
		std::shared_lock lock(g_pipeline_mutex);
		const auto it = g_pipelines.find(handle);
		return it != g_pipelines.end() ? it->second : pipeline_fingerprint {};
	}

	struct draw_record
	{
		bool indexed = false;
		uint32_t count = 0;
		uint64_t pipeline = 0;
		pipeline_fingerprint fp = {};
		uint32_t topology = 0;
		resource_view rtv0 = { 0 };
		resource_view dsv = { 0 };
		uint64_t ordinal = 0;
	};

	struct bridge_stream_state
	{
		uint64_t pipeline = 0;
		uint32_t topology = 0;
		resource_view rtv0 = { 0 };
		resource_view dsv = { 0 };
		uint64_t ordinal = 0;
		std::optional<draw_record> prev2;
		std::optional<draw_record> prev1;
		uint64_t last_copied_present = UINT64_MAX;
		uint64_t frame_serial = UINT64_MAX;
		std::vector<draw_record> frame_draws;
		uint32_t miss_dump_budget = 3;
	};

	thread_local bridge_stream_state g_stream;

	struct __declspec(uuid("a8e9c0be-1464-4a7c-9f70-ecbf0702a97f")) bridge_device_data
	{
		std::mutex mutex;
		resource scene_clean = { 0 };
		resource_view scene_clean_srv = { 0 };
		resource_desc scene_desc = {};
		bool scene_desc_valid = false;
		bool scene_shader_ready = false;
		std::vector<resource> retired;
		std::vector<resource_view> retired_views;
		uint64_t copies = 0;
		bool unsupported_logged = false;
	};

	bool same_texture_shape(const resource_desc &a, const resource_desc &b)
	{
		return
			a.type == b.type &&
			a.texture.width == b.texture.width &&
			a.texture.height == b.texture.height &&
			a.texture.depth_or_layers == b.texture.depth_or_layers &&
			a.texture.levels == b.texture.levels &&
			a.texture.format == b.texture.format &&
			a.texture.samples == b.texture.samples;
	}

	resource_desc make_scene_clean_desc(const resource_desc &source)
	{
		const resource_usage transfer_usage =
			source.texture.samples > 1
				? resource_usage::resolve_dest
				: resource_usage::copy_dest;

		return resource_desc(
			resource_type::texture_2d,
			source.texture.width,
			source.texture.height,
			1,
			1,
			format_to_default_typed(source.texture.format),
			1,
			memory_heap::default_,
			transfer_usage | resource_usage::shader_resource,
			resource_flags::none);
	}

	bool is_main_hud_pipeline(const draw_record &d)
	{
		return
			d.fp.stable == 0xc45ffe89e386cb09ull &&
			d.fp.vs == 0x70848fc93426bb4eull &&
			d.fp.ps == 0xae6370c8685b4894ull &&
			d.topology == 0x5;
	}

	bool same_main_target(const draw_record &a, const draw_record &b)
	{
		return
			a.rtv0 != 0 &&
			a.dsv != 0 &&
			a.rtv0 == b.rtv0 &&
			a.dsv == b.dsv;
	}

	bool is_first_hud_anchor(
		const bridge_stream_state &state,
		const draw_record &current)
	{
		if (!state.prev2 || !state.prev1)
			return false;

		const draw_record &a = *state.prev2;
		const draw_record &b = *state.prev1;
		const draw_record &c = current;

		return
			a.indexed && a.count == 64 &&
			!b.indexed && b.count == 4 &&
			c.indexed && c.count == 89 &&
			is_main_hud_pipeline(a) &&
			is_main_hud_pipeline(b) &&
			is_main_hud_pipeline(c) &&
			same_main_target(a, b) &&
			same_main_target(b, c);
	}

	draw_record make_record(bool indexed, uint32_t count)
	{
		draw_record record;
		record.indexed = indexed;
		record.count = count;
		record.pipeline = g_stream.pipeline;
		record.fp = lookup_pipeline(g_stream.pipeline);
		record.topology =
			g_stream.topology != 0 ? g_stream.topology : record.fp.static_topology;
		record.rtv0 = g_stream.rtv0;
		record.dsv = g_stream.dsv;
		record.ordinal = g_stream.ordinal;
		return record;
	}

	void remember_draw(const draw_record &record)
	{
		g_stream.prev2 = g_stream.prev1;
		g_stream.prev1 = record;
		++g_stream.ordinal;
	}

	bool ensure_scene_clean(
		device *device,
		bridge_device_data &data,
		const resource_desc &source_desc)
	{
		const resource_desc desired = make_scene_clean_desc(source_desc);

		if (data.scene_clean != 0 &&
			data.scene_desc_valid &&
			same_texture_shape(data.scene_desc, desired))
			return true;

		resource replacement = { 0 };
		const resource_usage initial_transfer_state =
			source_desc.texture.samples > 1
				? resource_usage::resolve_dest
				: resource_usage::copy_dest;

		if (!device->create_resource(
				desired,
				nullptr,
				initial_transfer_state,
				&replacement))
		{
			std::ostringstream message;
			message
				<< "ACZRenderBridge: failed to create SceneClean "
				<< source_desc.texture.width << 'x' << source_desc.texture.height
				<< " format=" << static_cast<uint32_t>(source_desc.texture.format)
				<< " samples=" << source_desc.texture.samples;
			reshade::log::message(
				reshade::log::level::error,
				message.str().c_str());
			return false;
		}

		device->set_resource_name(replacement, "ACZ SceneClean");

		resource_view replacement_srv = { 0 };
		const resource_view_desc srv_desc(
			format_to_default_typed(desired.texture.format));

		if (!device->create_resource_view(
				replacement,
				resource_usage::shader_resource,
				srv_desc,
				&replacement_srv))
		{
			device->destroy_resource(replacement);
			reshade::log::message(
				reshade::log::level::error,
				"ACZRenderBridge: failed to create SceneClean SRV.");
			return false;
		}

		if (data.scene_clean_srv != 0)
			data.retired_views.push_back(data.scene_clean_srv);
		if (data.scene_clean != 0)
			data.retired.push_back(data.scene_clean);

		data.scene_clean = replacement;
		data.scene_clean_srv = replacement_srv;
		data.scene_desc = desired;
		data.scene_desc_valid = true;
		data.scene_shader_ready = false;

		std::ostringstream message;
		message
			<< "ACZRenderBridge: SceneClean allocated "
			<< desired.texture.width << 'x' << desired.texture.height
			<< " format=" << static_cast<uint32_t>(desired.texture.format)
			<< " samples=" << desired.texture.samples
			<< " source_samples=" << source_desc.texture.samples
			<< " resource=0x" << std::hex << replacement.handle
			<< " srv=0x" << replacement_srv.handle;
		reshade::log::message(
			reshade::log::level::info,
			message.str().c_str());

		return true;
	}

	void copy_scene_clean(command_list *cmd_list, const draw_record &anchor)
	{
		if (anchor.rtv0 == 0)
			return;

		device *device = cmd_list->get_device();
		if (device == nullptr)
			return;

		resource source = device->get_resource_from_view(anchor.rtv0);
		if (source == 0)
			return;

		const resource_desc source_desc = device->get_resource_desc(source);
		if (source_desc.type != resource_type::texture_2d ||
			source_desc.texture.width == 0 ||
			source_desc.texture.height == 0 ||
			source_desc.texture.samples == 0)
		{
			auto &data = *device->get_private_data<bridge_device_data>();
			if (!data.unsupported_logged)
			{
				data.unsupported_logged = true;
				std::ostringstream message;
				message
					<< "ACZRenderBridge: unsupported HUD target desc type="
					<< static_cast<uint32_t>(source_desc.type)
					<< " size=" << source_desc.texture.width
					<< 'x' << source_desc.texture.height
					<< " samples=" << source_desc.texture.samples;
				reshade::log::message(
					reshade::log::level::error,
					message.str().c_str());
			}
			return;
		}

		auto &data = *device->get_private_data<bridge_device_data>();
		std::lock_guard lock(data.mutex);

		if (!ensure_scene_clean(device, data, source_desc))
			return;

		const bool multisampled = source_desc.texture.samples > 1;
		const resource_usage transfer_dest =
			multisampled
				? resource_usage::resolve_dest
				: resource_usage::copy_dest;

		if (data.scene_shader_ready)
		{
			cmd_list->barrier(
				data.scene_clean,
				resource_usage::shader_resource,
				transfer_dest);
		}

		if (multisampled)
		{
			cmd_list->barrier(
				source,
				resource_usage::render_target,
				resource_usage::resolve_source);

			cmd_list->resolve_texture_region(
				source,
				0,
				nullptr,
				data.scene_clean,
				0,
				0,
				0,
				0,
				format_to_default_typed(source_desc.texture.format));

			cmd_list->barrier(
				source,
				resource_usage::resolve_source,
				resource_usage::render_target);
		}
		else
		{
			cmd_list->barrier(
				source,
				resource_usage::render_target,
				resource_usage::copy_source);

			cmd_list->copy_resource(source, data.scene_clean);

			cmd_list->barrier(
				source,
				resource_usage::copy_source,
				resource_usage::render_target);
		}

		cmd_list->barrier(
			data.scene_clean,
			transfer_dest,
			resource_usage::shader_resource);
		data.scene_shader_ready = true;

		++data.copies;

		if (data.copies <= 5 || (data.copies % 60) == 0)
		{
			std::ostringstream message;
			message
				<< "ACZRenderBridge: SceneClean copied before first HUD draw"
				<< " copies=" << data.copies
				<< " ordinal=" << anchor.ordinal
				<< " source=0x" << std::hex << source.handle
				<< " dest=0x" << data.scene_clean.handle
				<< " rtv=0x" << anchor.rtv0.handle
				<< std::dec
				<< " size=" << source_desc.texture.width
				<< 'x' << source_desc.texture.height
				<< " source_samples=" << source_desc.texture.samples
				<< (source_desc.texture.samples > 1 ? " resolved=1" : " resolved=0");
			reshade::log::message(
				reshade::log::level::info,
				message.str().c_str());
		}
	}

	void on_init_device(device *device)
	{
		device->create_private_data<bridge_device_data>();
	}

	void on_destroy_device(device *device)
	{
		auto *data = device->get_private_data<bridge_device_data>();
		if (data != nullptr)
		{
			if (data->scene_clean_srv != 0)
				device->destroy_resource_view(data->scene_clean_srv);

			for (resource_view retired_view : data->retired_views)
				if (retired_view != 0)
					device->destroy_resource_view(retired_view);

			if (data->scene_clean != 0)
				device->destroy_resource(data->scene_clean);

			for (resource retired : data->retired)
				if (retired != 0)
					device->destroy_resource(retired);
		}

		device->destroy_private_data<bridge_device_data>();
	}

	void update_effect_runtime(effect_runtime *runtime)
	{
		device *device = runtime->get_device();
		if (device == nullptr)
			return;

		auto *data = device->get_private_data<bridge_device_data>();
		if (data == nullptr)
			return;

		std::lock_guard lock(data->mutex);
		const resource_view srv =
			(data->scene_shader_ready && data->scene_clean_srv != 0)
				? data->scene_clean_srv
				: resource_view { 0 };

		runtime->update_texture_bindings(
			"ACZ_SCENE_CLEAN",
			srv,
			srv);
	}

	void on_reshade_begin_effects(
		effect_runtime *runtime,
		command_list *,
		resource_view,
		resource_view)
	{
		update_effect_runtime(runtime);
	}

	void on_bind_pipeline(
		command_list *,
		pipeline_stage,
		pipeline pipeline)
	{
		g_stream.pipeline = pipeline.handle;
	}

	void on_bind_pipeline_states(
		command_list *,
		uint32_t count,
		const dynamic_state *states,
		const uint32_t *values)
	{
		for (uint32_t i = 0; i < count; ++i)
			if (states[i] == dynamic_state::primitive_topology)
				g_stream.topology = values[i];
	}

	void on_bind_render_targets(
		command_list *,
		uint32_t count,
		const resource_view *rtvs,
		resource_view dsv)
	{
		g_stream.rtv0 =
			(count != 0 && rtvs != nullptr) ? rtvs[0] : resource_view { 0 };
		g_stream.dsv = dsv;
	}

	void dump_missed_frame(uint64_t present_serial)
	{
		if (g_stream.frame_draws.empty() || g_stream.miss_dump_budget == 0)
			return;

		std::ostringstream head;
		head
			<< "ACZRenderBridge: MISS FRAME present=" << present_serial
			<< " draws=" << g_stream.frame_draws.size()
			<< " (compact main-target candidates follow)";
		reshade::log::message(
			reshade::log::level::warning,
			head.str().c_str());

		for (const draw_record &d : g_stream.frame_draws)
		{
			if (d.rtv0 == 0 || d.dsv == 0)
				continue;

			// Keep the dump compact: target small/medium HUD-like draws and anything
			// using the previously known HUD shader fingerprint.
			const bool hud_like_count =
				d.count <= 128 ||
				(d.indexed && d.count <= 192);

			const bool known_hud_shader =
				d.fp.vs == 0x70848fc93426bb4eull ||
				d.fp.ps == 0xae6370c8685b4894ull;

			if (!hud_like_count && !known_hud_shader)
				continue;

			std::ostringstream line;
			line
				<< "ACZRenderBridge: FD "
				<< (d.indexed ? "IDX" : "DRAW")
				<< " count=" << d.count
				<< " ordinal=" << d.ordinal
				<< " pipeline=0x" << std::hex << d.pipeline
				<< " stable=0x" << d.fp.stable
				<< " vs=0x" << d.fp.vs
				<< " ps=0x" << d.fp.ps
				<< " topo=0x" << d.topology
				<< " rtv=0x" << d.rtv0.handle
				<< " dsv=0x" << d.dsv.handle;
			reshade::log::message(
				reshade::log::level::warning,
				line.str().c_str());
		}

		--g_stream.miss_dump_budget;
	}

	void on_present(
		command_queue *,
		swapchain *,
		const rect *,
		const rect *,
		uint32_t,
		const rect *)
	{
		const uint64_t finished =
			g_present_serial.load(std::memory_order_acquire);

		if (g_hud_bootstrapped.load(std::memory_order_acquire) &&
			g_stream.frame_serial == finished &&
			g_stream.last_copied_present != finished)
		{
			dump_missed_frame(finished);
		}

		g_present_serial.fetch_add(1, std::memory_order_release);
	}


	bool process_draw(
		command_list *cmd_list,
		bool indexed,
		uint32_t count)
	{
		const draw_record current = make_record(indexed, count);

		const uint64_t current_present =
			g_present_serial.load(std::memory_order_acquire);

		if (g_stream.frame_serial != current_present)
		{
			g_stream.frame_serial = current_present;
			g_stream.frame_draws.clear();
		}

		g_stream.frame_draws.push_back(current);

		if (!g_hud_bootstrapped.load(std::memory_order_acquire) &&
			is_first_hud_anchor(g_stream, current))
		{
			g_hud_bootstrapped.store(true, std::memory_order_release);

			std::ostringstream message;
			message
				<< "ACZRenderBridge: bootstrapped first-HUD fingerprint"
				<< " runtime_pipeline=0x" << std::hex << current.pipeline
				<< " stable=0x" << current.fp.stable
				<< " vs=0x" << current.fp.vs
				<< " ps=0x" << current.fp.ps;
			reshade::log::message(
				reshade::log::level::info,
				message.str().c_str());
		}

		const bool direct_hud_match =
			g_hud_bootstrapped.load(std::memory_order_acquire) &&
			current.indexed &&
			current.count == 89 &&
			is_main_hud_pipeline(current);

		const uint64_t present_serial =
			g_present_serial.load(std::memory_order_acquire);

		if (direct_hud_match &&
			g_stream.last_copied_present != present_serial)
		{
			copy_scene_clean(cmd_list, current);
			g_stream.last_copied_present = present_serial;
			g_stream.miss_dump_budget = 3;
		}

		remember_draw(current);
		return false;
	}

	bool on_draw(
		command_list *cmd_list,
		uint32_t vertex_count,
		uint32_t,
		uint32_t,
		uint32_t)
	{
		return process_draw(cmd_list, false, vertex_count);
	}

	bool on_draw_indexed(
		command_list *cmd_list,
		uint32_t index_count,
		uint32_t,
		uint32_t,
		int32_t,
		uint32_t)
	{
		return process_draw(cmd_list, true, index_count);
	}
}

extern "C" __declspec(dllexport) const char *NAME = "ACZ Render Bridge";
extern "C" __declspec(dllexport) const char *DESCRIPTION =
	"Captures a clean pre-HUD scene texture for ACE COMBAT ZERO.";

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
		if (!reshade::register_addon(module))
			return FALSE;

		reshade::register_event<reshade::addon_event::init_device>(on_init_device);
		reshade::register_event<reshade::addon_event::destroy_device>(on_destroy_device);

		reshade::register_event<reshade::addon_event::init_pipeline>(on_init_pipeline);
		reshade::register_event<reshade::addon_event::destroy_pipeline>(on_destroy_pipeline);
		reshade::register_event<reshade::addon_event::bind_pipeline>(on_bind_pipeline);
		reshade::register_event<reshade::addon_event::bind_pipeline_states>(on_bind_pipeline_states);
		reshade::register_event<reshade::addon_event::bind_render_targets_and_depth_stencil>(on_bind_render_targets);
		reshade::register_event<reshade::addon_event::draw>(on_draw);
		reshade::register_event<reshade::addon_event::draw_indexed>(on_draw_indexed);
		reshade::register_event<reshade::addon_event::present>(on_present);

		reshade::register_event<reshade::addon_event::reshade_begin_effects>(on_reshade_begin_effects);
		reshade::register_event<reshade::addon_event::reshade_reloaded_effects>(update_effect_runtime);

		reshade::log::message(
			reshade::log::level::info,
			"ACZRenderBridge: loaded; pure GPU HUD anchor active.");
		break;

	case DLL_PROCESS_DETACH:
		reshade::unregister_addon(module);
		break;
	}

	return TRUE;
}

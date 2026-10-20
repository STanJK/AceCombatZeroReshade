#include <Windows.h>
#include <reshade.hpp>

#include <atomic>
#include <cstdint>
#include <cstring>
#include <mutex>
#include <optional>
#include <shared_mutex>
#include <sstream>
#include <type_traits>
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

	uint64_t fnv_string(uint64_t hash, const char *value)
	{
		if (value == nullptr)
		{
			const uint32_t length = 0;
			return fnv_value(hash, length);
		}

		const uint32_t length = static_cast<uint32_t>(std::strlen(value));
		hash = fnv_value(hash, length);
		return fnv1a(hash, value, length);
	}

	template <typename Enum>
	uint64_t fnv_enum(uint64_t hash, Enum value)
	{
		using raw_type = std::underlying_type_t<Enum>;
		return fnv_value(hash, static_cast<raw_type>(value));
	}

	uint64_t hash_input_element(uint64_t hash, const input_element &value)
	{
		hash = fnv_value(hash, value.location);
		hash = fnv_string(hash, value.semantic);
		hash = fnv_value(hash, value.semantic_index);
		hash = fnv_enum(hash, value.format);
		hash = fnv_value(hash, value.buffer_binding);
		hash = fnv_value(hash, value.offset);
		hash = fnv_value(hash, value.stride);
		hash = fnv_value(hash, value.instance_step_rate);
		return hash;
	}

	uint64_t hash_blend_desc(uint64_t hash, const blend_desc &value)
	{
		hash = fnv_value(hash, value.alpha_to_coverage_enable);
		for (uint32_t i = 0; i < 8; ++i)
		{
			hash = fnv_value(hash, value.blend_enable[i]);
			hash = fnv_value(hash, value.logic_op_enable[i]);
			hash = fnv_enum(hash, value.source_color_blend_factor[i]);
			hash = fnv_enum(hash, value.dest_color_blend_factor[i]);
			hash = fnv_enum(hash, value.color_blend_op[i]);
			hash = fnv_enum(hash, value.source_alpha_blend_factor[i]);
			hash = fnv_enum(hash, value.dest_alpha_blend_factor[i]);
			hash = fnv_enum(hash, value.alpha_blend_op[i]);
			hash = fnv_enum(hash, value.logic_op[i]);
			hash = fnv_value(hash, value.render_target_write_mask[i]);
		}
		for (float component : value.blend_constant)
			hash = fnv_value(hash, component);
		return hash;
	}

	uint64_t hash_rasterizer_desc(uint64_t hash, const rasterizer_desc &value)
	{
		hash = fnv_enum(hash, value.fill_mode);
		hash = fnv_enum(hash, value.cull_mode);
		hash = fnv_value(hash, value.front_counter_clockwise);
		hash = fnv_value(hash, value.depth_bias);
		hash = fnv_value(hash, value.depth_bias_clamp);
		hash = fnv_value(hash, value.slope_scaled_depth_bias);
		hash = fnv_value(hash, value.depth_clip_enable);
		hash = fnv_value(hash, value.scissor_enable);
		hash = fnv_value(hash, value.multisample_enable);
		hash = fnv_value(hash, value.antialiased_line_enable);
		hash = fnv_value(hash, value.conservative_rasterization);
		return hash;
	}

	uint64_t hash_depth_stencil_desc(uint64_t hash, const depth_stencil_desc &value)
	{
		hash = fnv_value(hash, value.depth_enable);
		hash = fnv_value(hash, value.depth_write_mask);
		hash = fnv_enum(hash, value.depth_func);
		hash = fnv_value(hash, value.stencil_enable);

		hash = fnv_value(hash, value.front_stencil_read_mask);
		hash = fnv_value(hash, value.front_stencil_write_mask);
		hash = fnv_value(hash, value.front_stencil_reference_value);
		hash = fnv_enum(hash, value.front_stencil_func);
		hash = fnv_enum(hash, value.front_stencil_pass_op);
		hash = fnv_enum(hash, value.front_stencil_fail_op);
		hash = fnv_enum(hash, value.front_stencil_depth_fail_op);

		hash = fnv_value(hash, value.back_stencil_read_mask);
		hash = fnv_value(hash, value.back_stencil_write_mask);
		hash = fnv_value(hash, value.back_stencil_reference_value);
		hash = fnv_enum(hash, value.back_stencil_func);
		hash = fnv_enum(hash, value.back_stencil_pass_op);
		hash = fnv_enum(hash, value.back_stencil_fail_op);
		hash = fnv_enum(hash, value.back_stencil_depth_fail_op);
		return hash;
	}

	uint64_t hash_sampler_desc(uint64_t hash, const sampler_desc &value)
	{
		hash = fnv_enum(hash, value.filter);
		hash = fnv_enum(hash, value.address_u);
		hash = fnv_enum(hash, value.address_v);
		hash = fnv_enum(hash, value.address_w);
		hash = fnv_value(hash, value.mip_lod_bias);
		hash = fnv_value(hash, value.max_anisotropy);
		hash = fnv_enum(hash, value.compare_op);
		for (float component : value.border_color)
			hash = fnv_value(hash, component);
		hash = fnv_value(hash, value.min_lod);
		hash = fnv_value(hash, value.max_lod);
		return hash;
	}

	uint64_t hash_constant_range(uint64_t hash, const constant_range &value)
	{
		hash = fnv_value(hash, value.binding);
		hash = fnv_value(hash, value.dx_register_index);
		hash = fnv_value(hash, value.dx_register_space);
		hash = fnv_value(hash, value.count);
		hash = fnv_enum(hash, value.visibility);
		return hash;
	}

	uint64_t hash_descriptor_range(uint64_t hash, const descriptor_range &value)
	{
		hash = fnv_value(hash, value.binding);
		hash = fnv_value(hash, value.dx_register_index);
		hash = fnv_value(hash, value.dx_register_space);
		hash = fnv_value(hash, value.count);
		hash = fnv_enum(hash, value.visibility);
		hash = fnv_value(hash, value.array_size);
		hash = fnv_enum(hash, value.type);
		return hash;
	}

	uint64_t hash_descriptor_range_with_flags(
		uint64_t hash,
		const descriptor_range_with_flags &value)
	{
		hash = hash_descriptor_range(
			hash,
			static_cast<const descriptor_range &>(value));
		hash = fnv_enum(hash, value.flags);

		const bool has_static_samplers = value.static_samplers != nullptr;
		hash = fnv_value(hash, has_static_samplers);

		if (has_static_samplers && value.count != UINT32_MAX)
		{
			for (uint32_t i = 0; i < value.count; ++i)
				hash = hash_sampler_desc(hash, value.static_samplers[i]);
		}

		return hash;
	}

	uint64_t hash_pipeline_layout_param(
		uint64_t hash,
		const pipeline_layout_param &param)
	{
		hash = fnv_enum(hash, param.type);

		switch (param.type)
		{
		case pipeline_layout_param_type::push_constants:
			return hash_constant_range(hash, param.push_constants);

		case pipeline_layout_param_type::push_descriptors:
			return hash_descriptor_range(hash, param.push_descriptors);

		case pipeline_layout_param_type::descriptor_table:
		case pipeline_layout_param_type::push_descriptors_with_ranges:
			hash = fnv_value(hash, param.descriptor_table.count);
			if (param.descriptor_table.ranges != nullptr)
				for (uint32_t i = 0; i < param.descriptor_table.count; ++i)
					hash = hash_descriptor_range(
						hash,
						param.descriptor_table.ranges[i]);
			return hash;

		case pipeline_layout_param_type::descriptor_table_with_flags:
		case pipeline_layout_param_type::push_descriptors_with_ranges_and_flags:
			hash = fnv_value(hash, param.descriptor_table_with_flags.count);
			if (param.descriptor_table_with_flags.ranges != nullptr)
				for (uint32_t i = 0; i < param.descriptor_table_with_flags.count; ++i)
					hash = hash_descriptor_range_with_flags(
						hash,
						param.descriptor_table_with_flags.ranges[i]);
			return hash;

		default:
			return hash;
		}
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
		uint64_t stable = 0;   // Legacy calibration hash.
		uint64_t full_pso = 0; // Normalized root signature + graphics PSO hash.
		uint64_t layout_hash = 0;
		uint64_t layout_handle = 0; // Diagnostic only; never hashed.

		uint64_t vs = 0;
		uint64_t hs = 0;
		uint64_t ds = 0;
		uint64_t gs = 0;
		uint64_t ps = 0;
		uint64_t as = 0;
		uint64_t ms = 0;

		uint32_t static_topology = 0;
		uint32_t rt_count = 0;
		uint32_t rt0_format = 0;
		uint32_t ds_format = 0;
		uint32_t sample_count = 0;
		uint32_t sample_mask = 0;
	};

	std::unordered_map<uint64_t, uint64_t> g_pipeline_layouts;
	std::shared_mutex g_pipeline_layout_mutex;

	uint64_t lookup_pipeline_layout(uint64_t handle)
	{
		std::shared_lock lock(g_pipeline_layout_mutex);
		const auto it = g_pipeline_layouts.find(handle);
		return it != g_pipeline_layouts.end() ? it->second : 0;
	}

	void on_init_pipeline_layout(
		device *,
		uint32_t param_count,
		const pipeline_layout_param *params,
		pipeline_layout layout)
	{
		uint64_t hash = fnv_offset;
		hash = fnv_value(hash, param_count);

		if (params != nullptr)
			for (uint32_t i = 0; i < param_count; ++i)
				hash = hash_pipeline_layout_param(hash, params[i]);

		std::unique_lock lock(g_pipeline_layout_mutex);
		g_pipeline_layouts[layout.handle] = hash;
	}

	void on_destroy_pipeline_layout(device *, pipeline_layout layout)
	{
		std::unique_lock lock(g_pipeline_layout_mutex);
		g_pipeline_layouts.erase(layout.handle);
	}

	std::unordered_map<uint64_t, pipeline_fingerprint> g_pipelines;
	std::shared_mutex g_pipeline_mutex;

	std::atomic<uint64_t> g_present_serial { 0 };
	std::atomic_bool g_hud_bootstrapped { false };
	std::atomic<uint64_t> g_bootstrap_full_pso { 0 };

	void on_init_pipeline(
		device *,
		pipeline_layout layout,
		uint32_t subobject_count,
		const pipeline_subobject *subobjects,
		pipeline pipeline)
	{
		pipeline_fingerprint fp;
		fp.layout_handle = layout.handle;
		fp.layout_hash = lookup_pipeline_layout(layout.handle);

		uint64_t stable = fnv_offset;
		uint64_t full = fnv_offset;
		full = fnv_value(full, fp.layout_hash);

		for (uint32_t i = 0; i < subobject_count; ++i)
		{
			const pipeline_subobject &sub = subobjects[i];

			// Preserve the legacy calibration hash exactly for compatibility.
			stable = fnv_value(stable, sub.type);
			stable = fnv_value(stable, sub.count);

			// Full PSO hash uses explicit scalar values only: no pointers or
			// structure padding are hashed.
			full = fnv_enum(full, sub.type);
			full = fnv_value(full, sub.count);

			switch (sub.type)
			{
			case pipeline_subobject_type::vertex_shader:
			case pipeline_subobject_type::hull_shader:
			case pipeline_subobject_type::domain_shader:
			case pipeline_subobject_type::geometry_shader:
			case pipeline_subobject_type::pixel_shader:
			case pipeline_subobject_type::amplification_shader:
			case pipeline_subobject_type::mesh_shader:
			{
				const auto *shaders =
					static_cast<const shader_desc *>(sub.data);

				if (shaders == nullptr)
					break;

				for (uint32_t n = 0; n < sub.count; ++n)
				{
					const uint64_t shader_hash = hash_shader(shaders[n]);
					stable = fnv_value(stable, shader_hash);
					full = fnv_value(full, shader_hash);

					if (n != 0)
						continue;

					switch (sub.type)
					{
					case pipeline_subobject_type::vertex_shader: fp.vs = shader_hash; break;
					case pipeline_subobject_type::hull_shader: fp.hs = shader_hash; break;
					case pipeline_subobject_type::domain_shader: fp.ds = shader_hash; break;
					case pipeline_subobject_type::geometry_shader: fp.gs = shader_hash; break;
					case pipeline_subobject_type::pixel_shader: fp.ps = shader_hash; break;
					case pipeline_subobject_type::amplification_shader: fp.as = shader_hash; break;
					case pipeline_subobject_type::mesh_shader: fp.ms = shader_hash; break;
					default: break;
					}
				}
				break;
			}

			case pipeline_subobject_type::input_layout:
			{
				const auto *values =
					static_cast<const input_element *>(sub.data);
				if (values != nullptr)
					for (uint32_t n = 0; n < sub.count; ++n)
						full = hash_input_element(full, values[n]);
				break;
			}

			case pipeline_subobject_type::stream_output_state:
			{
				const auto *values =
					static_cast<const stream_output_desc *>(sub.data);
				if (values != nullptr)
					for (uint32_t n = 0; n < sub.count; ++n)
						full = fnv_value(full, values[n].rasterized_stream);
				break;
			}

			case pipeline_subobject_type::blend_state:
			{
				const auto *values =
					static_cast<const blend_desc *>(sub.data);
				if (values != nullptr)
					for (uint32_t n = 0; n < sub.count; ++n)
						full = hash_blend_desc(full, values[n]);
				break;
			}

			case pipeline_subobject_type::rasterizer_state:
			{
				const auto *values =
					static_cast<const rasterizer_desc *>(sub.data);
				if (values != nullptr)
					for (uint32_t n = 0; n < sub.count; ++n)
						full = hash_rasterizer_desc(full, values[n]);
				break;
			}

			case pipeline_subobject_type::depth_stencil_state:
			{
				const auto *values =
					static_cast<const depth_stencil_desc *>(sub.data);
				if (values != nullptr)
					for (uint32_t n = 0; n < sub.count; ++n)
						full = hash_depth_stencil_desc(full, values[n]);
				break;
			}

			case pipeline_subobject_type::primitive_topology:
			{
				const auto *values =
					static_cast<const primitive_topology *>(sub.data);
				if (values != nullptr)
				{
					if (sub.count != 0)
						fp.static_topology = static_cast<uint32_t>(values[0]);

					for (uint32_t n = 0; n < sub.count; ++n)
					{
						const uint32_t value =
							static_cast<uint32_t>(values[n]);
						stable = fnv_value(stable, value);
						full = fnv_value(full, value);
					}
				}
				break;
			}

			case pipeline_subobject_type::depth_stencil_format:
			{
				const auto *values = static_cast<const format *>(sub.data);
				if (values != nullptr)
					for (uint32_t n = 0; n < sub.count; ++n)
					{
						const uint32_t value =
							static_cast<uint32_t>(values[n]);
						if (n == 0)
							fp.ds_format = value;
						stable = fnv_value(stable, value);
						full = fnv_value(full, value);
					}
				break;
			}

			case pipeline_subobject_type::render_target_formats:
			{
				const auto *values = static_cast<const format *>(sub.data);
				fp.rt_count = sub.count;
				if (values != nullptr)
					for (uint32_t n = 0; n < sub.count; ++n)
					{
						const uint32_t value =
							static_cast<uint32_t>(values[n]);
						if (n == 0)
							fp.rt0_format = value;
						stable = fnv_value(stable, value);
						full = fnv_value(full, value);
					}
				break;
			}

			case pipeline_subobject_type::sample_mask:
			{
				const auto *values =
					static_cast<const uint32_t *>(sub.data);
				if (values != nullptr)
					for (uint32_t n = 0; n < sub.count; ++n)
					{
						if (n == 0)
							fp.sample_mask = values[n];
						full = fnv_value(full, values[n]);
					}
				break;
			}

			case pipeline_subobject_type::sample_count:
			{
				const auto *values =
					static_cast<const uint32_t *>(sub.data);
				if (values != nullptr)
					for (uint32_t n = 0; n < sub.count; ++n)
					{
						if (n == 0)
							fp.sample_count = values[n];
						stable = fnv_value(stable, values[n]);
						full = fnv_value(full, values[n]);
					}
				break;
			}

			case pipeline_subobject_type::viewport_count:
			case pipeline_subobject_type::max_vertex_count:
			{
				const auto *values =
					static_cast<const uint32_t *>(sub.data);
				if (values != nullptr)
					for (uint32_t n = 0; n < sub.count; ++n)
						full = fnv_value(full, values[n]);
				break;
			}

			case pipeline_subobject_type::dynamic_pipeline_states:
			{
				const auto *values =
					static_cast<const dynamic_state *>(sub.data);
				if (values != nullptr)
					for (uint32_t n = 0; n < sub.count; ++n)
						full = fnv_enum(full, values[n]);
				break;
			}

			case pipeline_subobject_type::flags:
			{
				const auto *values =
					static_cast<const pipeline_flags *>(sub.data);
				if (values != nullptr)
					for (uint32_t n = 0; n < sub.count; ++n)
						full = fnv_enum(full, values[n]);
				break;
			}

			default:
				break;
			}
		}

		fp.stable = stable;
		fp.full_pso = full;

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

	struct __declspec(uuid("6bc7483f-d102-4acd-96d3-6f247f6b298e")) bridge_runtime_data
	{
		uint64_t last_seen_copies = 0;
		bool technique_gate_active = false;
		std::vector<effect_technique> gated_techniques;
	};

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
			transfer_usage |
				resource_usage::shader_resource |
				resource_usage::copy_source,
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

	bool is_hud_boundary_pair(
		const bridge_stream_state &state,
		const draw_record &current)
	{
		if (!state.prev1)
			return false;

		const draw_record &prev = *state.prev1;

		return
			!prev.indexed && prev.count == 4 &&
			current.indexed && current.count == 89 &&
			is_main_hud_pipeline(prev) &&
			is_main_hud_pipeline(current) &&
			same_main_target(prev, current);
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
				<< "ACZRenderBridge: SceneClean copied at first latched-HUD PSO draw"
				<< " copies=" << data.copies
				<< " ordinal=" << anchor.ordinal
				<< " full_pso=0x" << std::hex << anchor.fp.full_pso
				<< " pipeline=0x" << anchor.pipeline
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

	void on_init_effect_runtime(effect_runtime *runtime)
	{
		runtime->create_private_data<bridge_runtime_data>();
	}

	void on_destroy_effect_runtime(effect_runtime *runtime)
	{
		runtime->destroy_private_data<bridge_runtime_data>();
	}

	bool update_effect_runtime(effect_runtime *runtime)
	{
		device *device = runtime->get_device();
		if (device == nullptr)
			return false;

		auto *data = device->get_private_data<bridge_device_data>();
		auto *runtime_data = runtime->get_private_data<bridge_runtime_data>();
		if (data == nullptr || runtime_data == nullptr)
			return false;

		std::lock_guard lock(data->mutex);

		const bool fresh =
			data->scene_shader_ready &&
			data->scene_clean_srv != 0 &&
			data->copies != runtime_data->last_seen_copies;

		const resource_view srv =
			data->scene_clean_srv != 0
				? data->scene_clean_srv
				: resource_view { 0 };

		runtime->update_texture_bindings(
			"ACZ_SCENE_CLEAN",
			srv,
			srv);

		runtime->enumerate_uniform_variables(
			nullptr,
			[fresh](effect_runtime *rt, effect_uniform_variable variable)
			{
				char source[64] = {};
				if (rt->get_annotation_string_from_uniform_variable(
						variable,
						"source",
						source) &&
					std::strcmp(source, "acz_scene_clean_fresh") == 0)
				{
					rt->set_uniform_value_bool(variable, fresh);
				}
			});

		runtime_data->last_seen_copies = data->copies;
		return fresh;
	}


	void apply_technique_gate(
		effect_runtime *runtime,
		bool scene_clean_fresh)
	{
		auto *runtime_data =
			runtime->get_private_data<bridge_runtime_data>();
		if (runtime_data == nullptr)
			return;

		if (!scene_clean_fresh)
		{
			if (runtime_data->technique_gate_active)
				return;

			runtime_data->gated_techniques.clear();

			runtime->enumerate_techniques(
				nullptr,
				[runtime_data](
					effect_runtime *rt,
					effect_technique technique)
				{
					if (!rt->get_technique_state(technique))
						return;

					runtime_data->gated_techniques.push_back(technique);
					rt->set_technique_state(technique, false);
				});

			runtime_data->technique_gate_active = true;

			std::ostringstream message;
			message
				<< "ACZRenderBridge: effect gate OFF; no fresh SceneClean"
				<< " techniques=" << runtime_data->gated_techniques.size();
			reshade::log::message(
				reshade::log::level::info,
				message.str().c_str());
			return;
		}

		if (!runtime_data->technique_gate_active)
			return;

		for (effect_technique technique :
			 runtime_data->gated_techniques)
		{
			if (technique != 0)
				runtime->set_technique_state(technique, true);
		}

		const size_t restored =
			runtime_data->gated_techniques.size();

		runtime_data->gated_techniques.clear();
		runtime_data->technique_gate_active = false;

		std::ostringstream message;
		message
			<< "ACZRenderBridge: effect gate ON; fresh SceneClean"
			<< " restored=" << restored;
		reshade::log::message(
			reshade::log::level::info,
			message.str().c_str());
	}

	void on_reshade_begin_effects(
		effect_runtime *runtime,
		command_list *,
		resource_view,
		resource_view)
	{
		// Publish SceneClean and obtain this frame's freshness before the
		// technique list is rendered.
		const bool fresh = update_effect_runtime(runtime);

		// Keep ReShade's global effects state enabled so this callback
		// continues to run every frame. Only gate individual techniques.
		apply_technique_gate(runtime, fresh);
	}

	void on_reshade_reloaded_effects(
		effect_runtime *runtime)
	{
		auto *runtime_data =
			runtime->get_private_data<bridge_runtime_data>();
		if (runtime_data != nullptr)
		{
			runtime_data->gated_techniques.clear();
			runtime_data->technique_gate_active = false;
		}

		const bool fresh = update_effect_runtime(runtime);
		apply_technique_gate(runtime, fresh);
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
				<< " full_pso=0x" << d.fp.full_pso
				<< " layout_hash=0x" << d.fp.layout_hash
				<< " layout=0x" << d.fp.layout_handle
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
			g_bootstrap_full_pso.store(
				current.fp.full_pso,
				std::memory_order_release);
			g_hud_bootstrapped.store(true, std::memory_order_release);

			std::ostringstream message;
			message
				<< "ACZRenderBridge: bootstrapped first-HUD fingerprint"
				<< " runtime_pipeline=0x" << std::hex << current.pipeline
				<< " stable=0x" << current.fp.stable
				<< " full_pso=0x" << current.fp.full_pso
				<< " layout_hash=0x" << current.fp.layout_hash
				<< " layout=0x" << current.fp.layout_handle
				<< " vs=0x" << current.fp.vs
				<< " ps=0x" << current.fp.ps;
			reshade::log::message(
				reshade::log::level::info,
				message.str().c_str());
		}

		const uint64_t latched_full_pso =
			g_bootstrap_full_pso.load(std::memory_order_acquire);

		const bool direct_hud_match =
			g_hud_bootstrapped.load(std::memory_order_acquire) &&
			latched_full_pso != 0 &&
			current.fp.full_pso == latched_full_pso &&
			current.topology == 0x5 &&
			current.rtv0 != 0 &&
			current.dsv != 0;

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
	"Captures a clean pre-HUD scene and exposes it to ReShade effects for ACE COMBAT ZERO.";

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
		if (!reshade::register_addon(module))
			return FALSE;

		reshade::register_event<reshade::addon_event::init_device>(on_init_device);
		reshade::register_event<reshade::addon_event::destroy_device>(on_destroy_device);

		reshade::register_event<reshade::addon_event::init_pipeline_layout>(on_init_pipeline_layout);
		reshade::register_event<reshade::addon_event::destroy_pipeline_layout>(on_destroy_pipeline_layout);
		reshade::register_event<reshade::addon_event::init_pipeline>(on_init_pipeline);
		reshade::register_event<reshade::addon_event::destroy_pipeline>(on_destroy_pipeline);
		reshade::register_event<reshade::addon_event::bind_pipeline>(on_bind_pipeline);
		reshade::register_event<reshade::addon_event::bind_pipeline_states>(on_bind_pipeline_states);
		reshade::register_event<reshade::addon_event::bind_render_targets_and_depth_stencil>(on_bind_render_targets);
		reshade::register_event<reshade::addon_event::draw>(on_draw);
		reshade::register_event<reshade::addon_event::draw_indexed>(on_draw_indexed);
		reshade::register_event<reshade::addon_event::present>(on_present);

		reshade::register_event<reshade::addon_event::init_effect_runtime>(on_init_effect_runtime);
		reshade::register_event<reshade::addon_event::destroy_effect_runtime>(on_destroy_effect_runtime);
		reshade::register_event<reshade::addon_event::reshade_begin_effects>(on_reshade_begin_effects);
		reshade::register_event<reshade::addon_event::reshade_reloaded_effects>(on_reshade_reloaded_effects);

		reshade::log::message(
			reshade::log::level::info,
			"ACZRenderBridge: loaded; bootstrap anchor + normalized full-PSO HUD matcher active.");
		break;

	case DLL_PROCESS_DETACH:
		reshade::unregister_addon(module);
		break;
	}

	return TRUE;
}

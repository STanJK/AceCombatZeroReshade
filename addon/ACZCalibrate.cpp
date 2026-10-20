#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>
#include <TlHelp32.h>

#include <reshade.hpp>

#include <atomic>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <mutex>
#include <optional>
#include <shared_mutex>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

namespace
{
	using namespace reshade;

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

	uint64_t hash_shader(const api::shader_desc &shader)
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
		uint64_t gs = 0;
		uint32_t static_topology = 0;
		uint32_t rt_count = 0;
		uint32_t rt0_format = 0;
		uint32_t ds_format = 0;
		uint32_t sample_count = 0;
	};

	std::unordered_map<uint64_t, pipeline_fingerprint> g_pipelines;
	std::shared_mutex g_pipeline_mutex;

	void on_init_pipeline(
		api::device *,
		api::pipeline_layout,
		uint32_t subobject_count,
		const api::pipeline_subobject *subobjects,
		api::pipeline pipeline)
	{
		pipeline_fingerprint fp;
		uint64_t stable = fnv_offset;

		for (uint32_t i = 0; i < subobject_count; ++i)
		{
			const auto &sub = subobjects[i];
			stable = fnv_value(stable, sub.type);
			stable = fnv_value(stable, sub.count);

			switch (sub.type)
			{
			case api::pipeline_subobject_type::vertex_shader:
			case api::pipeline_subobject_type::geometry_shader:
			case api::pipeline_subobject_type::pixel_shader:
			{
				const auto *shaders = static_cast<const api::shader_desc *>(sub.data);
				for (uint32_t n = 0; n < sub.count; ++n)
				{
					const uint64_t shader_hash = hash_shader(shaders[n]);
					stable = fnv_value(stable, shader_hash);
					if (n == 0)
					{
						if (sub.type == api::pipeline_subobject_type::vertex_shader)
							fp.vs = shader_hash;
						else if (sub.type == api::pipeline_subobject_type::geometry_shader)
							fp.gs = shader_hash;
						else
							fp.ps = shader_hash;
					}
				}
				break;
			}
			case api::pipeline_subobject_type::primitive_topology:
				if (sub.count != 0 && sub.data != nullptr)
				{
					const auto *values = static_cast<const api::primitive_topology *>(sub.data);
					fp.static_topology = static_cast<uint32_t>(values[0]);
					for (uint32_t n = 0; n < sub.count; ++n)
					{
						const uint32_t value = static_cast<uint32_t>(values[n]);
						stable = fnv_value(stable, value);
					}
				}
				break;
			case api::pipeline_subobject_type::render_target_formats:
				if (sub.data != nullptr)
				{
					const auto *values = static_cast<const api::format *>(sub.data);
					fp.rt_count = sub.count;
					if (sub.count != 0)
						fp.rt0_format = static_cast<uint32_t>(values[0]);
					for (uint32_t n = 0; n < sub.count; ++n)
					{
						const uint32_t value = static_cast<uint32_t>(values[n]);
						stable = fnv_value(stable, value);
					}
				}
				break;
			case api::pipeline_subobject_type::depth_stencil_format:
				if (sub.count != 0 && sub.data != nullptr)
				{
					fp.ds_format = static_cast<uint32_t>(*static_cast<const api::format *>(sub.data));
					stable = fnv_value(stable, fp.ds_format);
				}
				break;
			case api::pipeline_subobject_type::sample_count:
				if (sub.count != 0 && sub.data != nullptr)
				{
					fp.sample_count = *static_cast<const uint32_t *>(sub.data);
					stable = fnv_value(stable, fp.sample_count);
				}
				break;
			default:
				break;
			}
		}

		fp.stable = stable;

		std::unique_lock lock(g_pipeline_mutex);
		g_pipelines[pipeline.handle] = fp;
	}

	void on_destroy_pipeline(api::device *, api::pipeline pipeline)
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

	using oracle_scope_fn = uint32_t(WINAPI *)();
	std::atomic<oracle_scope_fn> g_oracle_scope { nullptr };
	std::atomic_bool g_oracle_announced { false };

	bool try_resolve_oracle()
	{
		if (g_oracle_scope.load(std::memory_order_acquire) != nullptr)
			return true;

		const HANDLE snapshot = CreateToolhelp32Snapshot(
			TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32,
			GetCurrentProcessId());
		if (snapshot == INVALID_HANDLE_VALUE)
			return false;

		MODULEENTRY32W entry = {};
		entry.dwSize = sizeof(entry);
		bool found = false;

		if (Module32FirstW(snapshot, &entry))
		{
			do
			{
				if (const auto proc = GetProcAddress(entry.hModule, "ACZOracleScopeFlags"))
				{
					g_oracle_scope.store(reinterpret_cast<oracle_scope_fn>(proc), std::memory_order_release);
					found = true;
					break;
				}
			}
			while (Module32NextW(snapshot, &entry));
		}

		CloseHandle(snapshot);

		if (found && !g_oracle_announced.exchange(true))
			reshade::log::message(reshade::log::level::info, "ACZCalibrate: connected to ACZ semantic oracle.");

		return found;
	}

	uint32_t oracle_scope_flags()
	{
		const auto fn = g_oracle_scope.load(std::memory_order_acquire);
		return fn != nullptr ? fn() : 0;
	}

	struct draw_record
	{
		bool indexed = false;
		uint64_t ordinal = 0;
		uint64_t pipeline = 0;
		pipeline_fingerprint fp = {};
		uint32_t topology = 0;
		uint64_t rtv0 = 0;
		uint64_t dsv = 0;
		int64_t args[5] = {};
	};

	struct thread_state
	{
		uint64_t pipeline = 0;
		uint32_t topology = 0;
		uint64_t rtv0 = 0;
		uint64_t dsv = 0;

		bool capture_active = false;
		bool first_hud_seen = false;
		uint64_t draw_ordinal = 0;
		std::optional<draw_record> last_draw;
	};

	thread_local thread_state g_tls;

	struct pending_capture
	{
		uint64_t id = 0;
		std::optional<draw_record> pre_hud;
		std::vector<draw_record> hud;
	};

	std::mutex g_pending_mutex;
	pending_capture g_pending;
	std::atomic<uint64_t> g_next_capture_id { 0 };
	std::atomic_bool g_capture_observed { false };
	std::atomic<uint64_t> g_raw_capture_draws { 0 };
	std::atomic<uint64_t> g_present_count { 0 };

	void on_bind_pipeline(api::command_list *, api::pipeline_stage, api::pipeline pipeline)
	{
		g_tls.pipeline = pipeline.handle;
	}

	void on_bind_pipeline_states(
		api::command_list *,
		uint32_t count,
		const api::dynamic_state *states,
		const uint32_t *values)
	{
		for (uint32_t i = 0; i < count; ++i)
			if (states[i] == api::dynamic_state::primitive_topology)
				g_tls.topology = values[i];
	}

	void on_bind_render_targets(
		api::command_list *,
		uint32_t count,
		const api::resource_view *rtvs,
		api::resource_view dsv)
	{
		g_tls.rtv0 = (count != 0 && rtvs != nullptr) ? rtvs[0].handle : 0;
		g_tls.dsv = dsv.handle;
	}

	void begin_capture_if_needed()
	{
		if (g_tls.capture_active)
			return;

		g_tls.capture_active = true;
		g_capture_observed.store(true, std::memory_order_release);
		g_tls.first_hud_seen = false;
		g_tls.draw_ordinal = 0;
		g_tls.last_draw.reset();

		std::lock_guard lock(g_pending_mutex);
		g_pending = {};
		g_pending.id = g_next_capture_id.fetch_add(1, std::memory_order_relaxed) + 1;
	}

	draw_record make_record(bool indexed, const int64_t (&args)[5])
	{
		draw_record record;
		record.indexed = indexed;
		record.ordinal = g_tls.draw_ordinal;
		record.pipeline = g_tls.pipeline;
		record.fp = lookup_pipeline(g_tls.pipeline);
		record.topology = g_tls.topology != 0 ? g_tls.topology : record.fp.static_topology;
		record.rtv0 = g_tls.rtv0;
		record.dsv = g_tls.dsv;
		for (size_t i = 0; i < 5; ++i)
			record.args[i] = args[i];
		return record;
	}

	void observe_draw(const draw_record &record, uint32_t scope)
	{
		const bool capture = (scope & 1u) != 0;
		if (!capture)
		{
			g_tls.capture_active = false;
			return;
		}

		begin_capture_if_needed();

		const bool hud = (scope & 0x7u) == 0x7u;
		if (hud)
		{
			std::lock_guard lock(g_pending_mutex);
			if (!g_tls.first_hud_seen)
			{
				g_pending.pre_hud = g_tls.last_draw;
				g_tls.first_hud_seen = true;
			}
			g_pending.hud.push_back(record);
		}

		g_tls.last_draw = record;
		++g_tls.draw_ordinal;
	}

	void console_draw(const char *kind, uint32_t scope, const draw_record &record)
	{
		std::ostringstream s;
		s
			<< "RAW " << kind
			<< " scope=0x" << std::hex << scope
			<< " ordinal=" << std::dec << record.ordinal
			<< " pipeline=0x" << std::hex << record.pipeline
			<< " stable=0x" << record.fp.stable
			<< " vs=0x" << record.fp.vs
			<< " ps=0x" << record.fp.ps
			<< " topology=0x" << record.topology
			<< " rtv0=0x" << record.rtv0
			<< " dsv=0x" << record.dsv
			<< std::dec
			<< " args=["
			<< record.args[0] << ','
			<< record.args[1] << ','
			<< record.args[2] << ','
			<< record.args[3] << ','
			<< record.args[4] << ']';
		reshade::log::message(reshade::log::level::info, s.str().c_str());
	}

	void ensure_calibration_log()
	{
		static std::once_flag once;
		std::call_once(once, [] {
			std::ofstream out(log_path(), std::ios::trunc);
			if (out)
			{
				out << "ACZCalibrate ReShade 6.8.0 / API 20\n";
				out << "[status] add-on connected; waiting for oracle capture\n";
				out.flush();
				reshade::log::message(
					reshade::log::level::info,
					"ACZCalibrate: created D:\\Games\\ACZero\\ACZCalibrate.log.");
			}
			else
			{
				reshade::log::message(
					reshade::log::level::error,
					"ACZCalibrate: FAILED to create ACZCalibrate.log.");
			}
		});
	}

	bool on_draw(
		api::command_list *,
		uint32_t vertex_count,
		uint32_t instance_count,
		uint32_t first_vertex,
		uint32_t first_instance)
	{
		const uint32_t scope = oracle_scope_flags();
		if ((scope & 1u) == 0)
		{
			g_tls.capture_active = false;
			return false;
		}

		const int64_t args[5] = {
			vertex_count,
			instance_count,
			first_vertex,
			first_instance,
			0
		};
		const draw_record record = make_record(false, args);
		g_raw_capture_draws.fetch_add(1, std::memory_order_relaxed);
		console_draw("DRAW", scope, record);
		observe_draw(record, scope);
		return false;
	}

	bool on_draw_indexed(
		api::command_list *,
		uint32_t index_count,
		uint32_t instance_count,
		uint32_t first_index,
		int32_t vertex_offset,
		uint32_t first_instance)
	{
		const uint32_t scope = oracle_scope_flags();
		if ((scope & 1u) == 0)
		{
			g_tls.capture_active = false;
			return false;
		}

		const int64_t args[5] = {
			index_count,
			instance_count,
			first_index,
			vertex_offset,
			first_instance
		};
		const draw_record record = make_record(true, args);
		g_raw_capture_draws.fetch_add(1, std::memory_order_relaxed);
		console_draw("DRAW_INDEXED", scope, record);
		observe_draw(record, scope);
		return false;
	}

	std::wstring log_path()
	{
		wchar_t path[MAX_PATH] = {};
		const DWORD length = GetModuleFileNameW(nullptr, path, ARRAYSIZE(path));
		std::wstring result(path, length);
		const size_t slash = result.find_last_of(L"\\/");
		if (slash != std::wstring::npos)
			result.resize(slash + 1);
		else
			result.clear();
		result += L"ACZCalibrate.log";
		return result;
	}

	void write_draw(std::ofstream &out, const char *tag, const draw_record &d)
	{
		out
			<< tag
			<< " ordinal=" << d.ordinal
			<< " indexed=" << (d.indexed ? 1 : 0)
			<< " pipeline=0x" << std::hex << d.pipeline
			<< " stable=0x" << d.fp.stable
			<< " vs=0x" << d.fp.vs
			<< " ps=0x" << d.fp.ps
			<< " gs=0x" << d.fp.gs
			<< " topology=0x" << d.topology
			<< " rtv0=0x" << d.rtv0
			<< " dsv=0x" << d.dsv
			<< std::dec
			<< " args=["
			<< d.args[0] << ','
			<< d.args[1] << ','
			<< d.args[2] << ','
			<< d.args[3] << ','
			<< d.args[4] << "]\n";
	}

	void flush_capture()
	{
		pending_capture capture;
		{
			std::lock_guard lock(g_pending_mutex);
			if (g_pending.id == 0)
				return;
			capture = std::move(g_pending);
			g_pending = {};
		}

		static std::once_flag truncate_once;
		std::call_once(truncate_once, [] {
			std::ofstream clear(log_path(), std::ios::trunc);
			clear << "ACZCalibrate ReShade 6.8.0 / API 20\n";
		});

		std::ofstream out(log_path(), std::ios::app);
		out << "[capture] id=" << capture.id << " hud_draws=" << capture.hud.size() << '\n';

		if (capture.pre_hud)
			write_draw(out, "[PRE-HUD]", *capture.pre_hud);
		else
			out << "[PRE-HUD] unavailable\n";

		for (size_t i = 0; i < capture.hud.size(); ++i)
		{
			std::ostringstream tag;
			tag << (i == 0 ? "[FIRST-HUD #" : "[HUD #") << i << ']';
			write_draw(out, tag.str().c_str(), capture.hud[i]);
		}

		out << "[capture] end\n";
		out.flush();

		std::ostringstream msg;
		msg << "ACZCalibrate: capture " << capture.id << " wrote "
			<< capture.hud.size() << " HUD GPU draws to ACZCalibrate.log.";
		reshade::log::message(reshade::log::level::info, msg.str().c_str());
	}

	void on_reshade_present(api::effect_runtime *)
	{
		const bool connected = try_resolve_oracle();
		if (connected)
			ensure_calibration_log();

		const uint32_t scope = oracle_scope_flags();
		const uint64_t present = g_present_count.fetch_add(1, std::memory_order_relaxed) + 1;
		const bool observed = g_capture_observed.load(std::memory_order_acquire);

		if (scope != 0 || observed)
		{
			std::ostringstream s;
			s << "PRESENT #" << present
			  << " scope=0x" << std::hex << scope
			  << " observed=" << std::dec << (observed ? 1 : 0)
			  << " raw_capture_draws=" << g_raw_capture_draws.load(std::memory_order_relaxed);
			reshade::log::message(reshade::log::level::info, s.str().c_str());
		}

		if ((scope & 1u) == 0 &&
			g_capture_observed.exchange(false, std::memory_order_acq_rel))
		{
			reshade::log::message(reshade::log::level::info, "FLUSH capture after oracle capture bit dropped.");
			flush_capture();
			g_raw_capture_draws.store(0, std::memory_order_relaxed);
		}
	}
}

extern "C" __declspec(dllexport) const char *NAME = "ACZ Calibrate";
extern "C" __declspec(dllexport) const char *DESCRIPTION =
	"Correlates ACE COMBAT ZERO semantic HUD scope with ReShade GPU draw events.";

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
		if (!reshade::register_addon(module))
			return FALSE;

		reshade::register_event<reshade::addon_event::init_pipeline>(on_init_pipeline);
		reshade::register_event<reshade::addon_event::destroy_pipeline>(on_destroy_pipeline);
		reshade::register_event<reshade::addon_event::bind_pipeline>(on_bind_pipeline);
		reshade::register_event<reshade::addon_event::bind_pipeline_states>(on_bind_pipeline_states);
		reshade::register_event<reshade::addon_event::bind_render_targets_and_depth_stencil>(on_bind_render_targets);
		reshade::register_event<reshade::addon_event::draw>(on_draw);
		reshade::register_event<reshade::addon_event::draw_indexed>(on_draw_indexed);
		reshade::register_event<reshade::addon_event::reshade_present>(on_reshade_present);
		break;

	case DLL_PROCESS_DETACH:
		reshade::unregister_addon(module);
		break;
	}

	return TRUE;
}

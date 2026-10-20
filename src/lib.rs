#![allow(non_snake_case)]
#![allow(clippy::missing_safety_doc)]

use minhook_sys::{MH_CreateHook, MH_DisableHook, MH_EnableHook, MH_Initialize, MH_OK};
use sha2::{Digest, Sha256};
use std::{
    cell::{Cell, RefCell},
    collections::HashMap,
    ffi::{c_void, CStr},
    fmt,
    fs::{File, OpenOptions},
    io::{Read, Write},
    mem,
    path::PathBuf,
    ptr::{null, null_mut},
    slice,
    sync::{
        atomic::{AtomicBool, AtomicU64, AtomicUsize, Ordering},
        Mutex, OnceLock,
    },
};
use windows_sys::Win32::{
    Foundation::{CloseHandle, HINSTANCE},
    System::{
        LibraryLoader::{GetModuleHandleW, GetProcAddress, LoadLibraryW},
        Threading::{CreateThread, Sleep},
    },
    UI::Input::KeyboardAndMouse::GetAsyncKeyState,
};

const DLL_PROCESS_ATTACH: u32 = 1;
const VK_ADD: i32 = 0x6B;

// Verified 2026 ACZ Windows build.
// IDA image base was 0x140000000. Store RVAs only.
const RVA_HUD_EMITTER: usize = 0x00AE510;
const RVA_DISPLAY_LIST_PARSER: usize = 0x018F920;
const RVA_PACKET_INTERPRETER: usize = 0x019D160;
const RVA_BATCH_FLUSH: usize = 0x019CBF0;
const RVA_LEGACY_BATCH_RENDER: usize = 0x0194840;
const RVA_MODERN_DRAW_BUILDER: usize = 0x020F8E0;
const RVA_D3D12_DRAW_HELPER: usize = 0x020F680;
const RVA_FRAME_END: usize = 0x020C280;
const RVA_DEVICE_RESOURCES_GLOBAL: usize = 0x033DA48;

const EXPECTED_SHA256: &str =
    "43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664";

const MAX_HUD_SPANS: usize = 32;
const MAX_HUD_DRAWS_TO_LOG: u64 = 128;

// D3D12 vtable indices for ID3D12GraphicsCommandList.
const GCL_DRAW_INSTANCED: usize = 12;
const GCL_DRAW_INDEXED_INSTANCED: usize = 13;
const GCL_IA_SET_PRIMITIVE_TOPOLOGY: usize = 20;
const GCL_SET_PIPELINE_STATE: usize = 25;
const GCL_OM_SET_RENDER_TARGETS: usize = 46;

// D3D12 vtable index for ID3D12Device::CreateGraphicsPipelineState.

static IMAGE_BASE: AtomicUsize = AtomicUsize::new(0);
static OWN_MODULE: AtomicUsize = AtomicUsize::new(0);
static COMPLETED_FRAME: AtomicU64 = AtomicU64::new(0);
static CAPTURE_TARGET_FRAME: AtomicU64 = AtomicU64::new(0);
static CAPTURE_REQUESTED: AtomicBool = AtomicBool::new(false);
static HUD_DRAW_COUNT: AtomicU64 = AtomicU64::new(0);
static FIRST_HUD_DRAW_SEEN: AtomicBool = AtomicBool::new(false);
static HUD_BUILDER_DEPTH_GLOBAL: AtomicUsize = AtomicUsize::new(0);

#[derive(Clone, Copy, Debug)]
struct Span {
    begin: usize,
    end: usize,
}
static HUD_SPANS: OnceLock<Mutex<Vec<Span>>> = OnceLock::new();

#[derive(Clone, Debug)]
struct PsoFingerprint {
    vs_sha256: String,
    ps_sha256: String,
    root_signature: usize,
}
static PSO_FINGERPRINTS: OnceLock<Mutex<HashMap<usize, PsoFingerprint>>> = OnceLock::new();
static CAPTURE_HOOK_TARGETS: OnceLock<Mutex<Vec<usize>>> = OnceLock::new();

#[derive(Clone, Copy, Debug, Default)]
struct DrawSnapshot {
    indexed: bool,
    pso: usize,
    topology: u32,
    rtv0: usize,
    dsv: usize,
    a: [i64; 5],
}

thread_local! {
    static HUD_PARSE_DEPTH: Cell<u32> = const { Cell::new(0) };
    static CURRENT_PSO: Cell<usize> = const { Cell::new(0) };
    static CURRENT_TOPOLOGY: Cell<u32> = const { Cell::new(0) };
    static CURRENT_RTV0: Cell<usize> = const { Cell::new(0) };
    static CURRENT_DSV: Cell<usize> = const { Cell::new(0) };
    static LAST_DRAW: RefCell<Option<DrawSnapshot>> = const { RefCell::new(None) };
}

static LOG_FILE: OnceLock<Mutex<File>> = OnceLock::new();

fn log_path() -> PathBuf {
    std::env::current_exe()
        .ok()
        .and_then(|p| p.parent().map(|d| d.join("ACZRenderOracle.log")))
        .unwrap_or_else(|| PathBuf::from("ACZRenderOracle.log"))
}

fn log(args: fmt::Arguments<'_>) {
    let mutex = LOG_FILE.get_or_init(|| {
        let file = OpenOptions::new()
            .create(true)
            .write(true)
            .truncate(true)
            .open(log_path())
            .expect("failed to open ACZRenderOracle.log");
        Mutex::new(file)
    });
    if let Ok(mut file) = mutex.lock() {
        let _ = writeln!(file, "{}", args);
        let _ = file.flush();
    }
}
macro_rules! logln {
    ($($tt:tt)*) => { log(format_args!($($tt)*)) };
}

fn sha256_hex(bytes: &[u8]) -> String {
    let digest = Sha256::digest(bytes);
    let mut out = String::with_capacity(64);
    for b in digest {
        use std::fmt::Write as _;
        let _ = write!(&mut out, "{b:02x}");
    }
    out
}

fn verify_host() -> bool {
    let path = match std::env::current_exe() {
        Ok(p) => p,
        Err(e) => {
            logln!("[boot] current_exe failed: {e}");
            return false;
        }
    };
    let mut file = match File::open(&path) {
        Ok(f) => f,
        Err(e) => {
            logln!("[boot] cannot open host executable: {e}");
            return false;
        }
    };
    let mut bytes = Vec::new();
    if let Err(e) = file.read_to_end(&mut bytes) {
        logln!("[boot] cannot read host executable: {e}");
        return false;
    }
    let hash = sha256_hex(&bytes);
    logln!("[boot] host={}", path.display());
    logln!("[boot] sha256={hash}");
    logln!("[boot] expected={EXPECTED_SHA256}");
    if hash != EXPECTED_SHA256 {
        logln!("[boot] REFUSED: executable hash mismatch; no hooks installed.");
        return false;
    }
    if bytes.len() < 0x100 || &bytes[0..2] != b"MZ" {
        logln!("[boot] REFUSED: invalid PE image.");
        return false;
    }
    let pe = u32::from_le_bytes(bytes[0x3c..0x40].try_into().unwrap()) as usize;
    if pe + 0x20 >= bytes.len() || &bytes[pe..pe + 4] != b"PE\0\0" {
        logln!("[boot] REFUSED: invalid PE signature.");
        return false;
    }
    let machine = u16::from_le_bytes(bytes[pe + 4..pe + 6].try_into().unwrap());
    let opt_magic = u16::from_le_bytes(bytes[pe + 0x18..pe + 0x1a].try_into().unwrap());
    if machine != 0x8664 || opt_magic != 0x20b {
        logln!("[boot] REFUSED: expected PE32+/AMD64, got machine=0x{machine:04x} magic=0x{opt_magic:04x}");
        return false;
    }
    true
}

#[inline]
fn current_render_frame() -> u64 {
    COMPLETED_FRAME.load(Ordering::Acquire) + 1
}
#[inline]
fn capture_this_frame() -> bool {
    let target = CAPTURE_TARGET_FRAME.load(Ordering::Acquire);
    target != 0 && target == current_render_frame()
}
#[inline]
fn hud_parse_active() -> bool {
    HUD_PARSE_DEPTH.with(|d| d.get() != 0)
}

fn spans() -> &'static Mutex<Vec<Span>> {
    HUD_SPANS.get_or_init(|| Mutex::new(Vec::with_capacity(MAX_HUD_SPANS)))
}
fn pso_map() -> &'static Mutex<HashMap<usize, PsoFingerprint>> {
    PSO_FINGERPRINTS.get_or_init(|| Mutex::new(HashMap::new()))
}
fn capture_hook_targets() -> &'static Mutex<Vec<usize>> {
    CAPTURE_HOOK_TARGETS.get_or_init(|| Mutex::new(Vec::new()))
}
fn remember_capture_hook(target: *mut c_void) {
    if let Ok(mut hooks) = capture_hook_targets().lock() {
        hooks.push(target as usize);
    }
}
unsafe fn set_capture_hooks_enabled(enabled: bool) {
    let Ok(hooks) = capture_hook_targets().lock() else { return };
    for &target in hooks.iter() {
        let status = if enabled {
            MH_EnableHook(target as *mut c_void)
        } else {
            MH_DisableHook(target as *mut c_void)
        };
        if status != MH_OK {
            logln!(
                "[hook] {} capture hook 0x{target:016x} failed status={status}",
                if enabled { "enable" } else { "disable" }
            );
        }
    }
    logln!(
        "[hook] capture hooks {} count={}",
        if enabled { "ENABLED" } else { "DISABLED" },
        hooks.len()
    );
}

unsafe fn read_ptr(address: usize) -> usize {
    *(address as *const usize)
}
unsafe fn vfunc(instance: usize, index: usize) -> *mut c_void {
    let vtable = *(instance as *const *const usize);
    *vtable.add(index) as *mut c_void
}

unsafe fn install_hook<T>(
    name: &str,
    target: *mut c_void,
    detour: *mut c_void,
    original_slot: &mut Option<T>,
) -> bool {
    let mut original = null_mut();
    let status = MH_CreateHook(target, detour, &mut original);
    if status != MH_OK {
        logln!("[hook] {name}: MH_CreateHook failed status={status}");
        return false;
    }
    *original_slot = Some(mem::transmute_copy::<*mut c_void, T>(&original));
    let status = MH_EnableHook(target);
    if status != MH_OK {
        logln!("[hook] {name}: MH_EnableHook failed status={status}");
        return false;
    }
    logln!("[hook] {name}: target=0x{:016x}", target as usize);
    true
}

type HudEmitter = unsafe extern "system" fn(*mut i64, i64, i64, *mut usize, i64) -> i64;
type PacketInterpreter = unsafe extern "system" fn(i64, i64, i32, i64);
type BatchFlush = unsafe extern "system" fn(i64) -> i16;
type LegacyBatchRender = unsafe extern "system" fn(i64) -> i64;
type ModernDrawBuilder = unsafe extern "system" fn(
    i64, i32, *mut i8, i32, i32, i32, u8, i32, i32, i32, i32, i8,
    *mut usize, *const c_void, i32,
);
type D3D12DrawHelper =
    unsafe extern "system" fn(*mut i64, i64, i64, i64, i32, u32, u32) -> i64;
type FrameEnd = unsafe extern "system" fn() -> i64;

static mut ORIG_HUD_EMITTER: Option<HudEmitter> = None;
static mut ORIG_PACKET_INTERPRETER: Option<PacketInterpreter> = None;
static mut ORIG_BATCH_FLUSH: Option<BatchFlush> = None;
static mut ORIG_LEGACY_BATCH_RENDER: Option<LegacyBatchRender> = None;
static mut ORIG_MODERN_DRAW_BUILDER: Option<ModernDrawBuilder> = None;
static mut ORIG_D3D12_DRAW_HELPER: Option<D3D12DrawHelper> = None;
static mut ORIG_FRAME_END: Option<FrameEnd> = None;

unsafe extern "system" fn hk_hud_emitter(
    rcx: *mut i64,
    packet_begin: i64,
    r8: i64,
    a4: *mut usize,
    a5: i64,
) -> i64 {
    let result = ORIG_HUD_EMITTER.unwrap()(rcx, packet_begin, r8, a4, a5);
    if capture_this_frame() {
        let begin = packet_begin as usize;
        let end = result as usize;
        if end >= begin && end - begin <= 4 * 1024 * 1024 {
            if let Ok(mut list) = spans().lock() {
                if list.len() < MAX_HUD_SPANS {
                    list.push(Span { begin, end });
                    logln!(
                        "[hud-span] frame={} idx={} begin=0x{begin:016x} end=0x{end:016x} bytes={}",
                        current_render_frame(),
                        list.len() - 1,
                        end - begin
                    );
                }
            }
        } else {
            logln!(
                "[hud-span] frame={} suspicious begin=0x{begin:016x} end=0x{end:016x}",
                current_render_frame()
            );
        }
    }
    result
}

fn packet_is_in_hud_span(ptr: usize) -> bool {
    let Ok(list) = spans().lock() else { return false };
    list.iter().any(|s| ptr >= s.begin && ptr < s.end)
}

unsafe extern "system" fn hk_packet_interpreter(a1: i64, a2: i64, a3: i32, a4: i64) {
    let is_hud = capture_this_frame() && packet_is_in_hud_span(a2 as usize);
    if is_hud {
        let first = *(a2 as *const u32);
        let opcode = ((first >> 24) & 0x7f) as u8;
        logln!(
            "[hud-parse] frame={} payload=0x{:016x} words={} next=0x{:016x} first=0x{first:08x} opcode=0x{opcode:02x}",
            current_render_frame(),
            a2 as usize,
            a3,
            a4 as usize
        );
        HUD_PARSE_DEPTH.with(|d| d.set(d.get() + 1));
    }
    ORIG_PACKET_INTERPRETER.unwrap()(a1, a2, a3, a4);
    if is_hud {
        HUD_PARSE_DEPTH.with(|d| d.set(d.get().saturating_sub(1)));
    }
}

unsafe extern "system" fn hk_batch_flush(a1: i64) -> i16 {
    if capture_this_frame() && hud_parse_active() {
        logln!("[hud-flush] frame={} state=0x{:016x}", current_render_frame(), a1 as usize);
    }
    ORIG_BATCH_FLUSH.unwrap()(a1)
}

unsafe extern "system" fn hk_legacy_batch_render(a1: i64) -> i64 {
    if capture_this_frame() && hud_parse_active() {
        logln!(
            "[hud-legacy-batch] frame={} ctx=0x{:016x}",
            current_render_frame(),
            a1 as usize
        );
    }
    ORIG_LEGACY_BATCH_RENDER.unwrap()(a1)
}

unsafe extern "system" fn hk_modern_draw_builder(
    a1: i64, a2: i32, a3: *mut i8, a4: i32, a5: i32, a6: i32, a7: u8,
    a8: i32, a9: i32, a10: i32, a11: i32, a12: i8, a13: *mut usize,
    a14: *const c_void, a15: i32,
) {
    let tagged = capture_this_frame() && hud_parse_active();
    if tagged {
        logln!(
            "[hud-draw-builder] frame={} a1=0x{:016x} a2={} vertices=0x{:016x} vertex_count={} prim={} a6={} a7={} a8={} a9={} a10={} a11={} a12={} indices=0x{:016x} index_count={}",
            current_render_frame(),
            a1 as usize, a2, a3 as usize, a4, a5, a6, a7, a8, a9, a10, a11,
            a12, a14 as usize, a15
        );
        HUD_BUILDER_DEPTH_GLOBAL.fetch_add(1, Ordering::AcqRel);
    }

    ORIG_MODERN_DRAW_BUILDER.unwrap()(
        a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15
    );

    if tagged {
        HUD_BUILDER_DEPTH_GLOBAL.fetch_sub(1, Ordering::AcqRel);
    }
}

unsafe extern "system" fn hk_d3d12_draw_helper(
    cmd: *mut i64, a2: i64, a3: i64, a4: i64, a5: i32, a6: u32, a7: u32,
) -> i64 {
    if capture_this_frame() && hud_parse_active() {
        logln!(
            "[hud-draw-helper] frame={} cmd=0x{:016x} root0=0x{:x} root1=0x{:x} index_ctx=0x{:x} index_slot={} vertex_count={} index_count={}",
            current_render_frame(), cmd as usize, a2, a3, a4, a5, a6, a7
        );
    }
    ORIG_D3D12_DRAW_HELPER.unwrap()(cmd, a2, a3, a4, a5, a6, a7)
}

unsafe extern "system" fn hk_frame_end() -> i64 {
    let frame = current_render_frame();
    if frame == CAPTURE_TARGET_FRAME.load(Ordering::Acquire) {
        logln!(
            "[frame-end] frame={} hud_spans={} hud_draws={}",
            frame,
            spans().lock().map(|v| v.len()).unwrap_or(0),
            HUD_DRAW_COUNT.load(Ordering::Relaxed)
        );
    }
    let result = ORIG_FRAME_END.unwrap()();
    COMPLETED_FRAME.store(frame, Ordering::Release);

    if frame == CAPTURE_TARGET_FRAME.load(Ordering::Acquire) {
        set_capture_hooks_enabled(false);
        logln!("[capture] END frame={frame}");
        CAPTURE_TARGET_FRAME.store(0, Ordering::Release);
    }
    if CAPTURE_REQUESTED.swap(false, Ordering::AcqRel) {
        let target = frame + 1;
        if let Ok(mut list) = spans().lock() { list.clear(); }
        LAST_DRAW.with(|v| *v.borrow_mut() = None);
        HUD_DRAW_COUNT.store(0, Ordering::Release);
        FIRST_HUD_DRAW_SEEN.store(false, Ordering::Release);
        CAPTURE_TARGET_FRAME.store(target, Ordering::Release);
        set_capture_hooks_enabled(true);
        logln!("[capture] ARMED target_frame={target}; complete_frame_now={frame}");
    }
    result
}

#[repr(C)]
#[derive(Clone, Copy)]
struct CpuDescriptorHandle {
    ptr: usize,
}
type SetPipelineState = unsafe extern "system" fn(*mut c_void, *mut c_void);
type IaSetPrimitiveTopology = unsafe extern "system" fn(*mut c_void, u32);
type OmSetRenderTargets = unsafe extern "system" fn(
    *mut c_void, u32, *const CpuDescriptorHandle, i32, *const CpuDescriptorHandle,
);
type DrawInstanced = unsafe extern "system" fn(*mut c_void, u32, u32, u32, u32);
type DrawIndexedInstanced = unsafe extern "system" fn(*mut c_void, u32, u32, u32, i32, u32);

static mut ORIG_SET_PIPELINE_STATE: Option<SetPipelineState> = None;
static mut ORIG_IA_SET_PRIMITIVE_TOPOLOGY: Option<IaSetPrimitiveTopology> = None;
static mut ORIG_OM_SET_RENDER_TARGETS: Option<OmSetRenderTargets> = None;
static mut ORIG_DRAW_INSTANCED: Option<DrawInstanced> = None;
static mut ORIG_DRAW_INDEXED_INSTANCED: Option<DrawIndexedInstanced> = None;

unsafe extern "system" fn hk_set_pipeline_state(cmd: *mut c_void, pso: *mut c_void) {
    CURRENT_PSO.with(|v| v.set(pso as usize));
    ORIG_SET_PIPELINE_STATE.unwrap()(cmd, pso);
}
unsafe extern "system" fn hk_ia_set_primitive_topology(cmd: *mut c_void, topology: u32) {
    CURRENT_TOPOLOGY.with(|v| v.set(topology));
    ORIG_IA_SET_PRIMITIVE_TOPOLOGY.unwrap()(cmd, topology);
}
unsafe extern "system" fn hk_om_set_render_targets(
    cmd: *mut c_void,
    count: u32,
    rtvs: *const CpuDescriptorHandle,
    single_range: i32,
    dsv: *const CpuDescriptorHandle,
) {
    let rtv0 = if count != 0 && !rtvs.is_null() { (*rtvs).ptr } else { 0 };
    let dsv0 = if !dsv.is_null() { (*dsv).ptr } else { 0 };
    CURRENT_RTV0.with(|v| v.set(rtv0));
    CURRENT_DSV.with(|v| v.set(dsv0));
    ORIG_OM_SET_RENDER_TARGETS.unwrap()(cmd, count, rtvs, single_range, dsv);
}

unsafe fn cached_pso_sha256(pso: usize) -> Option<String> {
    if pso == 0 { return None; }
    type GetCachedBlob = unsafe extern "system" fn(*mut c_void, *mut *mut c_void) -> i32;
    type GetBufferPointer = unsafe extern "system" fn(*mut c_void) -> *mut c_void;
    type GetBufferSize = unsafe extern "system" fn(*mut c_void) -> usize;
    type Release = unsafe extern "system" fn(*mut c_void) -> u32;

    let get_cached: GetCachedBlob = mem::transmute(vfunc(pso, 8));
    let mut blob: *mut c_void = null_mut();
    if get_cached(pso as *mut c_void, &mut blob) < 0 || blob.is_null() {
        return None;
    }
    let get_ptr: GetBufferPointer = mem::transmute(vfunc(blob as usize, 3));
    let get_size: GetBufferSize = mem::transmute(vfunc(blob as usize, 4));
    let release: Release = mem::transmute(vfunc(blob as usize, 2));
    let ptr = get_ptr(blob);
    let size = get_size(blob);
    let hash = if !ptr.is_null() && size != 0 {
        Some(sha256_hex(slice::from_raw_parts(ptr as *const u8, size)))
    } else {
        None
    };
    release(blob);
    hash
}

fn describe_pso(pso: usize) -> String {
    if let Ok(map) = pso_map().lock() {
        if let Some(fp) = map.get(&pso) {
            return format!(
                "pso=0x{pso:016x} root=0x{:016x} vs={} ps={}",
                fp.root_signature, fp.vs_sha256, fp.ps_sha256
            );
        }
    }
    unsafe {
        if let Some(hash) = cached_pso_sha256(pso) {
            let fp = PsoFingerprint {
                vs_sha256: "-".to_owned(),
                ps_sha256: format!("cached:{hash}"),
                root_signature: 0,
            };
            if let Ok(mut map) = pso_map().lock() {
                map.insert(pso, fp);
            }
            return format!("pso=0x{pso:016x} cached_blob_sha256={hash} [creation not observed]");
        }
    }
    format!("pso=0x{pso:016x} [fingerprint unavailable]")
}

fn snapshot_draw(indexed: bool, a: [i64; 5]) -> DrawSnapshot {
    DrawSnapshot {
        indexed,
        pso: CURRENT_PSO.with(|v| v.get()),
        topology: CURRENT_TOPOLOGY.with(|v| v.get()),
        rtv0: CURRENT_RTV0.with(|v| v.get()),
        dsv: CURRENT_DSV.with(|v| v.get()),
        a,
    }
}
fn format_draw(tag: &str, d: DrawSnapshot) {
    logln!(
        "{tag} indexed={} {} topology={} rtv0=0x{:016x} dsv=0x{:016x} args=[{},{},{},{},{}]",
        d.indexed, describe_pso(d.pso), d.topology, d.rtv0, d.dsv,
        d.a[0], d.a[1], d.a[2], d.a[3], d.a[4]
    );
}

fn observe_draw(draw: DrawSnapshot) {
    if !capture_this_frame() {
        return;
    }
    let hud = hud_parse_active();
    if hud {
        let ordinal = HUD_DRAW_COUNT.fetch_add(1, Ordering::AcqRel);
        if ordinal < MAX_HUD_DRAWS_TO_LOG {
            format_draw(&format!("[hud-d3d12-draw #{ordinal}]"), draw);
        }
        if !FIRST_HUD_DRAW_SEEN.swap(true, Ordering::AcqRel) {
            LAST_DRAW.with(|last| {
                if let Some(prev) = *last.borrow() {
                    format_draw("[pre-hud-d3d12-draw]", prev);
                } else {
                    logln!("[pre-hud-d3d12-draw] unavailable");
                }
            });
            format_draw("[FIRST-HUD-D3D12-DRAW]", draw);
        }
    }
    LAST_DRAW.with(|last| *last.borrow_mut() = Some(draw));
}

unsafe extern "system" fn hk_draw_instanced(
    cmd: *mut c_void,
    vertex_count: u32,
    instance_count: u32,
    start_vertex: u32,
    start_instance: u32,
) {
    observe_draw(snapshot_draw(false, [
        vertex_count as i64,
        instance_count as i64,
        start_vertex as i64,
        start_instance as i64,
        0,
    ]));
    ORIG_DRAW_INSTANCED.unwrap()(cmd, vertex_count, instance_count, start_vertex, start_instance);
}

unsafe extern "system" fn hk_draw_indexed_instanced(
    cmd: *mut c_void,
    index_count: u32,
    instance_count: u32,
    start_index: u32,
    base_vertex: i32,
    start_instance: u32,
) {
    observe_draw(snapshot_draw(true, [
        index_count as i64,
        instance_count as i64,
        start_index as i64,
        base_vertex as i64,
        start_instance as i64,
    ]));
    ORIG_DRAW_INDEXED_INSTANCED.unwrap()(
        cmd, index_count, instance_count, start_index, base_vertex, start_instance
    );
}

unsafe fn install_game_hooks(base: usize) -> bool {
    let mut ok = true;
    ok &= install_hook(
        "HUD emitter",
        (base + RVA_HUD_EMITTER) as *mut c_void,
        hk_hud_emitter as *mut c_void,
        &mut ORIG_HUD_EMITTER,
    );
    ok &= install_hook(
        "packet interpreter",
        (base + RVA_PACKET_INTERPRETER) as *mut c_void,
        hk_packet_interpreter as *mut c_void,
        &mut ORIG_PACKET_INTERPRETER,
    );
    ok &= install_hook(
        "batch flush",
        (base + RVA_BATCH_FLUSH) as *mut c_void,
        hk_batch_flush as *mut c_void,
        &mut ORIG_BATCH_FLUSH,
    );
    ok &= install_hook(
        "legacy batch render",
        (base + RVA_LEGACY_BATCH_RENDER) as *mut c_void,
        hk_legacy_batch_render as *mut c_void,
        &mut ORIG_LEGACY_BATCH_RENDER,
    );
    ok &= install_hook(
        "modern draw builder",
        (base + RVA_MODERN_DRAW_BUILDER) as *mut c_void,
        hk_modern_draw_builder as *mut c_void,
        &mut ORIG_MODERN_DRAW_BUILDER,
    );
    ok &= install_hook(
        "D3D12 draw helper",
        (base + RVA_D3D12_DRAW_HELPER) as *mut c_void,
        hk_d3d12_draw_helper as *mut c_void,
        &mut ORIG_D3D12_DRAW_HELPER,
    );
    ok &= install_hook(
        "frame end",
        (base + RVA_FRAME_END) as *mut c_void,
        hk_frame_end as *mut c_void,
        &mut ORIG_FRAME_END,
    );

    // High-frequency hooks are created once, but disabled during normal gameplay.
    // They are enabled for exactly one requested frame.
    for rva in [
        RVA_PACKET_INTERPRETER,
        RVA_BATCH_FLUSH,
        RVA_LEGACY_BATCH_RENDER,
        RVA_MODERN_DRAW_BUILDER,
        RVA_D3D12_DRAW_HELPER,
    ] {
        let target = (base + rva) as *mut c_void;
        remember_capture_hook(target);
        let status = MH_DisableHook(target);
        if status != MH_OK {
            logln!("[hook] initial disable failed target=0x{:016x} status={status}", target as usize);
            ok = false;
        }
    }
    ok
}

unsafe fn install_d3d12_vtable_hooks(base: usize) -> bool {
    let global = base + RVA_DEVICE_RESOURCES_GLOBAL;
    for _ in 0..3000 {
        let devres = read_ptr(global);
        if devres != 0 {
            let device = read_ptr(devres + 0x08);
            let cmd = read_ptr(devres + 0x10);
            if device != 0 && cmd != 0 {
                logln!(
                    "[d3d12] DeviceResources=0x{devres:016x} device=0x{device:016x} command_list=0x{cmd:016x}"
                );
                let mut ok = true;
                ok &= install_hook(
                    "ID3D12GraphicsCommandList::SetPipelineState",
                    vfunc(cmd, GCL_SET_PIPELINE_STATE),
                    hk_set_pipeline_state as *mut c_void,
                    &mut ORIG_SET_PIPELINE_STATE,
                );
                ok &= install_hook(
                    "ID3D12GraphicsCommandList::IASetPrimitiveTopology",
                    vfunc(cmd, GCL_IA_SET_PRIMITIVE_TOPOLOGY),
                    hk_ia_set_primitive_topology as *mut c_void,
                    &mut ORIG_IA_SET_PRIMITIVE_TOPOLOGY,
                );
                ok &= install_hook(
                    "ID3D12GraphicsCommandList::OMSetRenderTargets",
                    vfunc(cmd, GCL_OM_SET_RENDER_TARGETS),
                    hk_om_set_render_targets as *mut c_void,
                    &mut ORIG_OM_SET_RENDER_TARGETS,
                );
                ok &= install_hook(
                    "ID3D12GraphicsCommandList::DrawInstanced",
                    vfunc(cmd, GCL_DRAW_INSTANCED),
                    hk_draw_instanced as *mut c_void,
                    &mut ORIG_DRAW_INSTANCED,
                );
                ok &= install_hook(
                    "ID3D12GraphicsCommandList::DrawIndexedInstanced",
                    vfunc(cmd, GCL_DRAW_INDEXED_INSTANCED),
                    hk_draw_indexed_instanced as *mut c_void,
                    &mut ORIG_DRAW_INDEXED_INSTANCED,
                );

                for target in [
                    vfunc(cmd, GCL_SET_PIPELINE_STATE),
                    vfunc(cmd, GCL_IA_SET_PRIMITIVE_TOPOLOGY),
                    vfunc(cmd, GCL_OM_SET_RENDER_TARGETS),
                    vfunc(cmd, GCL_DRAW_INSTANCED),
                    vfunc(cmd, GCL_DRAW_INDEXED_INSTANCED),
                ] {
                    remember_capture_hook(target);
                    let status = MH_DisableHook(target);
                    if status != MH_OK {
                        logln!("[hook] initial D3D12 disable failed target=0x{:016x} status={status}", target as usize);
                        ok = false;
                    }
                }
                return ok;
            }
        }
        Sleep(10);
    }
    logln!("[d3d12] timed out waiting for DeviceResources/device/command list.");
    false
}

unsafe extern "system" fn bootstrap(_: *mut c_void) -> u32 {
    let base = GetModuleHandleW(null()) as usize;
    IMAGE_BASE.store(base, Ordering::Release);
    logln!("[boot] ACZRenderOracle starting base=0x{base:016x}");
    logln!(
        "[boot] RVAs hud=0x{RVA_HUD_EMITTER:x} parser=0x{RVA_DISPLAY_LIST_PARSER:x} interp=0x{RVA_PACKET_INTERPRETER:x} batch=0x{RVA_LEGACY_BATCH_RENDER:x} builder=0x{RVA_MODERN_DRAW_BUILDER:x} draw=0x{RVA_D3D12_DRAW_HELPER:x} frame_end=0x{RVA_FRAME_END:x} devres=0x{RVA_DEVICE_RESOURCES_GLOBAL:x}"
    );

    if !verify_host() {
        return 1;
    }
    if MH_Initialize() != MH_OK {
        logln!("[boot] MinHook initialization failed.");
        return 2;
    }
    if !install_game_hooks(base) {
        logln!("[boot] one or more game hooks failed; refusing capture.");
        return 3;
    }
    logln!("[boot] system D3D12 vtable hooks are disabled; oracle uses ACZ-owned RVA hooks only.");
    logln!("[boot] READY. Press keypad '+' once to capture one complete future frame.");

    let mut was_down = false;
    loop {
        let down = (GetAsyncKeyState(VK_ADD) as u16 & 0x8000) != 0;
        if down && !was_down && CAPTURE_TARGET_FRAME.load(Ordering::Acquire) == 0 {
            CAPTURE_REQUESTED.store(true, Ordering::Release);
            logln!(
                "[key] VK_ADD requested at completed_frame={}",
                COMPLETED_FRAME.load(Ordering::Acquire)
            );
        }
        was_down = down;
        Sleep(5);
    }
}


#[unsafe(no_mangle)]
pub extern "system" fn ACZOracleScopeFlags() -> u32 {
    let mut flags = 0u32;
    if capture_this_frame() {
        flags |= 1;
    }
    if HUD_PARSE_DEPTH.with(|d| d.get() != 0) {
        flags |= 2;
    }
    if HUD_BUILDER_DEPTH_GLOBAL.load(Ordering::Acquire) != 0 {
        flags |= 4;
    }
    flags
}

struct RealXInput {
    get_state: unsafe extern "system" fn(u32, *mut c_void) -> u32,
    set_state: unsafe extern "system" fn(u32, *mut c_void) -> u32,
}
static REAL_XINPUT: OnceLock<RealXInput> = OnceLock::new();

fn wide_null(text: &std::ffi::OsStr) -> Vec<u16> {
    use std::os::windows::ffi::OsStrExt;
    text.encode_wide().chain(std::iter::once(0)).collect()
}
unsafe fn load_real_xinput() -> &'static RealXInput {
    REAL_XINPUT.get_or_init(|| {
        let windir = std::env::var_os("WINDIR").unwrap_or_else(|| "C:\\Windows".into());
        let path = PathBuf::from(windir).join("System32").join("XInput1_4.dll");
        let wide = wide_null(path.as_os_str());
        let module = LoadLibraryW(wide.as_ptr());
        assert!(!module.is_null(), "failed to load real System32\\XInput1_4.dll");

        unsafe fn proc(module: HINSTANCE, name: &'static CStr) -> *mut c_void {
            GetProcAddress(module, name.as_ptr() as *const u8)
                .map(|f| f as *mut c_void)
                .unwrap_or(null_mut())
        }
        let get_state = proc(module, c"XInputGetState");
        let set_state = proc(module, c"XInputSetState");
        assert!(!get_state.is_null() && !set_state.is_null(), "missing XInput1_4 export");
        RealXInput {
            get_state: mem::transmute(get_state),
            set_state: mem::transmute(set_state),
        }
    })
}

#[unsafe(no_mangle)]
pub unsafe extern "system" fn XInputGetState(user_index: u32, state: *mut c_void) -> u32 {
    (load_real_xinput().get_state)(user_index, state)
}
#[unsafe(no_mangle)]
pub unsafe extern "system" fn XInputSetState(user_index: u32, vibration: *mut c_void) -> u32 {
    (load_real_xinput().set_state)(user_index, vibration)
}

#[unsafe(no_mangle)]
pub unsafe extern "system" fn DllMain(
    instance: HINSTANCE,
    reason: u32,
    _: *mut c_void,
) -> i32 {
    if reason == DLL_PROCESS_ATTACH {
        OWN_MODULE.store(instance as usize, Ordering::Release);
        let thread = CreateThread(
            null(),
            0,
            Some(bootstrap),
            null_mut(),
            0,
            null_mut(),
        );
        if !thread.is_null() {
            CloseHandle(thread);
        }
    }
    1
}

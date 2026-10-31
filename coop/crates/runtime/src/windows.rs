//! Unsafe Win64 boundary only. ReShade calls AddonInit after LoadLibraryEx returns.
use crate::{HookBackend, HookPlan, ObserverConfig};
use acz_coop_contracts::{Error, Result};
use acz_coop_game::{HOOKS, MemoryReader, Observer, VerifiedImage};
use acz_coop_trace::{self as trace, Record, Status, TraceSender};
use minhook_sys::{
    MH_CreateHook, MH_DisableHook, MH_EnableHook, MH_Initialize, MH_OK, MH_RemoveHook,
};
use std::{
    ffi::{CString, c_void},
    fs::{self, OpenOptions},
    io::BufWriter,
    path::PathBuf,
    ptr::{null, null_mut},
    sync::{
        Mutex, OnceLock,
        atomic::{AtomicBool, AtomicUsize, Ordering},
    },
    time::{SystemTime, UNIX_EPOCH},
};
use windows_sys::Win32::{
    Foundation::HMODULE,
    System::{
        Diagnostics::Debug::ReadProcessMemory,
        LibraryLoader::{
            GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, GET_MODULE_HANDLE_EX_FLAG_PIN,
            GetModuleFileNameW, GetModuleHandleExW, GetModuleHandleW, GetProcAddress,
        },
        Threading::{GetCurrentProcess, GetCurrentProcessId, GetCurrentThreadId},
    },
};

static INITIALIZED: AtomicBool = AtomicBool::new(false);
static STOP: AtomicBool = AtomicBool::new(false);
static ORIGINAL: [AtomicUsize; 4] = [const { AtomicUsize::new(0) }; 4];
struct Context {
    observer: Mutex<Observer>,
    image: VerifiedImage,
    wingman_probe: bool,
    trace: TraceSender,
}
static CONTEXT: OnceLock<Context> = OnceLock::new();
struct LocalMemory;
impl MemoryReader for LocalMemory {
    fn read_exact(&self, address: usize, out: &mut [u8]) -> Result<()> {
        if address == 0 || address.checked_add(out.len()).is_none() {
            return Err(Error::Bounds("native read"));
        }
        let mut n = 0;
        // SAFETY: ReadProcessMemory validates source pages; destination is an initialized writable slice.
        let ok = unsafe {
            ReadProcessMemory(
                GetCurrentProcess(),
                address as *const c_void,
                out.as_mut_ptr().cast(),
                out.len(),
                &mut n,
            )
        };
        if ok == 0 || n != out.len() {
            Err(Error::Unavailable)
        } else {
            Ok(())
        }
    }
}
fn module_path(module: HMODULE) -> std::io::Result<PathBuf> {
    use std::os::windows::ffi::OsStringExt;
    let mut buffer = vec![0u16; 32768];
    // SAFETY: module is supplied by ReShade, or null for the host. Buffer has the passed capacity.
    let n =
        unsafe { GetModuleFileNameW(module, buffer.as_mut_ptr(), buffer.len() as u32) } as usize;
    if n == 0 || n >= buffer.len() {
        return Err(std::io::Error::last_os_error());
    }
    Ok(std::ffi::OsString::from_wide(&buffer[..n]).into())
}
unsafe fn register(module: HMODULE, reshade: HMODULE) -> bool {
    // SAFETY: caller supplies the two live loader handles; export type matches ReShade API 20.
    unsafe {
        match GetProcAddress(reshade, c"ReShadeRegisterAddon".as_ptr().cast()) {
            Some(p) => std::mem::transmute::<
                unsafe extern "system" fn() -> isize,
                unsafe extern "C" fn(HMODULE, u32) -> bool,
            >(p)(module, 20),
            None => false,
        }
    }
}
unsafe fn unregister(module: HMODULE, reshade: HMODULE) {
    // SAFETY: same live handles and official ReShade export signature.
    unsafe {
        if let Some(p) = GetProcAddress(reshade, c"ReShadeUnregisterAddon".as_ptr().cast()) {
            std::mem::transmute::<
                unsafe extern "system" fn() -> isize,
                unsafe extern "C" fn(HMODULE),
            >(p)(module);
        }
    }
}
fn log(module: HMODULE, reshade: HMODULE, message: &str) {
    if let Ok(text) = CString::new(message) {
        // SAFETY: only initialization calls this with valid ReShade handles; not used from hooks or after uninit.
        unsafe {
            if let Some(p) = GetProcAddress(reshade, c"ReShadeLogMessage".as_ptr().cast()) {
                std::mem::transmute::<
                    unsafe extern "system" fn() -> isize,
                    unsafe extern "C" fn(HMODULE, i32, *const i8),
                >(p)(module, 3, text.as_ptr());
            }
        }
    }
}
fn error_code(e: Error) -> u64 {
    match e {
        Error::Invalid(_) => 1,
        Error::Bounds(_) => 2,
        Error::Phase => 3,
        Error::Authority => 4,
        Error::Epoch => 5,
        Error::Duplicate => 6,
        Error::Stale => 7,
        Error::Gap => 8,
        Error::Exhausted => 9,
        Error::Conflict => 10,
        Error::WrongThread => 11,
        Error::BuildMismatch => 12,
        Error::Unavailable => 13,
        Error::Unsupported(_) => 14,
    }
}
fn record(status: Status, detail: u64) {
    if let Some(c) = CONTEXT.get() {
        c.trace.try_record(Record::Status {
            code: status,
            detail,
        });
    }
}
fn original(index: usize) -> usize {
    let p = ORIGINAL[index].load(Ordering::Acquire);
    if p == 0 {
        std::process::abort();
    }
    p
}
unsafe extern "system" fn on_enter(mode: usize) {
    // SAFETY: exact one-argument native member ABI; trampoline published before hook enable.
    unsafe {
        std::mem::transmute::<usize, unsafe extern "system" fn(usize)>(original(0))(mode);
    }
    if STOP.load(Ordering::Acquire) {
        return;
    }
    if let Some(c) = CONTEXT.get() {
        if let Ok(mut o) = c.observer.try_lock() {
            match o.enter(&LocalMemory, mode, unsafe { GetCurrentThreadId() }) {
                Ok(g) => record(Status::WorldEntered, g),
                Err(e) => record(Status::EnterRejected, error_code(e)),
            }
        }
    }
}
unsafe extern "system" fn on_leave(mode: usize) {
    if !STOP.load(Ordering::Acquire) {
        if let Some(c) = CONTEXT.get() {
            if let Ok(mut o) = c.observer.try_lock() {
                match o.leave(mode, unsafe { GetCurrentThreadId() }) {
                    Ok(()) => record(Status::WorldLeft, 0),
                    Err(e) => record(Status::LeaveRejected, error_code(e)),
                }
            } else {
                // A leave missed due to contention must stop future observation rather than retaining a stale world.
                STOP.store(true, Ordering::Release);
            }
        }
    }
    // SAFETY: invalidate before the original cleanup frees arena state; native ABI is RCX only.
    unsafe {
        std::mem::transmute::<usize, unsafe extern "system" fn(usize)>(original(1))(mode);
    }
}
fn observe_before_update(mode: usize) {
    if STOP.load(Ordering::Acquire) {
        return;
    }
    if let Some(c) = CONTEXT.get() {
        if let Ok(mut o) = c.observer.try_lock() {
            let thread = unsafe { GetCurrentThreadId() };
            // ReShade may load after a native enter. Explicit adoption is logged and still needs a full re-entry HIL trace.
            if !o.is_live() {
                match o.enter(&LocalMemory, mode, thread) {
                    Ok(g) => record(Status::Adopted, g),
                    Err(e) => {
                        record(Status::EnterRejected, error_code(e));
                        return;
                    }
                }
            }
            match o.observe(&LocalMemory, mode, thread) {
                Ok(frame) => {
                    c.trace.try_record(Record::Native(frame));
                }
                Err(e) => record(Status::UpdateRejected, error_code(e)),
            }
        }
    }
}
fn observe_after_update(mode: usize) {
    if STOP.load(Ordering::Acquire) {
        return;
    }
    if let Some(c) = CONTEXT.get() {
        if !c.wingman_probe {
            return;
        }
        if let Ok(o) = c.observer.try_lock() {
            // SAFETY: identity-only Win32 API. inspect never adopts a world after a native leave.
            let thread = unsafe { GetCurrentThreadId() };
            match o.inspect(&LocalMemory, mode, thread) {
                Ok(frame) if frame.ready => {
                    match acz_coop_wingman::capture(&LocalMemory, &c.image, &frame) {
                        Ok(snapshot) => {
                            c.trace.try_record(Record::Wingman(snapshot));
                        }
                        Err(e) => record(Status::WingmanProbeRejected, error_code(e)),
                    }
                }
                Ok(_) | Err(Error::Unavailable) => {}
                Err(e) => record(Status::WingmanProbeRejected, error_code(e)),
            }
        }
    }
}
unsafe extern "system" fn on_campaign_update(mode: usize, holder: usize) {
    observe_before_update(mode);
    // SAFETY: assembly consumes both RCX and RDX, including a holder tail-call on mission exit.
    unsafe {
        std::mem::transmute::<usize, unsafe extern "system" fn(usize, usize)>(original(2))(
            mode, holder,
        );
    }
    observe_after_update(mode);
}
unsafe extern "system" fn on_vs_update(mode: usize, holder: usize) {
    observe_before_update(mode);
    // SAFETY: VS update has the same two-argument storage contract.
    unsafe {
        std::mem::transmute::<usize, unsafe extern "system" fn(usize, usize)>(original(3))(
            mode, holder,
        );
    }
    observe_after_update(mode);
}
struct NativeHooks {
    targets: [usize; 4],
}
impl NativeHooks {
    fn new(image: &VerifiedImage) -> Result<Self> {
        let mut targets = [0; 4];
        for (i, h) in HOOKS.iter().enumerate() {
            targets[i] = image.executable_address(h.rva)?;
        }
        Ok(Self { targets })
    }
}
impl HookBackend for NativeHooks {
    fn create(&mut self, i: usize) -> Result<()> {
        let mut bytes = [0; 32];
        LocalMemory.read_exact(self.targets[i], &mut bytes)?;
        if bytes != HOOKS[i].bytes {
            return Err(Error::BuildMismatch);
        }
        let detour = match i {
            0 => on_enter as *const (),
            1 => on_leave as *const (),
            2 => on_campaign_update as *const (),
            3 => on_vs_update as *const (),
            _ => return Err(Error::Bounds("hook index")),
        };
        let mut trampoline = null_mut();
        // SAFETY: verified executable entry, typed detour, MinHook performs instruction relocation.
        let result = unsafe {
            MH_CreateHook(
                self.targets[i] as *mut c_void,
                detour as *mut c_void,
                &mut trampoline,
            )
        };
        if result != MH_OK || trampoline.is_null() {
            return Err(Error::Unavailable);
        }
        ORIGINAL[i].store(trampoline as usize, Ordering::Release);
        Ok(())
    }
    fn discard_unenabled(&mut self, i: usize) -> Result<()> {
        // SAFETY: HookPlan calls this only before any enable attempt; no callback can use this trampoline.
        if unsafe { MH_RemoveHook(self.targets[i] as *mut c_void) } != MH_OK {
            return Err(Error::Unavailable);
        }
        ORIGINAL[i].store(0, Ordering::Release);
        Ok(())
    }
    fn enable_all(&mut self) -> Result<()> {
        for target in self.targets {
            // SAFETY: callbacks/context and trampolines are already initialized; touches only our four hooks.
            if unsafe { MH_EnableHook(target as *mut c_void) } != MH_OK {
                return Err(Error::Unavailable);
            }
        }
        Ok(())
    }
    fn disable_all(&mut self) -> Result<()> {
        let mut failed = false;
        for target in self.targets {
            // SAFETY: initialization rollback outside DllMain; retain all trampolines even on failure.
            if unsafe { MH_DisableHook(target as *mut c_void) } != MH_OK {
                failed = true;
            }
        }
        if failed {
            Err(Error::Unavailable)
        } else {
            Ok(())
        }
    }
}
fn bootstrap(
    module: HMODULE,
    reshade: HMODULE,
) -> std::result::Result<(), Box<dyn std::error::Error>> {
    let host = module_path(null_mut())?;
    // SAFETY: null asks for the process executable handle; no module loading or arbitrary path resolution.
    let base = unsafe { GetModuleHandleW(null()) } as usize;
    let image = match VerifiedImage::from_pe(&fs::read(&host)?, base) {
        Ok(v) => v,
        Err(e) => {
            log(
                module,
                reshade,
                &format!("ACZCoop: rejected host build ({e}); no native hooks installed"),
            );
            return Ok(());
        }
    };
    let own = module_path(module)?;
    let config_path = own.with_file_name("ACZCoop.ini");
    let config = match fs::read_to_string(&config_path) {
        Ok(s) => ObserverConfig::parse(&s)?,
        Err(e) if e.kind() == std::io::ErrorKind::NotFound => ObserverConfig::default(),
        Err(e) => return Err(e.into()),
    };
    let stamp = SystemTime::now().duration_since(UNIX_EPOCH)?.as_nanos();
    let path = own.with_file_name(format!("ACZCoop-{}-{stamp}.trace.jsonl", unsafe {
        GetCurrentProcessId()
    }));
    let file = OpenOptions::new()
        .create_new(true)
        .write(true)
        .open(&path)?;
    let (tx, drain) = trace::channel(1024)?;
    tx.try_record(Record::Status {
        code: Status::Boot,
        detail: base as u64,
    });
    if !config.hooks {
        tx.try_record(Record::Status {
            code: Status::Disabled,
            detail: 0,
        });
        drain.run(&mut BufWriter::new(file), &AtomicBool::new(true))?;
        log(
            module,
            reshade,
            "ACZCoop: verified host; observer_hooks=false; diagnostic trace written",
        );
        return Ok(());
    }
    image.verify_loaded(&LocalMemory)?;
    let mut hooks = NativeHooks::new(&image)?;
    // SAFETY: official MinHook setup outside DllMain. Status 1 means this module's library already initialized.
    let status = unsafe { MH_Initialize() };
    if status != MH_OK && status != 1 {
        return Err(Error::Unavailable.into());
    }
    let mut pinned = null_mut();
    // SAFETY: FROM_ADDRESS treats this argument as an address, not a UTF-16 string. Pin before workers/hooks exist.
    if unsafe {
        GetModuleHandleExW(
            GET_MODULE_HANDLE_EX_FLAG_PIN | GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,
            AddonInit as *const () as *const u16,
            &mut pinned,
        )
    } == 0
    {
        return Err(std::io::Error::last_os_error().into());
    }
    CONTEXT
        .set(Context {
            observer: Mutex::new(Observer::new(image.clone())),
            image,
            wingman_probe: config.wingman_probe,
            trace: tx,
        })
        .map_err(|_| Error::Conflict)?;
    std::thread::Builder::new()
        .name("ACZCoopTrace".into())
        .spawn(move || {
            let _ = drain.run(&mut BufWriter::new(file), &STOP);
        })?;
    let mut plan = HookPlan::default();
    if let Err(e) = plan.install(&mut hooks, 4) {
        record(Status::HookFailure, 0);
        STOP.store(true, Ordering::Release);
        return Err(e.into());
    }
    record(Status::HooksReady, 4);
    log(
        module,
        reshade,
        "ACZCoop: 4 experimental read-only native observers enabled; no gameplay/network writes; exit game before replacing add-on",
    );
    Ok(())
}

// ReShade reads exported NAME/DESCRIPTION as addresses of const char pointers. Array references are thin pointers.
#[unsafe(no_mangle)]
pub static NAME: &[u8; 9] = b"ACZ Coop\0";
#[unsafe(no_mangle)]
pub static DESCRIPTION: &[u8; 52] = b"Experimental ACZ read-only co-op research observer.\0";
/// # Safety
/// ReShade must pass live add-on/host handles after LoadLibraryEx has returned (API 20).
#[unsafe(no_mangle)]
pub unsafe extern "C" fn AddonInit(module: HMODULE, reshade: HMODULE) -> bool {
    if module.is_null() || reshade.is_null() || INITIALIZED.swap(true, Ordering::AcqRel) {
        return false;
    }
    // SAFETY: loader handles and API verified by ReShade; registration precedes all other ReShade API calls.
    if !unsafe { register(module, reshade) } {
        return false;
    }
    match bootstrap(module, reshade) {
        Ok(()) => true,
        Err(e) => {
            STOP.store(true, Ordering::Release);
            log(
                module,
                reshade,
                &format!("ACZCoop initialization failed: {e}"),
            );
            unsafe { unregister(module, reshade) };
            false
        }
    }
}
/// # Safety
/// Called by the ReShade loader with the same live handles. No worker join or native frees under loader lock.
#[unsafe(no_mangle)]
pub unsafe extern "C" fn AddonUninit(module: HMODULE, reshade: HMODULE) {
    record(Status::Stopped, 0);
    STOP.store(true, Ordering::Release);
    // Hooks/trampolines and the module remain resident; callbacks now only forward originals. No hot unload.
    if !module.is_null() && !reshade.is_null() {
        unsafe { unregister(module, reshade) };
    }
}

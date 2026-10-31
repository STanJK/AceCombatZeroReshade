//! Bounded telemetry: game callbacks try-send; only a separate drain writes JSONL.
#![forbid(unsafe_code)]
use acz_coop_contracts::TARGET_SHA256;
use acz_coop_game::NativeFrame;
use acz_coop_wingman::{CameraSource, WingmanSnapshot, assess};
use std::io::{self, Write};
use std::sync::{
    Arc,
    atomic::{AtomicBool, AtomicU64, Ordering},
    mpsc::{self, Receiver, SyncSender, TrySendError},
};
use std::time::Duration;

#[derive(Debug, Clone, Copy)]
pub enum Status {
    Boot,
    BuildRejected,
    Disabled,
    HooksReady,
    HookFailure,
    EnterRejected,
    UpdateRejected,
    LeaveRejected,
    WorldEntered,
    WorldLeft,
    Adopted,
    Stopped,
    WingmanProbeRejected,
}
impl Status {
    fn name(self) -> &'static str {
        match self {
            Self::Boot => "boot",
            Self::BuildRejected => "build_rejected",
            Self::Disabled => "observer_disabled",
            Self::HooksReady => "hooks_ready",
            Self::HookFailure => "hook_failure",
            Self::EnterRejected => "enter_rejected",
            Self::UpdateRejected => "update_rejected",
            Self::LeaveRejected => "leave_rejected",
            Self::WorldEntered => "world_entered",
            Self::WorldLeft => "world_left",
            Self::Adopted => "adopted_at_update",
            Self::Stopped => "stopped",
            Self::WingmanProbeRejected => "wingman_probe_rejected",
        }
    }
}
#[derive(Debug, Clone)]
pub enum Record {
    Status { code: Status, detail: u64 },
    Native(NativeFrame),
    Wingman(WingmanSnapshot),
}
#[derive(Default)]
struct Counters {
    accepted: AtomicU64,
    dropped: AtomicU64,
    closed: AtomicU64,
    io_failed: AtomicBool,
}
#[derive(Debug, Clone, Copy)]
pub struct Metrics {
    pub accepted: u64,
    pub dropped: u64,
    pub closed: u64,
    pub io_failed: bool,
}
fn increment(c: &AtomicU64) {
    c.fetch_add(1, Ordering::Relaxed);
}
#[derive(Clone)]
pub struct TraceSender {
    tx: SyncSender<Record>,
    counts: Arc<Counters>,
}
pub struct TraceDrain {
    rx: Receiver<Record>,
    counts: Arc<Counters>,
    capacity: usize,
}
pub fn channel(capacity: usize) -> io::Result<(TraceSender, TraceDrain)> {
    if !(1..=65536).contains(&capacity) {
        return Err(io::Error::new(
            io::ErrorKind::InvalidInput,
            "trace capacity",
        ));
    }
    let (tx, rx) = mpsc::sync_channel(capacity);
    let counts = Arc::new(Counters::default());
    Ok((
        TraceSender {
            tx,
            counts: counts.clone(),
        },
        TraceDrain {
            rx,
            counts,
            capacity,
        },
    ))
}
impl TraceSender {
    /// Never waits for queue capacity. std's channel is not advertised as lock-free.
    pub fn try_record(&self, record: Record) -> bool {
        match self.tx.try_send(record) {
            Ok(()) => {
                increment(&self.counts.accepted);
                true
            }
            Err(TrySendError::Full(_)) => {
                increment(&self.counts.dropped);
                false
            }
            Err(TrySendError::Disconnected(_)) => {
                increment(&self.counts.closed);
                false
            }
        }
    }
    pub fn metrics(&self) -> Metrics {
        Metrics {
            accepted: self.counts.accepted.load(Ordering::Relaxed),
            dropped: self.counts.dropped.load(Ordering::Relaxed),
            closed: self.counts.closed.load(Ordering::Relaxed),
            io_failed: self.counts.io_failed.load(Ordering::Relaxed),
        }
    }
}
impl TraceDrain {
    pub fn run(self, writer: &mut impl Write, stop: &AtomicBool) -> io::Result<()> {
        let result = (|| {
            let hash: String = TARGET_SHA256.iter().map(|b| format!("{b:02x}")).collect();
            writeln!(
                writer,
                "{{\"type\":\"provenance\",\"schema\":1,\"build\":\"{hash}\",\"version\":\"{}\",\"scope\":\"native-observer\",\"read_only\":true}}",
                env!("CARGO_PKG_VERSION")
            )?;
            while !stop.load(Ordering::Acquire) {
                match self.rx.recv_timeout(Duration::from_millis(20)) {
                    Ok(record) => write_record(writer, &record)?,
                    Err(mpsc::RecvTimeoutError::Timeout) => writer.flush()?,
                    Err(mpsc::RecvTimeoutError::Disconnected) => break,
                }
            }
            // Bounded shutdown even if a buggy producer continues publishing.
            for _ in 0..self.capacity {
                match self.rx.try_recv() {
                    Ok(record) => write_record(writer, &record)?,
                    Err(_) => break,
                }
            }
            let c = &self.counts;
            writeln!(
                writer,
                "{{\"type\":\"trace_end\",\"accepted\":{},\"dropped\":{},\"closed\":{}}}",
                c.accepted.load(Ordering::Relaxed),
                c.dropped.load(Ordering::Relaxed),
                c.closed.load(Ordering::Relaxed)
            )?;
            writer.flush()
        })();
        if result.is_err() {
            self.counts.io_failed.store(true, Ordering::Release);
        }
        result
    }
}
fn vector(w: &mut impl Write, v: &[f32; 4]) -> io::Result<()> {
    write!(w, "[{},{},{},{}]", v[0], v[1], v[2], v[3])
}
fn write_record(w: &mut impl Write, record: &Record) -> io::Result<()> {
    match record {
        Record::Status { code, detail } => writeln!(
            w,
            "{{\"type\":\"status\",\"code\":\"{}\",\"detail\":{detail}}}",
            code.name()
        ),
        Record::Wingman(s) => write_wingman(w, s),
        Record::Native(f) => {
            if f.players.len() > 2
                || f.players.iter().any(|p| {
                    p.position
                        .iter()
                        .chain(p.context_position.iter())
                        .chain(p.orientation_like.iter())
                        .any(|v| !v.is_finite())
                })
            {
                return Err(io::Error::new(
                    io::ErrorKind::InvalidData,
                    "invalid native trace record",
                ));
            }
            write!(
                w,
                "{{\"type\":\"pre_update\",\"generation\":{},\"sample\":{},\"thread\":{},\"mode\":{},\"world\":{},\"ready\":{},\"setup\":{},\"native_tick\":",
                f.generation, f.sample, f.thread, f.mode, f.world, f.ready, f.setup
            )?;
            if let Some(v) = f.tick {
                write!(w, "{v}")?;
            } else {
                write!(w, "null")?;
            }
            write!(w, ",\"phase\":")?;
            if let Some(v) = f.phase {
                write!(w, "{v}")?;
            } else {
                write!(w, "null")?;
            }
            write!(w, ",\"players\":[")?;
            for (i, p) in f.players.iter().enumerate() {
                if i != 0 {
                    write!(w, ",")?;
                }
                write!(
                    w,
                    "{{\"slot\":{},\"group\":{},\"actor\":{},\"native_id\":{},\"hp\":{},\"flags\":{},\"context_position\":",
                    p.slot, p.group, p.actor, p.native_id, p.hp, p.flags
                )?;
                vector(w, &p.context_position)?;
                write!(w, ",\"actor_position\":")?;
                vector(w, &p.position)?;
                write!(w, ",\"native_orientation_like\":")?;
                vector(w, &p.orientation_like)?;
                write!(w, "}}")?;
            }
            writeln!(w, "]}}")
        }
    }
}

fn write_wingman(w: &mut impl Write, s: &WingmanSnapshot) -> io::Result<()> {
    if s.candidates.len() > 8 || s.views.len() > 4 || s.player_selectors.len() > 2 {
        return Err(io::Error::new(
            io::ErrorKind::InvalidData,
            "wingman trace bounds",
        ));
    }
    let readiness = assess(s);
    write!(
        w,
        "{{\"type\":\"wingman_post_update\",\"generation\":{},\"sample\":{},\"mode\":{},\"world\":{},\"campaign\":{},\"player_count\":{},\"world_flags\":{},\"world_phase\":{},\"camera_mode\":{},\"group\":{},\"group_category\":{},\"control_definition\":{},\"helper_count\":{},\"player_selectors\":[",
        s.generation,
        s.sample,
        s.mode,
        s.world,
        s.campaign,
        s.player_count,
        s.world_flags,
        s.world_phase,
        s.camera_mode,
        s.group,
        s.group_category,
        s.control_definition,
        s.helper_count
    )?;
    for (i, p) in s.player_selectors.iter().enumerate() {
        if i != 0 {
            write!(w, ",")?
        }
        write!(w, "[{},{}]", p[0], p[1])?;
    }
    write!(w, "],\"event\":")?;
    if let Some(e) = &s.event {
        write!(
            w,
            "{{\"controller\":{},\"flags\":{},\"index\":{},\"substate\":{},\"kind\":",
            e.controller, e.flags, e.index, e.substate
        )?;
        if let Some(k) = e.kind {
            write!(w, "{k}")?
        } else {
            write!(w, "null")?
        }
        write!(w, "}}")?;
    } else {
        write!(w, "null")?
    }
    write!(
        w,
        ",\"selection\":{{\"alternate_profile\":{},\"slots\":[",
        s.selection.alternate_profile
    )?;
    for (i, p) in s.selection.slots.iter().enumerate() {
        if i != 0 {
            write!(w, ",")?
        }
        write!(
            w,
            "{{\"aircraft\":{},\"weapon\":{},\"option\":{},\"color\":",
            p.aircraft, p.weapon, p.option
        )?;
        if let Some(c) = p.color {
            write!(w, "[{},{},{}]", c[0], c[1], c[2])?
        } else {
            write!(w, "null")?
        }
        write!(w, "}}")?;
    }
    write!(w, "]}},\"candidates\":[")?;
    for (i, c) in s.candidates.iter().enumerate() {
        if i != 0 {
            write!(w, ",")?
        }
        write!(
            w,
            "{{\"actor_index\":{},\"address\":{},\"helper\":{},\"helper_bound\":{},\"model_bound\":{},\"foreign_human_link\":{},\"native_id\":{},\"flags\":{},\"human_slot\":",
            c.actor_index,
            c.address,
            c.helper,
            c.helper_bound,
            c.model_bound,
            c.foreign_human_link,
            c.native_id,
            c.flags
        )?;
        if let Some(slot) = c.human_slot {
            write!(w, "{slot}")?
        } else {
            write!(w, "null")?
        }
        write!(w, "}}")?;
    }
    write!(w, "],\"views\":[")?;
    for (i, v) in s.views.iter().enumerate() {
        if i != 0 {
            write!(w, ",")?
        }
        write!(
            w,
            "{{\"owner\":{},\"primary\":{},\"secondary\":{},\"player_camera_slot\":",
            v.owner, v.primary, v.secondary
        )?;
        if let CameraSource::Player(slot) = v.source {
            write!(w, "{slot}")?
        } else {
            write!(w, "null")?
        }
        write!(w, "}}")?;
    }
    write!(
        w,
        "],\"native_takeover_ready\":{},\"blockers\":[",
        readiness.native_takeover_ready()
    )?;
    for (i, b) in readiness.blockers.iter().enumerate() {
        if i != 0 {
            write!(w, ",")?
        }
        write!(w, "\"{}\"", b.code())?;
    }
    writeln!(w, "]}}")
}

#[cfg(test)]
mod tests {
    use super::*;
    use acz_coop_game::NativePlayer;
    #[test]
    fn wingman_evidence_is_labeled_post_update_with_explicit_unfinished_control_gates() {
        use acz_coop_wingman::{EventSnapshot, Selection, SelectionSnapshot};
        let s = WingmanSnapshot {
            generation: 1,
            sample: 42,
            mode: 1,
            world: 2,
            campaign: true,
            player_count: 1,
            player_selectors: vec![[0, 0]],
            world_flags: 0,
            world_phase: 1,
            camera_mode: 0,
            group: 3,
            group_category: 0,
            control_definition: 0,
            helper_count: 0,
            candidates: vec![],
            views: vec![],
            event: Some(EventSnapshot {
                controller: 4,
                flags: 0x40,
                index: 1,
                substate: 2,
                kind: None,
            }),
            selection: SelectionSnapshot {
                alternate_profile: false,
                slots: [Selection {
                    aircraft: 0,
                    weapon: 1,
                    option: 2,
                    color: None,
                }; 2],
            },
        };
        let mut out = Vec::new();
        write_record(&mut out, &Record::Wingman(s)).unwrap();
        let text = String::from_utf8(out).unwrap();
        assert_eq!(text.lines().count(), 1);
        assert!(text.contains("\"type\":\"wingman_post_update\""));
        assert!(text.contains("\"sample\":42"));
        assert!(text.contains("\"kind\":null"));
        assert!(text.contains("\"native_takeover_ready\":false"));
        assert!(text.contains("\"ai_exclusion_unimplemented\""));
        assert!(text.contains("\"event_policy_unverified\""));
    }
    #[test]
    fn queue_capacity_never_blocks_and_reports_drops() {
        let (tx, drain) = channel(1).unwrap();
        assert!(tx.try_record(Record::Status {
            code: Status::Boot,
            detail: 0
        }));
        for _ in 0..1000 {
            assert!(!tx.try_record(Record::Status {
                code: Status::Boot,
                detail: 0
            }));
        }
        assert_eq!(tx.metrics().dropped, 1000);
        drop(drain);
        assert!(!tx.try_record(Record::Status {
            code: Status::Stopped,
            detail: 0
        }));
        assert_eq!(tx.metrics().closed, 1);
    }
    #[test]
    fn drain_writes_provenance_record_and_summary() {
        let (tx, drain) = channel(2).unwrap();
        tx.try_record(Record::Native(NativeFrame {
            generation: 1,
            sample: 1,
            thread: 7,
            mode: 16,
            world: 32,
            ready: true,
            setup: 18,
            tick: Some(42),
            phase: Some(1),
            players: vec![NativePlayer {
                slot: 0,
                group: 0,
                actor: 0,
                native_id: 7,
                context_position: [0.; 4],
                position: [1., 2., 3., 1.],
                orientation_like: [0., 1., 2., 0.],
                hp: 100,
                flags: 1,
            }],
        }));
        let mut out = Vec::new();
        drain.run(&mut out, &AtomicBool::new(true)).unwrap();
        let s = String::from_utf8(out).unwrap();
        assert_eq!(s.lines().count(), 3);
        assert!(s.contains("\"native_tick\":42"));
        assert!(s.contains("\"hp\":100"));
        assert!(s.contains("\"native_orientation_like\""));
        assert!(!tx.metrics().io_failed);
    }
    #[test]
    fn io_failure_is_visible_to_producers() {
        struct Fail;
        impl Write for Fail {
            fn write(&mut self, _: &[u8]) -> io::Result<usize> {
                Err(io::Error::new(io::ErrorKind::StorageFull, "test full disk"))
            }
            fn flush(&mut self) -> io::Result<()> {
                Ok(())
            }
        }
        let (tx, drain) = channel(1).unwrap();
        assert!(drain.run(&mut Fail, &AtomicBool::new(true)).is_err());
        assert!(tx.metrics().io_failed);
        assert!(!tx.try_record(Record::Status {
            code: Status::Boot,
            detail: 0
        }));
    }
    #[test]
    fn idle_writer_publishes_last_lifecycle_record_before_shutdown() {
        use std::sync::Mutex;
        use std::time::Instant;
        struct Probe(Arc<Mutex<Vec<u8>>>);
        impl Write for Probe {
            fn write(&mut self, b: &[u8]) -> io::Result<usize> {
                self.0.lock().unwrap().extend_from_slice(b);
                Ok(b.len())
            }
            fn flush(&mut self) -> io::Result<()> {
                Ok(())
            }
        }
        let (tx, drain) = channel(8).unwrap();
        let bytes = Arc::new(Mutex::new(Vec::new()));
        let output = bytes.clone();
        let stop = Arc::new(AtomicBool::new(false));
        let stopping = stop.clone();
        let thread = std::thread::spawn(move || {
            drain.run(
                &mut std::io::BufWriter::with_capacity(8192, Probe(output)),
                &stopping,
            )
        });
        tx.try_record(Record::Status {
            code: Status::WorldLeft,
            detail: 1,
        });
        let deadline = Instant::now() + Duration::from_secs(2);
        let visible = loop {
            if String::from_utf8_lossy(&bytes.lock().unwrap()).contains("world_left") {
                break true;
            }
            if Instant::now() >= deadline {
                break false;
            }
            std::thread::sleep(Duration::from_millis(1));
        };
        stop.store(true, Ordering::Release);
        drop(tx);
        thread.join().unwrap().unwrap();
        assert!(
            visible,
            "lifecycle tail was not visible while writer was still running"
        );
    }
    #[test]
    fn invalid_capacity_is_rejected() {
        assert!(channel(0).is_err());
        assert!(channel(65537).is_err());
    }
}

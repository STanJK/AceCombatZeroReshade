//! Composition root and explicit MODEL-only network scenarios, never a game simulator claim.
#![forbid(unsafe_code)]
use acz_coop_contracts::*;
use acz_coop_game::VerifiedImage;
use acz_coop_protocol::{Acknowledgement, Change, Event, Message, Packet};
use acz_coop_replication::{Assembler, WorldState, split_snapshot};
use acz_coop_session::{InputGate, InputLimits, Phase, Session};
use acz_coop_transport::{AuthenticatedStream, Psk};
use std::{
    fs, io,
    net::TcpListener,
    path::{Path, PathBuf},
    process::{Child, Command, Stdio},
    time::{Duration, Instant, SystemTime, UNIX_EPOCH},
};
pub type AnyResult<T> = std::result::Result<T, Box<dyn std::error::Error + Send + Sync>>;
fn require(ok: bool, label: &'static str) -> AnyResult<()> {
    if ok {
        Ok(())
    } else {
        Err(io::Error::new(io::ErrorKind::InvalidData, label).into())
    }
}
pub fn agreement() -> Agreement {
    Agreement {
        build: TARGET_SHA256,
        patch: PATCH_COMPATIBILITY,
        content: [0x42; 32],
        mission: 1,
        difficulty: 2,
    }
}
fn pose(n: u32, epoch: Epoch) -> Pose {
    Pose {
        id: EntityId::new(epoch, n).expect("nonzero bounded model serial"),
        position: [n as f32, 0., 0.],
        orientation: [0., 0., 0., 1.],
        velocity: [0.; 3],
        flags: 0,
    }
}
fn ack(
    stream: &mut AuthenticatedStream,
    world: &WorldState,
    snapshot: u32,
    tick: u32,
) -> AnyResult<()> {
    stream.send(
        world.epoch(),
        tick,
        Message::Ack(Acknowledgement {
            event: world.last_event(),
            snapshot,
            state_hash: world.digest(),
        }),
    )?;
    Ok(())
}
fn check_ack(stream: &mut AuthenticatedStream, world: &WorldState, snapshot: u32) -> AnyResult<()> {
    let p = stream.receive()?;
    require(p.epoch == world.epoch(), "ack epoch")?;
    require(
        p.message
            == Message::Ack(Acknowledgement {
                event: world.last_event(),
                snapshot,
                state_hash: world.digest(),
            }),
        "peer world digest/event/snapshot mismatch",
    )
}
fn expect(stream: &mut AuthenticatedStream, epoch: Epoch, message: Message) -> AnyResult<Packet> {
    let p = stream.receive()?;
    require(
        p.epoch == epoch && p.message == message,
        "unexpected session message",
    )?;
    Ok(p)
}
#[derive(Debug)]
pub struct ModelReport {
    pub epoch: u32,
    pub entities_after_retry: usize,
    pub host_save_permits: u8,
    pub guest_save_permits: u8,
}
impl ModelReport {
    pub fn json(&self) -> String {
        format!(
            "{{\"result\":\"PASS\",\"scope\":\"model\",\"transport\":\"authenticated_tcp\",\"native_gameplay\":false,\"epoch\":{},\"entities_after_retry\":{},\"host_save_permits\":{},\"guest_save_permits\":{},\"digest_checks\":4,\"input_duplicate_rejected\":true,\"damage_duplicate_rejected\":true,\"old_epoch_rejected\":true}}",
            self.epoch, self.entities_after_retry, self.host_save_permits, self.guest_save_permits
        )
    }
}

pub fn model_host(mut stream: AuthenticatedStream) -> AnyResult<ModelReport> {
    let mut session = Session::new(Role::Host);
    let e = session.host_prepare(agreement())?;
    let mut world = WorldState::new(e);
    stream.send(e, 0, Message::Prepare(agreement()))?;
    session.local_ready()?;
    expect(&mut stream, e, Message::Ready)?;
    session.receive_guest_ready(e)?;
    session.host_start()?;
    stream.send(e, 0, Message::Start)?;
    let mut inputs = InputGate::new(e, 0, InputLimits::default())?;
    let p = stream.receive()?;
    let Message::Input(sample) = p.message else {
        return Err(Error::Invalid("model input").into());
    };
    inputs.submit(stream.peer_role(), p.epoch, p.tick, sample)?;
    let f = inputs.consume(0)?;
    require(f.pilots[1].pressed == 1, "model input edge")?;
    let repeated = stream.receive()?;
    let Message::Input(again) = repeated.message else {
        return Err(Error::Invalid("duplicate input").into());
    };
    require(
        inputs.submit(stream.peer_role(), repeated.epoch, repeated.tick, again)
            == Err(Error::Duplicate),
        "input duplicate accepted",
    )?;
    require(
        inputs.consume(1)?.pilots[1].pressed == 0,
        "input edge repeated",
    )?;
    for n in 1..=21 {
        let event = Event {
            id: n as u64,
            change: Change::Spawn {
                definition: n,
                pose: pose(n, e),
                hp: 100,
            },
        };
        world.apply_event(Role::Host, e, &event)?;
        stream.send(e, 0, Message::Event(event))?;
    }
    let mut poses: Vec<_> = world.entities().values().map(|v| v.pose).collect();
    poses[1].position[0] += f.pilots[1].held.axes[0] as f32 / 32767.0;
    let chunks = split_snapshot(e, 1, &poses)?;
    let mut local = Assembler::new(e);
    for chunk in chunks.into_iter().rev() {
        if let Some(s) = local.push(e, 1, chunk.clone())? {
            world.apply_snapshot(Role::Host, &s)?;
        }
        stream.send(e, 1, Message::Snapshot(chunk))?;
    }
    check_ack(&mut stream, &world, 1)?;
    let damage = Event {
        id: 22,
        change: Change::Damage {
            target: pose(2, e).id,
            attacker: Some(pose(1, e).id),
            hp: 75,
            score: 100,
        },
    };
    world.apply_event(Role::Host, e, &damage)?;
    stream.send(e, 2, Message::Event(damage.clone()))?;
    stream.send(e, 2, Message::Event(damage.clone()))?;
    check_ack(&mut stream, &world, 1)?;
    let result = Event {
        id: 23,
        change: Change::Result {
            verdict: Verdict::Success,
            score: 100,
        },
    };
    world.apply_event(Role::Host, e, &result)?;
    session.host_finish(Verdict::Success)?;
    stream.send(e, 3, Message::Event(result))?;
    check_ack(&mut stream, &world, 1)?;
    let permit = session.take_save_permit()?;
    require(permit.epoch() == e, "save epoch")?;
    require(
        matches!(session.take_save_permit(), Err(Error::Duplicate)),
        "duplicate save permit",
    )?;
    let next = session.host_prepare(agreement())?;
    world.reset(next)?;
    inputs.reset(next, 0)?;
    session.local_ready()?;
    stream.send(next, 0, Message::Prepare(agreement()))?;
    expect(&mut stream, next, Message::Ready)?;
    session.receive_guest_ready(next)?;
    stream.send(e, 2, Message::Event(damage))?;
    stream.send(
        e,
        1,
        Message::Snapshot(split_snapshot(e, 2, &[pose(1, e)])?.remove(0)),
    )?;
    session.host_start()?;
    stream.send(next, 0, Message::Start)?;
    check_ack(&mut stream, &world, 0)?;
    require(
        inputs.consume(0)?.pilots[1].held == Controls::default(),
        "retry retained input",
    )?;
    require(session.phase() == Phase::Playing, "retry state")?;
    Ok(ModelReport {
        epoch: next.get(),
        entities_after_retry: world.entities().len(),
        host_save_permits: 1,
        guest_save_permits: 0,
    })
}

pub fn model_guest(mut stream: AuthenticatedStream) -> AnyResult<()> {
    let mut session = Session::new(Role::Guest);
    let p = stream.receive()?;
    let Message::Prepare(remote) = p.message else {
        return Err(Error::Phase.into());
    };
    let e = p.epoch;
    session.guest_prepare(e, remote, agreement())?;
    session.local_ready()?;
    stream.send(e, 0, Message::Ready)?;
    expect(&mut stream, e, Message::Start)?;
    session.guest_start(e)?;
    let input = Message::Input(InputSample {
        sequence: 1,
        slot: Slot::Guest,
        controls: Controls {
            axes: [1234, 0, 0, 0],
            buttons: 1,
            triggers: [77, 0],
        },
    });
    stream.send(e, 0, input.clone())?;
    stream.send(e, 0, input)?;
    let mut world = WorldState::new(e);
    let mut assembler = Assembler::new(e);
    for _ in 0..21 {
        let p = stream.receive()?;
        let Message::Event(event) = p.message else {
            return Err(Error::Invalid("model spawn").into());
        };
        world.apply_event(stream.peer_role(), p.epoch, &event)?;
    }
    for i in 0..2 {
        let p = stream.receive()?;
        let Message::Snapshot(chunk) = p.message else {
            return Err(Error::Invalid("model snapshot").into());
        };
        let result = assembler.push(p.epoch, p.tick, chunk)?;
        if i == 0 {
            require(result.is_none(), "partial snapshot exposed")?;
        } else {
            world.apply_snapshot(stream.peer_role(), &result.ok_or(Error::Gap)?)?;
        }
    }
    ack(&mut stream, &world, 1, 1)?;
    let damage = stream.receive()?;
    let Message::Event(event) = damage.message else {
        return Err(Error::Invalid("model damage").into());
    };
    world.apply_event(stream.peer_role(), damage.epoch, &event)?;
    let duplicate = stream.receive()?;
    let Message::Event(event) = duplicate.message else {
        return Err(Error::Invalid("duplicate damage").into());
    };
    require(
        world.apply_event(stream.peer_role(), duplicate.epoch, &event) == Err(Error::Duplicate),
        "duplicate damage accepted",
    )?;
    require(
        world.entities()[&pose(2, e).id].hp == 75 && world.score() == 100,
        "duplicate changed outcome",
    )?;
    ack(&mut stream, &world, 1, 2)?;
    let p = stream.receive()?;
    let Message::Event(event) = p.message else {
        return Err(Error::Invalid("model result").into());
    };
    world.apply_event(stream.peer_role(), p.epoch, &event)?;
    session.guest_follow_result(p.epoch, Verdict::Success)?;
    require(
        matches!(session.take_save_permit(), Err(Error::Authority)),
        "guest got save permit",
    )?;
    ack(&mut stream, &world, 1, 3)?;
    let p = stream.receive()?;
    let Message::Prepare(remote) = p.message else {
        return Err(Error::Phase.into());
    };
    let next = p.epoch;
    session.guest_prepare(next, remote, agreement())?;
    world.reset(next)?;
    assembler.reset(next)?;
    session.local_ready()?;
    stream.send(next, 0, Message::Ready)?;
    let old = stream.receive()?;
    let Message::Event(event) = old.message else {
        return Err(Error::Invalid("old epoch event").into());
    };
    require(
        world.apply_event(stream.peer_role(), old.epoch, &event) == Err(Error::Epoch),
        "old event accepted",
    )?;
    let old = stream.receive()?;
    let Message::Snapshot(chunk) = old.message else {
        return Err(Error::Invalid("old epoch snapshot").into());
    };
    require(
        assembler.push(old.epoch, old.tick, chunk) == Err(Error::Epoch),
        "old snapshot accepted",
    )?;
    expect(&mut stream, next, Message::Start)?;
    session.guest_start(next)?;
    require(world.entities().is_empty(), "retry retained entities")?;
    ack(&mut stream, &world, 0, 0)
}

struct TempKey(PathBuf);
impl Drop for TempKey {
    fn drop(&mut self) {
        let _ = fs::remove_file(&self.0);
    }
}
fn wait_child(child: &mut Child, until: Instant) -> io::Result<()> {
    loop {
        if child.try_wait()?.is_some() {
            return Ok(());
        }
        if Instant::now() >= until {
            let _ = child.kill();
            let _ = child.wait();
            return Err(io::Error::new(
                io::ErrorKind::TimedOut,
                "model child deadline",
            ));
        }
        std::thread::sleep(Duration::from_millis(5));
    }
}
pub fn demo() -> AnyResult<ModelReport> {
    let stamp = SystemTime::now().duration_since(UNIX_EPOCH)?.as_nanos();
    let key_file = TempKey(
        std::env::temp_dir().join(format!("acz-coop-model-{}-{stamp}.key", std::process::id())),
    );
    let key = Psk::create_file(&key_file.0)?;
    let listener = TcpListener::bind("127.0.0.1:0")?;
    let addr = listener.local_addr()?;
    listener.set_nonblocking(true)?;
    let mut child = Command::new(std::env::current_exe()?)
        .arg("guest-model")
        .arg(addr.to_string())
        .arg(&key_file.0)
        .stdout(Stdio::piped())
        .stderr(Stdio::piped())
        .spawn()?;
    let result = (|| {
        let until = Instant::now() + Duration::from_secs(10);
        let socket = loop {
            match listener.accept() {
                Ok((s, _)) => break s,
                Err(e) if e.kind() == io::ErrorKind::WouldBlock => {
                    if Instant::now() >= until || child.try_wait()?.is_some() {
                        return Err(io::Error::new(
                            io::ErrorKind::TimedOut,
                            "model guest did not connect",
                        )
                        .into());
                    }
                    std::thread::sleep(Duration::from_millis(5));
                }
                Err(e) => return Err(e.into()),
            }
        };
        let stream = AuthenticatedStream::accept_host(socket, &key, Duration::from_secs(5))?;
        let report = model_host(stream)?;
        wait_child(&mut child, Instant::now() + Duration::from_secs(5))?;
        Ok(report)
    })();
    if result.is_err() {
        let _ = child.kill();
    }
    let output = child.wait_with_output()?;
    if !output.status.success() {
        return Err(io::Error::other(format!(
            "model guest failed: {}",
            String::from_utf8_lossy(&output.stderr)
        ))
        .into());
    }
    result
}
pub fn doctor(path: &Path) -> AnyResult<String> {
    let bytes = fs::read(path)?;
    let image = VerifiedImage::from_pe(&bytes, 0x140000000)?;
    Ok(format!(
        "{{\"result\":\"PASS\",\"scope\":\"static-build-check\",\"bytes\":{},\"image_size\":{},\"observer_candidates\":{},\"native_writes\":false,\"gameplay_executed\":false}}",
        bytes.len(),
        image.size(),
        acz_coop_game::HOOKS.len()
    ))
}
#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn digest_covers_outcomes_and_reset() {
        // The actual two-process test exercises successful hashes; this checks the world digest changes with outcomes.
        let e = Epoch::FIRST;
        let mut w = WorldState::new(e);
        let before = w.digest();
        w.apply_event(
            Role::Host,
            e,
            &Event {
                id: 1,
                change: Change::Spawn {
                    definition: 1,
                    pose: pose(1, e),
                    hp: 100,
                },
            },
        )
        .unwrap();
        assert_ne!(before, w.digest());
        w.reset(e.next().unwrap()).unwrap();
        assert_eq!(w.digest(), WorldState::new(e.next().unwrap()).digest());
    }
    #[test]
    fn altered_peer_digest_is_rejected_over_authenticated_tcp() {
        let listener = TcpListener::bind("127.0.0.1:0").unwrap();
        let addr = listener.local_addr().unwrap();
        let key = Psk::from_bytes([7; 32]).unwrap();
        let server_key = key.clone();
        let thread = std::thread::spawn(move || {
            AuthenticatedStream::accept_host(
                listener.accept().unwrap().0,
                &server_key,
                Duration::from_secs(2),
            )
            .unwrap()
        });
        let mut guest = AuthenticatedStream::connect_guest(
            std::net::TcpStream::connect(addr).unwrap(),
            &key,
            Duration::from_secs(2),
        )
        .unwrap();
        let mut host = thread.join().unwrap();
        let world = WorldState::new(Epoch::FIRST);
        guest
            .send(
                Epoch::FIRST,
                0,
                Message::Ack(Acknowledgement {
                    event: 0,
                    snapshot: 0,
                    state_hash: [0; 32],
                }),
            )
            .unwrap();
        assert!(check_ack(&mut host, &world, 0).is_err());
    }
    #[test]
    fn wrong_exe_never_reports_compatible() {
        let path = std::env::temp_dir().join(format!("acz-wrong-exe-{}", std::process::id()));
        fs::write(&path, b"wrong binary").unwrap();
        assert!(doctor(&path).is_err());
        fs::remove_file(path).unwrap();
    }
}

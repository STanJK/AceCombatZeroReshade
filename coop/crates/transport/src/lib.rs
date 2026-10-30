//! Authenticated, bounded direct-IP TCP prototype. Integrity/authentication, not encryption.
#![forbid(unsafe_code)]
use acz_coop_contracts::{Epoch, MAX_DATAGRAM, Role};
use acz_coop_protocol::{Message, Packet};
use hmac::{Hmac, Mac};
use sha2::Sha256;
use std::fs::{self, OpenOptions};
use std::io::{self, Read, Write};
use std::net::{Shutdown, TcpStream};
use std::path::Path;
use std::time::{Duration, Instant};
type Hmac256 = Hmac<Sha256>;
fn invalid(s: &'static str) -> io::Error {
    io::Error::new(io::ErrorKind::InvalidData, s)
}
fn denied() -> io::Error {
    io::Error::new(
        io::ErrorKind::PermissionDenied,
        "peer authentication failed",
    )
}
fn core_error(e: acz_coop_contracts::Error) -> io::Error {
    io::Error::new(io::ErrorKind::InvalidData, e)
}

#[derive(Clone)]
pub struct Psk([u8; 32]);
impl Psk {
    pub fn from_bytes(bytes: [u8; 32]) -> io::Result<Self> {
        if bytes == [0; 32] {
            Err(invalid("zero key"))
        } else {
            Ok(Self(bytes))
        }
    }
    pub fn generate() -> io::Result<Self> {
        let mut b = [0; 32];
        getrandom::getrandom(&mut b).map_err(|e| io::Error::other(e.to_string()))?;
        Self::from_bytes(b)
    }
    pub fn create_file(path: &Path) -> io::Result<Self> {
        let key = Self::generate()?;
        let mut options = OpenOptions::new();
        options.write(true).create_new(true);
        #[cfg(unix)]
        {
            use std::os::unix::fs::OpenOptionsExt;
            options.mode(0o600);
        }
        let mut file = options.open(path)?;
        let text: String = key.0.iter().map(|v| format!("{v:02x}")).collect();
        file.write_all(text.as_bytes())?;
        file.write_all(b"\n")?;
        file.sync_all()?;
        Ok(key)
    }
    pub fn read_file(path: &Path) -> io::Result<Self> {
        let mut b = Vec::new();
        fs::File::open(path)?.take(67).read_to_end(&mut b)?;
        if b.len() > 66 {
            return Err(invalid("key file length"));
        }
        let s = std::str::from_utf8(&b)
            .map_err(|_| invalid("key file encoding"))?
            .trim_end_matches(['\r', '\n']);
        if s.len() != 64 || !s.is_ascii() {
            return Err(invalid("expected 32-byte hexadecimal key"));
        }
        let mut key = [0; 32];
        for (i, v) in key.iter_mut().enumerate() {
            *v = u8::from_str_radix(&s[i * 2..i * 2 + 2], 16)
                .map_err(|_| invalid("key file hex"))?;
        }
        Self::from_bytes(key)
    }
}
fn mac(key: &[u8], parts: &[&[u8]]) -> Hmac256 {
    let mut h = Hmac256::new_from_slice(key).expect("HMAC accepts arbitrary key length");
    for p in parts {
        h.update(p);
    }
    h
}
fn tag(key: &[u8], parts: &[&[u8]]) -> [u8; 32] {
    mac(key, parts).finalize().into_bytes().into()
}
fn deadline(timeout: Duration) -> io::Result<Instant> {
    if timeout.is_zero() || timeout > Duration::from_secs(30) {
        return Err(invalid("timeout must be >0 and <=30 seconds"));
    }
    Instant::now()
        .checked_add(timeout)
        .ok_or_else(|| invalid("deadline overflow"))
}
fn remaining(until: Instant) -> io::Result<Duration> {
    until
        .checked_duration_since(Instant::now())
        .filter(|v| !v.is_zero())
        .ok_or_else(|| io::Error::new(io::ErrorKind::TimedOut, "exchange deadline"))
}
fn read_exact_until(s: &mut TcpStream, mut b: &mut [u8], until: Instant) -> io::Result<()> {
    while !b.is_empty() {
        s.set_read_timeout(Some(remaining(until)?))?;
        match s.read(b) {
            Ok(0) => return Err(io::ErrorKind::UnexpectedEof.into()),
            Ok(n) => {
                b = &mut b[n..];
            }
            Err(e) if e.kind() == io::ErrorKind::Interrupted => (),
            Err(e) => return Err(e),
        }
    }
    Ok(())
}
fn write_all_until(s: &mut TcpStream, mut b: &[u8], until: Instant) -> io::Result<()> {
    while !b.is_empty() {
        s.set_write_timeout(Some(remaining(until)?))?;
        match s.write(b) {
            Ok(0) => return Err(io::ErrorKind::WriteZero.into()),
            Ok(n) => b = &b[n..],
            Err(e) if e.kind() == io::ErrorKind::Interrupted => (),
            Err(e) => return Err(e),
        }
    }
    Ok(())
}
fn hello(role: Role, session: [u8; 16]) -> io::Result<[u8; 64]> {
    let mut b = [0; 64];
    b[..4].copy_from_slice(b"ACZH");
    b[4..6].copy_from_slice(&1u16.to_le_bytes());
    b[6] = role as u8;
    b[8..24].copy_from_slice(&session);
    getrandom::getrandom(&mut b[24..56]).map_err(|e| io::Error::other(e.to_string()))?;
    Ok(b)
}
fn check_hello(b: &[u8; 64], role: Role, session: &[u8; 16]) -> io::Result<()> {
    if &b[..4] != b"ACZH"
        || b[4..6] != [1, 0]
        || b[6] != role as u8
        || b[7] != 0
        || &b[8..24] != session
        || b[56..] != [0; 8]
        || b[24..56] == [0; 32]
    {
        return Err(denied());
    }
    Ok(())
}

pub struct AuthenticatedStream {
    stream: TcpStream,
    session: [u8; 16],
    key: [u8; 32],
    role: Role,
    timeout: Duration,
    tx: u64,
    rx: u64,
    poisoned: bool,
}
impl AuthenticatedStream {
    pub fn accept_host(mut stream: TcpStream, psk: &Psk, timeout: Duration) -> io::Result<Self> {
        let result = (|| {
            let until = deadline(timeout)?;
            // Windows accept may inherit nonblocking mode from the listener. This owned
            // stream uses blocking I/O with a total deadline on every exchange.
            stream.set_nonblocking(false)?;
            stream.set_nodelay(true)?;
            let mut session = [0; 16];
            getrandom::getrandom(&mut session).map_err(|e| io::Error::other(e.to_string()))?;
            if session == [0; 16] {
                return Err(invalid("random session"));
            }
            let server = hello(Role::Host, session)?;
            write_all_until(&mut stream, &server, until)?;
            let mut client = [0; 64];
            read_exact_until(&mut stream, &mut client, until)?;
            check_hello(&client, Role::Guest, &session)?;
            if client[24..56] == server[24..56] {
                return Err(denied());
            }
            let mut proof = [0; 32];
            read_exact_until(&mut stream, &mut proof, until)?;
            mac(&psk.0, &[b"ACZ2-GUEST-v1", &server, &client])
                .verify_slice(&proof)
                .map_err(|_| denied())?;
            write_all_until(
                &mut stream,
                &tag(&psk.0, &[b"ACZ2-HOST-v1", &server, &client]),
                until,
            )?;
            Ok((
                session,
                tag(&psk.0, &[b"ACZ2-SESSION-v1", &server, &client]),
            ))
        })();
        match result {
            Ok((session, key)) => Ok(Self {
                stream,
                session,
                key,
                role: Role::Host,
                timeout,
                tx: 0,
                rx: 0,
                poisoned: false,
            }),
            Err(e) => {
                let _ = stream.shutdown(Shutdown::Both);
                Err(e)
            }
        }
    }
    pub fn connect_guest(mut stream: TcpStream, psk: &Psk, timeout: Duration) -> io::Result<Self> {
        let result = (|| {
            let until = deadline(timeout)?;
            stream.set_nonblocking(false)?;
            stream.set_nodelay(true)?;
            let mut server = [0; 64];
            read_exact_until(&mut stream, &mut server, until)?;
            let session = server[8..24].try_into().expect("fixed session field");
            if session == [0; 16] {
                return Err(denied());
            }
            check_hello(&server, Role::Host, &session)?;
            let client = hello(Role::Guest, session)?;
            write_all_until(&mut stream, &client, until)?;
            write_all_until(
                &mut stream,
                &tag(&psk.0, &[b"ACZ2-GUEST-v1", &server, &client]),
                until,
            )?;
            let mut proof = [0; 32];
            read_exact_until(&mut stream, &mut proof, until)?;
            mac(&psk.0, &[b"ACZ2-HOST-v1", &server, &client])
                .verify_slice(&proof)
                .map_err(|_| denied())?;
            Ok((
                session,
                tag(&psk.0, &[b"ACZ2-SESSION-v1", &server, &client]),
            ))
        })();
        match result {
            Ok((session, key)) => Ok(Self {
                stream,
                session,
                key,
                role: Role::Guest,
                timeout,
                tx: 0,
                rx: 0,
                poisoned: false,
            }),
            Err(e) => {
                let _ = stream.shutdown(Shutdown::Both);
                Err(e)
            }
        }
    }
    pub fn session_id(&self) -> [u8; 16] {
        self.session
    }
    pub fn peer_role(&self) -> Role {
        self.role.peer()
    }
    pub fn is_poisoned(&self) -> bool {
        self.poisoned
    }
    fn finish<T>(&mut self, result: io::Result<T>) -> io::Result<T> {
        if result.is_err() {
            self.poisoned = true;
            let _ = self.stream.shutdown(Shutdown::Both);
        }
        result
    }
    fn live(&self) -> io::Result<()> {
        if self.poisoned {
            Err(io::Error::new(
                io::ErrorKind::BrokenPipe,
                "exchange failed; reconnect",
            ))
        } else {
            Ok(())
        }
    }
    pub fn send(&mut self, epoch: Epoch, tick: u32, message: Message) -> io::Result<u32> {
        self.live()?;
        let result = (|| {
            if !message.allowed_sender(self.role) {
                return Err(denied());
            }
            if let Message::Input(i) = &message {
                if i.slot != self.role.slot() {
                    return Err(denied());
                }
            }
            let next = self
                .tx
                .checked_add(1)
                .ok_or_else(|| invalid("frame counter exhausted"))?;
            let packet = Packet {
                session: self.session,
                epoch,
                sequence: self.tx as u32,
                tick,
                message,
            }
            .encode()
            .map_err(core_error)?;
            let len = (packet.len() as u16).to_le_bytes();
            let counter = self.tx.to_le_bytes();
            let dir = [self.role as u8];
            let signature = tag(
                &self.key,
                &[b"ACZ2-FRAME-v1", &dir, &len, &counter, &packet],
            );
            let mut frame = Vec::with_capacity(10 + packet.len() + 32);
            frame.extend(len);
            frame.extend(counter);
            frame.extend(packet);
            frame.extend(signature);
            write_all_until(&mut self.stream, &frame, deadline(self.timeout)?)?;
            let seq = self.tx as u32;
            self.tx = next;
            Ok(seq)
        })();
        self.finish(result)
    }
    pub fn receive(&mut self) -> io::Result<Packet> {
        self.live()?;
        let result = (|| {
            let until = deadline(self.timeout)?;
            let mut len = [0; 2];
            read_exact_until(&mut self.stream, &mut len, until)?;
            let n = u16::from_le_bytes(len) as usize;
            if !(40..=MAX_DATAGRAM).contains(&n) {
                return Err(invalid("frame length"));
            }
            let mut counter = [0; 8];
            read_exact_until(&mut self.stream, &mut counter, until)?;
            if u64::from_le_bytes(counter) != self.rx {
                return Err(invalid("frame sequence"));
            }
            let mut body = vec![0; n];
            read_exact_until(&mut self.stream, &mut body, until)?;
            let mut signature = [0; 32];
            read_exact_until(&mut self.stream, &mut signature, until)?;
            mac(
                &self.key,
                &[
                    b"ACZ2-FRAME-v1",
                    &[self.role.peer() as u8],
                    &len,
                    &counter,
                    &body,
                ],
            )
            .verify_slice(&signature)
            .map_err(|_| denied())?;
            let p = Packet::decode(&body).map_err(core_error)?;
            if p.session != self.session
                || p.sequence != self.rx as u32
                || !p.message.allowed_sender(self.role.peer())
            {
                return Err(denied());
            }
            if let Message::Input(i) = &p.message {
                if i.slot != self.role.peer().slot() {
                    return Err(denied());
                }
            }
            self.rx = self
                .rx
                .checked_add(1)
                .ok_or_else(|| invalid("frame counter exhausted"))?;
            Ok(p)
        })();
        self.finish(result)
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::net::TcpListener;
    use std::thread;
    fn key(v: u8) -> Psk {
        Psk::from_bytes([v; 32]).unwrap()
    }
    fn pair() -> (AuthenticatedStream, AuthenticatedStream) {
        let listener = TcpListener::bind("127.0.0.1:0").unwrap();
        let addr = listener.local_addr().unwrap();
        let worker = thread::spawn(move || {
            AuthenticatedStream::accept_host(
                listener.accept().unwrap().0,
                &key(7),
                Duration::from_secs(2),
            )
            .unwrap()
        });
        let guest = AuthenticatedStream::connect_guest(
            TcpStream::connect(addr).unwrap(),
            &key(7),
            Duration::from_secs(2),
        )
        .unwrap();
        (worker.join().unwrap(), guest)
    }
    #[test]
    fn authenticated_loopback_both_directions() {
        let (mut h, mut g) = pair();
        assert_eq!(h.session_id(), g.session_id());
        assert_eq!(h.peer_role(), Role::Guest);
        h.send(Epoch::FIRST, 0, Message::Start).unwrap();
        assert_eq!(g.receive().unwrap().message, Message::Start);
        g.send(Epoch::FIRST, 0, Message::Ready).unwrap();
        assert_eq!(h.receive().unwrap().message, Message::Ready);
    }
    #[test]
    fn owned_nonblocking_sockets_are_normalized_before_handshake() {
        let listener = TcpListener::bind("127.0.0.1:0").unwrap();
        let addr = listener.local_addr().unwrap();
        let worker = thread::spawn(move || {
            let socket = listener.accept().unwrap().0;
            socket.set_nonblocking(true).unwrap();
            let mut host =
                AuthenticatedStream::accept_host(socket, &key(7), Duration::from_secs(2)).unwrap();
            assert_eq!(host.receive().unwrap().message, Message::Ready);
            host.send(Epoch::FIRST, 0, Message::Start).unwrap();
        });
        let socket = TcpStream::connect(addr).unwrap();
        socket.set_nonblocking(true).unwrap();
        let mut guest =
            AuthenticatedStream::connect_guest(socket, &key(7), Duration::from_secs(2)).unwrap();
        guest.send(Epoch::FIRST, 0, Message::Ready).unwrap();
        assert_eq!(guest.receive().unwrap().message, Message::Start);
        worker.join().unwrap();
    }
    #[test]
    fn wrong_key_fails_both_peers() {
        let listener = TcpListener::bind("127.0.0.1:0").unwrap();
        let addr = listener.local_addr().unwrap();
        let worker = thread::spawn(move || {
            AuthenticatedStream::accept_host(
                listener.accept().unwrap().0,
                &key(1),
                Duration::from_secs(2),
            )
            .is_err()
        });
        assert!(
            AuthenticatedStream::connect_guest(
                TcpStream::connect(addr).unwrap(),
                &key(2),
                Duration::from_secs(2)
            )
            .is_err()
        );
        assert!(worker.join().unwrap());
    }
    #[test]
    fn corrupt_mac_never_returns_a_packet_and_poisons_connection() {
        let (mut h, mut g) = pair();
        let p = Packet {
            session: g.session,
            epoch: Epoch::FIRST,
            sequence: 0,
            tick: 0,
            message: Message::Ready,
        }
        .encode()
        .unwrap();
        let mut frame = Vec::new();
        frame.extend((p.len() as u16).to_le_bytes());
        frame.extend(0u64.to_le_bytes());
        frame.extend(p);
        frame.extend([0; 32]);
        g.stream.write_all(&frame).unwrap();
        assert!(h.receive().is_err());
        assert!(h.is_poisoned());
        assert_eq!(h.receive().unwrap_err().kind(), io::ErrorKind::BrokenPipe);
    }
    #[test]
    fn oversized_and_truncated_frames_are_closed() {
        for oversized in [true, false] {
            let (mut h, mut g) = pair();
            if oversized {
                g.stream.write_all(&1201u16.to_le_bytes()).unwrap();
            } else {
                g.stream.write_all(&40u16.to_le_bytes()).unwrap();
                g.stream.shutdown(Shutdown::Both).unwrap();
            }
            assert!(h.receive().is_err());
            assert!(h.is_poisoned());
        }
    }
    #[test]
    fn authenticated_identity_cannot_send_host_events_as_guest() {
        let (_h, mut g) = pair();
        assert!(g.send(Epoch::FIRST, 0, Message::Start).is_err());
        assert!(g.is_poisoned());
    }
    #[test]
    fn key_file_is_bounded_and_rejects_unicode_without_panicking() {
        let path = std::env::temp_dir().join(format!("acz-key-invalid-{}", std::process::id()));
        for bad in ["é".repeat(32), "a".repeat(67), "0".repeat(64)] {
            std::fs::write(&path, bad).unwrap();
            assert!(Psk::read_file(&path).is_err());
        }
        std::fs::remove_file(path).unwrap();
    }
    #[test]
    fn timeout_is_total_and_session_is_not_reusable() {
        let (mut h, _g) = pair();
        h.timeout = Duration::from_millis(100);
        let began = Instant::now();
        assert!(h.receive().is_err());
        assert!(began.elapsed() < Duration::from_secs(2));
        assert!(h.is_poisoned());
    }
}

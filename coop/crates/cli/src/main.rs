#![forbid(unsafe_code)]
use acz_coop_cli::{AnyResult, demo, doctor, model_guest, model_host};
use acz_coop_transport::{AuthenticatedStream, Psk};
use std::{
    net::{TcpListener, TcpStream},
    path::Path,
    time::Duration,
};
fn run() -> AnyResult<()> {
    let args: Vec<_> = std::env::args_os().skip(1).collect();
    let cmd = args.first().and_then(|s| s.to_str()).unwrap_or("help");
    match (cmd, args.len()) {
        ("help", _) | ("--help", _) => println!(
            "acz-coop doctor <acz.exe>\nacz-coop demo\nacz-coop keygen <new-key-file>\nacz-coop host-model <bind-address> <key-file>\nacz-coop guest-model <host-address> <key-file>\nMODEL commands test module/network contracts; they do not control the game."
        ),
        ("doctor", 2) => println!("{}", doctor(Path::new(&args[1]))?),
        ("demo", 1) => println!("{}", demo()?.json()),
        ("keygen", 2) => {
            Psk::create_file(Path::new(&args[1]))?;
            println!(
                "Key file created; keep its contents private. No existing file was overwritten."
            );
        }
        ("host-model", 3) => {
            let key = Psk::read_file(Path::new(&args[2]))?;
            let addr = args[1].to_str().ok_or("address encoding")?;
            let listener = TcpListener::bind(addr)?;
            println!("MODEL host listening on {}", listener.local_addr()?);
            let socket = listener.accept()?.0;
            println!(
                "{}",
                model_host(AuthenticatedStream::accept_host(
                    socket,
                    &key,
                    Duration::from_secs(5)
                )?)?
                .json()
            );
        }
        ("guest-model", 3) => {
            let key = Psk::read_file(Path::new(&args[2]))?;
            let addr = args[1].to_str().ok_or("address encoding")?;
            let socket = TcpStream::connect_timeout(&addr.parse()?, Duration::from_secs(5))?;
            model_guest(AuthenticatedStream::connect_guest(
                socket,
                &key,
                Duration::from_secs(5),
            )?)?;
            println!("{{\"result\":\"PASS\",\"scope\":\"guest-model\",\"native_gameplay\":false}}");
        }
        _ => return Err("invalid arguments; use --help".into()),
    }
    Ok(())
}
fn main() {
    if let Err(e) = run() {
        eprintln!("acz-coop: {e}");
        std::process::exit(1);
    }
}

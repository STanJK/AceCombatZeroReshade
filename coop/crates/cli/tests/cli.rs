use std::process::Command;
#[test]
fn two_process_authenticated_model_campaign_contract() {
    let out = Command::new(env!("CARGO_BIN_EXE_acz-coop"))
        .arg("demo")
        .output()
        .unwrap();
    assert!(
        out.status.success(),
        "{}",
        String::from_utf8_lossy(&out.stderr)
    );
    let s = String::from_utf8(out.stdout).unwrap();
    for field in [
        "\"scope\":\"model\"",
        "\"native_gameplay\":false",
        "\"epoch\":2",
        "\"entities_after_retry\":0",
        "\"guest_save_permits\":0",
    ] {
        assert!(s.contains(field), "{s}");
    }
}
#[test]
fn unknown_command_fails_and_help_does_not_launch_game() {
    assert!(
        !Command::new(env!("CARGO_BIN_EXE_acz-coop"))
            .arg("unknown")
            .output()
            .unwrap()
            .status
            .success()
    );
    assert!(
        Command::new(env!("CARGO_BIN_EXE_acz-coop"))
            .arg("--help")
            .output()
            .unwrap()
            .status
            .success()
    );
}

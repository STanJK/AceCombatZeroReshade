param(
    [ValidateSet('x86_64-pc-windows-msvc', 'x86_64-pc-windows-gnu', 'x86_64-pc-windows-gnullvm')]
    [string]$Target = 'x86_64-pc-windows-msvc'
)
$ErrorActionPreference = 'Stop'
$coop = Split-Path -Parent $PSScriptRoot
$flagName = 'CARGO_TARGET_' + $Target.ToUpperInvariant().Replace('-', '_') + '_RUSTFLAGS'
$previousFlags = [Environment]::GetEnvironmentVariable($flagName, 'Process')
if ($Target -ne 'x86_64-pc-windows-msvc') {
    [Environment]::SetEnvironmentVariable($flagName, ($previousFlags + ' -C target-feature=+crt-static').Trim(), 'Process')
}
Push-Location $coop
try {
    cargo fmt --all -- --check
    if ($LASTEXITCODE -ne 0) { throw 'fmt failed' }
    cargo test --workspace --locked
    if ($LASTEXITCODE -ne 0) { throw 'tests failed' }
    cargo clippy --workspace --all-targets --locked -- -D warnings
    if ($LASTEXITCODE -ne 0) { throw 'clippy failed' }
    cargo build --workspace --release --target $Target --locked
    if ($LASTEXITCODE -ne 0) { throw 'Windows build failed' }
    $release = Join-Path $coop "target\$Target\release"
    $stage = Join-Path $coop 'dist\ACZCoop-observer'
    New-Item -ItemType Directory -Force -Path $stage | Out-Null
    Copy-Item (Join-Path $release 'acz_coop_runtime.dll') (Join-Path $stage 'ACZCoop.addon64') -Force
    Copy-Item (Join-Path $release 'acz-coop.exe') $stage -Force
    Copy-Item (Join-Path $coop 'config\ACZCoop.ini') $stage -Force
    Copy-Item (Join-Path $coop 'README.md') $stage -Force
    Copy-Item (Join-Path $coop 'THIRD_PARTY_NOTICES.txt') $stage -Force
    Copy-Item (Join-Path $coop 'Cargo.lock') $stage -Force
    $files = Get-ChildItem $stage -File | Where-Object Name -ne 'manifest.json' | ForEach-Object {
        [ordered]@{ path = $_.Name; bytes = $_.Length; sha256 = (Get-FileHash $_.FullName -Algorithm SHA256).Hash.ToLowerInvariant() }
    }
    [ordered]@{ schema = 1; target = $Target; gameplay_validated = $false; native_writes = $false; files = @($files) } |
        ConvertTo-Json -Depth 6 | Set-Content (Join-Path $stage 'manifest.json') -Encoding utf8
    Write-Host "Staged: $stage"
    Write-Host 'No files were installed into a game directory.'
}
finally {
    [Environment]::SetEnvironmentVariable($flagName, $previousFlags, 'Process')
    Pop-Location
}

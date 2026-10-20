$ErrorActionPreference = "Stop"

cargo build --release
if ($LASTEXITCODE -ne 0) {
    throw "cargo build --release failed with exit code $LASTEXITCODE."
}

$src = Join-Path $PSScriptRoot "target\release\xinput1_4.dll"
if (-not (Test-Path $src)) {
    throw "Build returned success, but $src was not found."
}

Write-Host ""
Write-Host "Built: $src"
Write-Host "Copy xinput1_4.dll next to acz.exe."
Write-Host "Run the game, enter a mission, then press NUMPAD + once."
Write-Host "Read ACZRenderOracle.log next to acz.exe."

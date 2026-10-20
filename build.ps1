$ErrorActionPreference = "Stop"

cargo build --release

$src = Join-Path $PSScriptRoot "target\release\winmm.dll"
if (-not (Test-Path $src)) {
    throw "Build succeeded but $src was not found."
}

Write-Host ""
Write-Host "Built: $src"
Write-Host "Copy winmm.dll next to acz.exe."
Write-Host "Run the game, enter a mission, then press NUMPAD + once."
Write-Host "Read ACZRenderOracle.log next to acz.exe."

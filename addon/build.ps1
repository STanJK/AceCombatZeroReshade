$ErrorActionPreference = "Stop"

$root = Split-Path -Parent $PSScriptRoot
$deps = Join-Path $root ".deps"
$reshade = Join-Path $deps "reshade-6.8.0"
$include = Join-Path $reshade "include"
$outDir = Join-Path $PSScriptRoot "bin"
$source = Join-Path $PSScriptRoot "ACZCalibrate.cpp"
$output = Join-Path $outDir "ACZCalibrate.addon64"

New-Item -ItemType Directory -Force -Path $deps | Out-Null
New-Item -ItemType Directory -Force -Path $outDir | Out-Null

if (-not (Test-Path (Join-Path $include "reshade.hpp"))) {
    if (Test-Path $reshade) {
        Remove-Item -Recurse -Force $reshade
    }

    Write-Host "Fetching ReShade v6.8.0 headers..."
    git clone --depth 1 --branch v6.8.0 https://github.com/crosire/reshade.git $reshade
    if ($LASTEXITCODE -ne 0) {
        throw "git clone ReShade v6.8.0 failed with exit code $LASTEXITCODE."
    }
}

$programFilesX86 = [Environment]::GetFolderPath("ProgramFilesX86")
$vswhere = Join-Path $programFilesX86 "Microsoft Visual Studio\Installer\vswhere.exe"
if (-not (Test-Path $vswhere)) {
    throw "vswhere.exe not found. Install Visual Studio Build Tools with C++ x64 tools."
}

$vs = & $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
if (-not $vs) {
    throw "No Visual Studio installation with x64 C++ tools was found."
}

$vcvars = Join-Path $vs "VC\Auxiliary\Build\vcvars64.bat"
if (-not (Test-Path $vcvars)) {
    throw "vcvars64.bat not found at $vcvars"
}

$quotedSource = '"' + $source + '"'
$quotedInclude = '/I"' + $include + '"'
$quotedOutput = '/OUT:"' + $output + '"'
$pdb = '/PDB:"' + (Join-Path $outDir "ACZCalibrate.pdb") + '"'
$obj = '/Fo"' + (Join-Path $outDir "ACZCalibrate.obj") + '"'

$command = @(
    'call "' + $vcvars + '" >nul'
    'cl.exe /nologo /std:c++20 /O2 /EHsc /MD /LD /W4 /permissive- /DWIN32_LEAN_AND_MEAN /DNOMINMAX ' +
        $quotedInclude + ' ' + $obj + ' ' + $quotedSource +
        ' /link ' + $quotedOutput + ' ' + $pdb
) -join ' && '

Write-Host "Building ACZCalibrate.addon64..."
& $env:ComSpec /d /s /c $command
if ($LASTEXITCODE -ne 0) {
    throw "MSVC build failed with exit code $LASTEXITCODE."
}

if (-not (Test-Path $output)) {
    throw "Build returned success, but $output was not found."
}

Write-Host ""
Write-Host "Built: $output"
Write-Host "Copy ACZCalibrate.addon64 next to ReShade's d3d12.dll / acz.exe."
Write-Host "Keep the temporary xinput1_4.dll oracle installed for calibration."
Write-Host "Enter gameplay and press NUMPAD + once."
Write-Host "Read ACZCalibrate.log next to acz.exe."

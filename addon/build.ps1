param(
    [ValidateSet("All", "Calibrate", "Bridge")]
    [string]$Target = "All"
)

$ErrorActionPreference = "Stop"

$root = Split-Path -Parent $PSScriptRoot
$deps = Join-Path $root ".deps"
$reshade = Join-Path $deps "reshade-6.8.0"
$include = Join-Path $reshade "include"
$outDir = Join-Path $PSScriptRoot "bin"

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

function Build-Addon {
    param(
        [Parameter(Mandatory = $true)][string]$Name
    )

    $source = Join-Path $PSScriptRoot "$Name.cpp"
    $output = Join-Path $outDir "$Name.addon64"
    $obj = Join-Path $outDir "$Name.obj"
    $pdb = Join-Path $outDir "$Name.pdb"

    if (-not (Test-Path $source)) {
        throw "Source not found: $source"
    }

    $quotedSource = '"' + $source + '"'
    $quotedInclude = '/I"' + $include + '"'
    $quotedOutput = '/OUT:"' + $output + '"'
    $quotedPdb = '/PDB:"' + $pdb + '"'
    $quotedObj = '/Fo"' + $obj + '"'

    $command = @(
        'call "' + $vcvars + '" >nul'
        'cl.exe /nologo /std:c++20 /O2 /EHsc /MD /LD /W4 /permissive- /DWIN32_LEAN_AND_MEAN /DNOMINMAX ' +
            $quotedInclude + ' ' + $quotedObj + ' ' + $quotedSource +
            ' /link ' + $quotedOutput + ' ' + $quotedPdb
    ) -join ' && '

    Write-Host "Building $Name.addon64..."
    & $env:ComSpec /d /s /c $command
    if ($LASTEXITCODE -ne 0) {
        throw "$Name MSVC build failed with exit code $LASTEXITCODE."
    }

    if (-not (Test-Path $output)) {
        throw "Build returned success, but $output was not found."
    }

    Write-Host "Built: $output"
}

switch ($Target) {
    "Calibrate" {
        Build-Addon "ACZCalibrate"
    }
    "Bridge" {
        Build-Addon "ACZRenderBridge"
    }
    default {
        Build-Addon "ACZCalibrate"
        Build-Addon "ACZRenderBridge"
    }
}

Write-Host ""
if ($Target -eq "All" -or $Target -eq "Calibrate") {
    Write-Host "Calibration: addon\bin\ACZCalibrate.addon64"
}
if ($Target -eq "All" -or $Target -eq "Bridge") {
    Write-Host "Production:  addon\bin\ACZRenderBridge.addon64"
}
Write-Host ""
Write-Host "For SceneClean Phase 1 testing, install only ACZRenderBridge.addon64 next to acz.exe / ReShade."

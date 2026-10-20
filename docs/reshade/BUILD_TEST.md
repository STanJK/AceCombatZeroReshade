# Build, install and acceptance

## 1. Production build

```powershell
.\addon\build.ps1 -Target Bridge
```

Output:

```text
addon\bin\ACZRenderBridge.addon64
```

The build script fetches pinned ReShade `v6.8.0` headers into `.deps/reshade-6.8.0` if necessary and uses the installed MSVC x64 toolchain.

## 2. Calibration build

Calibration-only:

```powershell
.\addon\build.ps1 -Target Calibrate
```

Both:

```powershell
.\addon\build.ps1 -Target All
```

Outputs:

```text
addon\bin\ACZCalibrate.addon64
addon\bin\ACZRenderBridge.addon64
```

The Rust/XInput oracle is built separately:

```powershell
.\build.ps1
```

Output:

```text
target\release\xinput1_4.dll
```

The oracle is research-only.

## 3. Production install

Copy:

```powershell
Copy-Item `
  .\addon\bin\ACZRenderBridge.addon64 `
  D:\Games\ACZero\ACZRenderBridge.addon64 `
  -Force

Copy-Item `
  .\shaders\ACZSceneClean.fx `
  D:\Games\ACZero\reshade-shaders\Shaders\ACZSceneClean.fx `
  -Force
```

Expected game directory:

```text
acz.exe
dxgi.dll
ReShade.ini
ACZRenderBridge.addon64
reshade-shaders\Shaders\ACZSceneClean.fx
```

Remove/disable for production:

```text
ACZCalibrate.addon64
xinput1_4.dll
```

## 4. DLL reload behavior

Normal development workflow for C++ add-on changes:

```text
build
→ close ACZ
→ replace .addon64
→ restart ACZ
```

ReShade has internal add-on load/unload support, but safe hot reload is not treated as a supported development workflow here because the bridge owns:

- GPU resources/views;
- device and runtime private data;
- event registrations;
- pipeline fingerprint maps;
- in-flight resource state.

`.fx` changes can use normal ReShade shader reload.

## 5. Basic acceptance

Enable the `ACZSceneClean` technique and check `Display Raw`.

Expected:

### Main menu

```text
normal menu output
```

No black screen before first gameplay capture.

### Mission bootstrap

Log should contain:

```text
bootstrapped first-HUD fingerprint
```

and then:

```text
SceneClean allocated ... source_samples=8
SceneClean copied at first latched-HUD PSO draw copies=1
...
copies=60
copies=120
```

### Runtime stability

Test at minimum:

```text
MISSION START visible → disappears
normal maneuvering
first-person/no cockpit
cockpit
third-person
rapid V switching
subtitles/dialogue if available
pause/unpause
```

Expected:

```text
copies continue increasing
Display Raw remains live
no cockpit/HUD/black-frame flicker caused by wrong capture boundary
```

## 6. Known validated MSAA configuration

Observed:

```text
resolution      = 2560×1440
source samples  = 8
SceneClean      = single-sample
swapchain       = R10G10B10A2_UNORM
```

Do not assume all user settings use exactly the same source sample count; the bridge retains both resolve and copy paths.

## 7. Calibration/oracle mode

Use only when a new executable/render path invalidates the production bootstrap.

Research install:

```text
xinput1_4.dll
ACZCalibrate.addon64
ReShade dxgi.dll
```

The oracle can identify the CPU semantic HUD span and calibration can map that to actual ReShade GPU draws.

Production should return to:

```text
ACZRenderBridge.addon64
ACZSceneClean.fx
```

with no game-RVA dependency.

## 8. Useful diagnostic fields

Search ReShade log for:

```text
[ACZ Render Bridge]
bootstrapped first-HUD fingerprint
SceneClean allocated
SceneClean copied
MISS FRAME
FD
full_pso=
layout_hash=
```

If captures stop but the same latched `full_pso` still appears, investigate frame/present gating or resource state rather than inventing another draw-count anchor.

If the latched `full_pso` disappears completely, re-run calibration and compare the new PSO family.

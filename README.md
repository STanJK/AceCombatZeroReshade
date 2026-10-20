# AceCombatZeroReshade

Experimental rendering-bridge research for the 2026 Windows port of **ACE COMBAT ZERO THE BELKAN WAR**.

The current production path is a **pure ReShade add-on**. It does not require ACZ game-RVA hooks after one-time GPU bootstrap. The add-on identifies the first combat-HUD graphics PSO in the D3D12 draw stream, resolves the clean pre-HUD MSAA render target into `SceneClean`, and exposes that texture to ReShade effects as `ACZ_SCENE_CLEAN`.

> `xinput1_4.dll` and `ACZCalibrate.addon64` remain research/calibration tooling. They are not part of the intended production install.

## Target build

| Item | Value |
| --- | --- |
| Executable | `acz.exe` |
| Architecture | PE64 / x86-64 |
| IDA image base | `0x140000000` |
| SHA-256 | `43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664` |
| ReShade | `6.8.0.2155` |
| ReShade API | 20 |
| Graphics API | D3D12 |

Static addresses and RVAs in this documentation are specific to this executable. Analysis names are local semantic labels, not official symbols.

## Current production state

Validated path:

```text
ACZ scene rendering
    ↓
legacy packet/display-list layer
    ↓
D3D12 graphics PSOs
    ↓
bootstrap once with a known first-HUD draw sequence
    ↓
latch normalized full graphics-PSO fingerprint
    ↓
every frame: first draw using the latched full PSO
    ↓
resolve current 8× MSAA HUD target → single-sample SceneClean
    ↓
original HUD continues rendering normally
    ↓
ReShade effect runtime receives ACZ_SCENE_CLEAN
```

Observed bootstrap identity in the validated run:

```text
legacy stable = 0xc45ffe89e386cb09
full_pso      = 0x3ef04bb2bb111cce
layout_hash   = 0x904e7af1a7dbb185
VS            = 0x70848fc93426bb4e
PS            = 0xae6370c8685b4894
topology      = 0x5
```

The numeric values are diagnostic evidence. Production code latches the actual value at runtime instead of hard-coding it.

## Known renderer chain

```text
RVA 0x00AE510  whole combat HUD packet emitter
RVA 0x018F920  legacy display-list parser
RVA 0x019D160  packet interpreter
RVA 0x019CBF0  state/batch flush
RVA 0x0194840  legacy batch renderer
RVA 0x020F8E0  modern D3D12 draw builder
RVA 0x020F680  game-side D3D12 draw helper

RVA 0x020B9C0  frame begin/reset/barrier/clear
RVA 0x020C280  frame end/close/execute/present
RVA 0x033DA48  DeviceResources* global
```

The port retains a legacy display-list/render-command layer and translates it into native D3D12 work.

## Production build

Requirements:

- Windows x64
- Visual Studio / MSVC x64 C++ tools
- PowerShell
- Git

Build only the production add-on:

```powershell
.\addon\build.ps1 -Target Bridge
```

Output:

```text
addon\bin\ACZRenderBridge.addon64
```

Install:

```text
D:\Games\ACZero\
├─ dxgi.dll
├─ ReShade.ini
├─ ACZRenderBridge.addon64
└─ reshade-shaders\
   └─ Shaders\
      └─ ACZSceneClean.fx
```

Normal production setup should not keep these enabled:

```text
ACZCalibrate.addon64
xinput1_4.dll
```

The XInput proxy was a temporary semantic oracle and interferes with controller input.

## Raw SceneClean debug effect

`shaders/ACZSceneClean.fx` exposes:

```text
Display Raw
```

When enabled and a fresh `SceneClean` was captured for the current frame, the effect displays the pre-combat-HUD image. When no fresh capture exists, it falls back to the normal ReShade backbuffer instead of showing black or freezing an old SceneClean frame.

## Documentation

Start with [`docs/README.md`](docs/README.md).

Key pages:

- [`docs/reverse-engineering/FLOW.md`](docs/reverse-engineering/FLOW.md) — total render/HUD flow
- [`docs/reverse-engineering/FUNCTIONS.md`](docs/reverse-engineering/FUNCTIONS.md) — IDA VA/RVA function index
- [`docs/reverse-engineering/RENDERER.md`](docs/reverse-engineering/RENDERER.md) — legacy renderer and D3D12 seam
- [`docs/reverse-engineering/CAMERA.md`](docs/reverse-engineering/CAMERA.md) — CameraMode and FOV notes
- [`docs/reverse-engineering/HISTORY.md`](docs/reverse-engineering/HISTORY.md) — experiments, failures and design evolution
- [`docs/reshade/BRIDGE.md`](docs/reshade/BRIDGE.md) — production add-on architecture
- [`docs/reshade/SHADERS.md`](docs/reshade/SHADERS.md) — effect semantic contract
- [`docs/reshade/BUILD_TEST.md`](docs/reshade/BUILD_TEST.md) — build/install/test procedures

## Next phase

The clean-scene capture problem is considered closed for the tested gameplay/camera states.

Next problem:

```text
OriginalFinal = Scene + HUD
SceneClean    = Scene before combat HUD

HUD delta/mask
    ↓
post-process SceneClean
    ↓
restore original HUD pixels
```

That phase requires preserving the original final image, processing the clean scene, deriving a robust HUD mask/delta, and compositing the untouched HUD back after scene effects.

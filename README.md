# AceCombatZeroReshade

Experimental rendering bridge research for the 2026 Windows port of **ACE COMBAT ZERO THE BELKAN WAR**.

## Current stage: one-shot render oracle

The current `winmm.dll` build is **not the final ReShade add-on**. It is a short-lived diagnostic oracle used to map the already identified ACZ HUD/display-list seam onto stable D3D12 draw/pipeline fingerprints.

Verified executable SHA-256:

```text
43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
```

The DLL refuses to install game hooks when the host hash does not match.

### Known renderer chain

```text
RVA 0x00AE510  whole combat HUD packet emitter
RVA 0x018F920  legacy display-list parser
RVA 0x019D160  packet interpreter
RVA 0x019CBF0  batch/state flush
RVA 0x0194840  legacy batch renderer
RVA 0x020F8E0  modern D3D12 draw builder
RVA 0x020F680  D3D12 draw helper
RVA 0x020C280  frame-end / Execute / Present path
RVA 0x033DA48  DeviceResources*
```

The port keeps a legacy display-list/render-command layer and translates it into a native D3D12 backend.

### Build

Requirements: Windows x64, recent stable Rust/Cargo, MSVC toolchain.

```powershell
.\build.ps1
```

or:

```powershell
cargo build --release
```

Output:

```text
target\release\winmm.dll
```

### Run

1. Put `winmm.dll` next to `acz.exe`.
2. Start ACZ normally.
3. Enter a mission and wait until gameplay is stable.
4. Press **Numpad `+`** once.
5. The oracle deliberately skips the frame already in progress and captures one complete future frame.
6. Read `ACZRenderOracle.log` next to `acz.exe`.

The oracle does not suppress the HUD, patch game state, read back pixels, or modify rendering output.

### Logged data

For the selected frame it records:

- pre/post HUD packet pointers (`HUD span`);
- packet-interpreter regions that belong to that span;
- legacy batch flushes caused by HUD packets;
- modern draw-builder parameters reached from the HUD parser;
- actual D3D12 Draw/DrawIndexed calls while HUD parsing is active;
- current PSO pointer;
- VS/PS SHA-256 when PSO creation was observed;
- cached-PSO blob hash as a fallback;
- primitive topology;
- RTV/DSV descriptor handles;
- the immediately preceding D3D12 draw;
- the first confirmed HUD D3D12 draw.

The result is intended to produce a stable GPU anchor for the next phase:

```text
ACZ scene
  -> ReShade add-on detects first HUD draw
  -> copy pre-HUD color to ACZ_SCENE_CLEAN
  -> original HUD continues normally
  -> ReShade .fx derives HUD mask / protects HUD
```

## Why winmm.dll

This ACZ build imports only `timeBeginPeriod`, `timeEndPeriod`, and `timeGetTime` from WINMM. The proxy forwards those three functions to `%WINDIR%\System32\winmm.dll` and performs all initialization on a bootstrap thread, keeping `DllMain` minimal.

## Status

Temporary oracle stage. Once the GPU anchor is identified, the intended production architecture is a ReShade add-on plus `.fx`, without ACZ RVA hooks.

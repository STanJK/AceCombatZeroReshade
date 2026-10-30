# ACZRenderBridge production architecture

`addon/ACZRenderBridge.cpp` is the production ReShade add-on.

Its current responsibilities are:

```text
1. identify the first combat-HUD GPU PSO each frame
2. capture/resolve the pre-HUD scene as SceneClean
3. expose SceneClean + freshness to ReShade
4. capture the untouched game final before effects as OriginalFinal
5. optionally capture the processed clean scene for exact A/B comparison
6. gate enabled techniques when no fresh SceneClean exists
7. expose a read-only ACZ GameControl lifecycle diagnostic
```

The bridge still avoids patching ACZ code.

## 1. Current production boundary

The add-on uses ReShade events/resources for all render capture and effect orchestration.

It does **not**:

- patch ACZ code;
- install inline detours;
- patch system D3D12 vtables;
- depend on the old temporary XInput semantic oracle;
- read ACZ `DeviceResources` directly.

It **does** now perform one diagnostic-only read from the game image:

```text
acz.exe + RVA 0x032C933
```

This is the GameControl/control-active byte documented in [`../reverse-engineering/MODE_LIFECYCLE.md`](../reverse-engineering/MODE_LIFECYCLE.md).

The value is logged/exposed to shaders but is not yet used for effect admission.

## 2. Event model

Relevant ReShade events:

```text
init_pipeline_layout
destroy_pipeline_layout
init_pipeline
destroy_pipeline

bind_pipeline
bind_pipeline_states
bind_render_targets_and_depth_stencil
draw
draw_indexed
present

init_effect_runtime
destroy_effect_runtime
reshade_begin_effects
reshade_render_technique
reshade_reloaded_effects
```

ReShade `draw` / `draw_indexed` callbacks happen before the draw executes, allowing capture immediately before the first detected combat-HUD draw.

## 3. Draw-stream state

A render-thread `thread_local` stream tracks:

```text
current pipeline
current primitive topology
RTV0
DSV
draw ordinal
previous draw history
last copied present
current frame draw diagnostics
```

The state is deliberately continuous rather than command-list-local.

A command-list-local implementation previously lost the semantic sequence when ACZ changed command-list scheduling.

## 4. Pipeline fingerprinting

### Legacy fingerprint

Historical `stable` hash:

```text
shader hashes
topology
RT/DS formats
sample count
```

It remains useful for diagnostics and the one-time legacy bootstrap family, but is not unique enough for runtime identity.

### Full normalized graphics PSO

`full_pso` hashes explicit semantic fields:

```text
pipeline layout / root signature contents
VS/HS/DS/GS/PS/AS/MS bytecode hashes
input layout
stream-output state
blend state
rasterizer state
depth/stencil state
primitive topology
RT/DS formats
sample mask/count
viewport count
max vertex count
dynamic state declarations
pipeline flags
```

Not hashed:

```text
pipeline.handle
pipeline_layout.handle
raw pointers
subobject data pointers
structure padding
```

Validated bootstrap result:

```text
stable      = 0xc45ffe89e386cb09
full_pso    = 0x3ef04bb2bb111cce
layout_hash = 0x904e7af1a7dbb185
VS          = 0x70848fc93426bb4e
PS          = 0xae6370c8685b4894
topology    = 0x5
```

The literal `full_pso` is not hard-coded as the primary runtime detector; the bridge latches the current full fingerprint during bootstrap.

## 5. Bootstrap and runtime HUD detector

Bootstrap still uses the known historical anchor once:

```text
IDX64
DRAW4
IDX89
```

After bootstrap, draw count is intentionally ignored.

Runtime admission to SceneClean capture is:

```cpp
bootstrapped &&
latched_full_pso != 0 &&
current.fp.full_pso == latched_full_pso &&
current.topology == 0x5 &&
current.rtv0 != 0 &&
current.dsv != 0
```

The first hit per present triggers capture.

This survived states where the first draw count changed, e.g. `IDX89 → IDX94`, while the correct normalized PSO remained unchanged.

## 6. SceneClean

Semantic:

```text
ACZ_SCENE_CLEAN
```

Meaning:

> current main render target captured immediately before the first detected combat-HUD PSO draw.

Important limitation:

> SceneClean is pre-**combat-HUD**, not guaranteed pre-all-UI.

For example, `MISSION START` has been observed inside SceneClean.

### MSAA path

Validated gameplay target:

```text
2560×1440
8× MSAA
```

For MSAA source:

```text
source render_target → resolve_source
SceneClean shader_resource/resolve_dest transition
resolve_texture_region(...)
source → render_target
SceneClean → shader_resource
```

Single-sample targets use a copy path.

### Freshness

Uniform source:

```text
acz_scene_clean_fresh
```

Freshness means the SceneClean copy counter advanced since the last effect-runtime use.

It is a render-capture validity signal, not a gameplay-state signal.

## 7. Technique gate

The bridge keeps ReShade's global effects state enabled.

When no fresh SceneClean exists, it:

1. enumerates currently enabled techniques;
2. records them;
3. disables those techniques individually;
4. restores the same technique set once SceneClean becomes fresh again.

This deliberately avoids a global `set_effects_state(false)` style design, because the bridge must keep receiving effect callbacks in order to recover automatically.

Current gate condition:

```text
SceneClean freshness only
```

Known limitation:

- a render fingerprint may still become valid during mission-end/movie/hangar transitions;
- hangar is intended to remain post-processed eventually, but with a different profile/technique policy.

Therefore freshness alone is no longer considered the final scene-admission architecture.

## 8. OriginalFinal

Semantic:

```text
ACZ_ORIGINAL_FINAL
```

Uniform freshness source:

```text
acz_original_final_fresh
```

At `reshade_begin_effects`, after SceneClean freshness is established and before the first shader route replaces the effect input, the bridge copies the current single-sample ReShade target.

Meaning:

```text
OriginalFinal = untouched game final presented to ReShade
              = scene + game HUD/UI at that point
```

This texture is used by HUD restoration and A/B comparison.

## 9. ProcessedClean

Semantic:

```text
ACZ_PROCESSED_CLEAN
```

Uniform freshness source:

```text
acz_processed_clean_fresh
```

This resource exists for an exact clean-scene A/B path.

When `ACZBeforeAfter` is enabled, `reshade_render_technique` captures the latest processed target after each eligible technique.

It deliberately stops before:

```text
ACZRestoreHUD
ACZBeforeAfter
```

Therefore the last stored state is:

```text
ProcessedClean = processed SceneClean immediately before HUD restoration
```

The bridge avoids this extra capture path when the A/B technique is disabled.

## 10. Effect-stage frame path

```text
game renders scene
    ↓
first combat-HUD PSO
    ↓
SceneClean captured/resolved
    ↓
game HUD completes
    ↓
reshade_begin_effects
    ├─ publish GameControl diagnostic
    ├─ publish SceneClean + freshness
    ├─ apply technique gate
    └─ copy current game target → OriginalFinal
    ↓
ACZRouteSceneClean
    ↓
post-processing techniques
    ↓
ProcessedClean updated only when A/B is active
    ↓
ACZRestoreHUD
    ↓
ACZBeforeAfter (optional, last)
```

## 11. Why SceneClean routing is a shader pass

The original attempt to route SceneClean directly in C++ encountered a format mismatch:

```text
SceneClean     = R16G16B16A16_FLOAT
effect target  = R10G10B10A2_UNORM
```

The production path uses `ACZRouteSceneClean.fx` as the first ACZ shader pass.

Sampling the FP16 SceneClean and writing the current ReShade target naturally performs the format conversion.

## 12. GameControl lifecycle diagnostic

Static RE established:

```text
ModeGameControl enter  RVA 0x016E0B0 → byte 0x032C933 = 1
ModeGameControl leave  RVA 0x016E4C0 → byte 0x032C933 = 0
```

The bridge reads:

```cpp
GetModuleHandleW(nullptr) + 0x032C933
```

and logs transitions:

```text
ACZRenderBridge: GameControl flag transition ...
```

Uniform source:

```text
acz_gamecontrol_active
```

Current status:

> diagnostic only.

Gameplay code also writes this byte, so it is not yet accepted as a pure `combat_active` boolean.

See [`../reverse-engineering/MODE_LIFECYCLE.md`](../reverse-engineering/MODE_LIFECYCLE.md).

## 13. Current scene-admission direction

The next bridge-level classifier should separate at least:

```text
Combat
Hangar / aircraft presentation
Movie/result/briefing/debrief
Menu/other
```

The target policy is not simply "ReShade on in combat, off elsewhere".

Current requirement:

```text
Combat → current combat post stack
Hangar → post-processing allowed, but likely a different profile/technique set
Movie/result/menu → combat stack off unless explicitly designed otherwise
```

Hangar-state mapping is still open.

## 14. Diagnostics

Useful render fields:

```text
copies=
ordinal=
full_pso=
pipeline=
source=
dest=
rtv=
source_samples=
resolved=
```

Miss dumps include:

```text
DRAW / IDX
count
ordinal
pipeline
legacy stable
full_pso
layout_hash
VS/PS
topology
RTV/DSV
```

Useful lifecycle log filter:

```powershell
Select-String `
  -Path D:\Games\ACZero\ReShade.log `
  -Pattern "GameControl flag transition"
```

## 15. Production invariants vs open work

### Verified/implemented

- normalized full-PSO HUD identity;
- MSAA SceneClean resolve;
- SceneClean freshness;
- individual-technique fail-safe gate;
- OriginalFinal capture;
- ProcessedClean A/B capture;
- diagnostic read of GameControl flag.

### Open

- runtime validation of `0x032C933` across pause/replay/mission-end;
- semantic hangar mode identification;
- mode-aware technique/profile selection;
- supported ReShade whole-preset live switching, if any;
- replay-specific HUD restore artifact cleanup.

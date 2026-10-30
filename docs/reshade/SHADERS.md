# ReShade shader contract

This document describes the ACZ-specific shader semantics layered on top of `ACZRenderBridge.addon64`.

Current ACZ-owned effects:

```text
ACZRouteSceneClean.fx
ACZSceneClean.fx
ACZLighting.fx
ACZRestoreHUD.fx
ACZBeforeAfter.fx
ACZBF3Reference.fx
```

The proprietary iMMERSE package is a local user dependency and is not distributed by this repository.

## 1. Bridge texture semantics

### SceneClean

```hlsl
texture2D ACZSceneCleanTex : ACZ_SCENE_CLEAN;
```

Meaning:

> scene captured immediately before the first detected combat-HUD PSO draw.

Freshness source:

```hlsl
source = "acz_scene_clean_fresh";
```

This is a current-frame render-capture validity signal, not a gameplay-state signal.

### OriginalFinal

```hlsl
texture2D ACZOriginalFinalTex : ACZ_ORIGINAL_FINAL;
```

Meaning:

> untouched game final copied at `reshade_begin_effects` before SceneClean routing.

Freshness source:

```text
acz_original_final_fresh
```

### ProcessedClean

```hlsl
texture2D ACZProcessedCleanTex : ACZ_PROCESSED_CLEAN;
```

Meaning:

> latest processed SceneClean state immediately before HUD restore/A-B, captured only when the A/B technique is enabled.

Freshness source:

```text
acz_processed_clean_fresh
```

## 2. ACZRouteSceneClean

`ACZRouteSceneClean` should be the first ACZ-owned scene-routing technique.

Logic:

```hlsl
if (ACZSceneCleanFresh)
    return ACZ_SCENE_CLEAN;

return ReShade::BackBuffer;
```

The route is shader-based rather than a direct C++ resource copy because the clean source and ReShade effect target can have different formats:

```text
SceneClean     R16G16B16A16_FLOAT
effect target  R10G10B10A2_UNORM
```

Sampling/writing performs the required conversion naturally.

## 3. ACZSceneClean debug view

`ACZSceneClean.fx` remains the simple raw-capture validator.

`Display Raw` behavior:

| State | Output |
| --- | --- |
| off | ordinary ReShade backbuffer |
| on + fresh SceneClean | raw pre-combat-HUD SceneClean |
| on + no fresh SceneClean | ordinary ReShade backbuffer |

It also exposes the read-only diagnostic:

```text
GameControl Active
source = "acz_gamecontrol_active"
```

This is the raw ACZ byte at RVA `0x032C933`.

Important: the shader displays it for diagnosis only. It is not currently a production gate.

## 4. SceneClean semantic limitation

SceneClean means:

> immediately before the first **combat HUD** draw.

It does not mean:

> before every possible UI element.

Observed example:

```text
MISSION START
```

can already be present in SceneClean.

Therefore HUD restoration is based on the difference between SceneClean and OriginalFinal, not on an assumption that SceneClean is UI-free.

## 5. ACZRestoreHUD

`ACZRestoreHUD.fx` compares:

```text
OriginalFinal
vs
SceneClean
```

to derive a HUD/UI difference mask.

Core signal:

```text
delta = abs(OriginalFinal - quantized(SceneClean))
mask  = smoothstep(HUDMaskLow, HUDMaskHigh, max(delta.rgb))
```

SceneClean is explicitly quantized to the 10-bit target domain before comparison so FP16 → RGB10A2 conversion error does not become a false HUD signal.

Optional one-pixel neighborhood dilation expands the mask around antialiased HUD edges.

Final composite:

```text
Final = lerp(ProcessedScene, OriginalFinal, mask * HUDRestoreStrength)
```

Default controls in source:

```text
HUDMaskLow         = 0.0025
HUDMaskHigh        = 0.0150
HUDMaskDilate      = 0
HUDRestoreStrength = 1
```

### Known replay failure

Replay can produce false-positive scene differences between SceneClean and OriginalFinal.

Visible symptom:

```text
contour / woodgrain-like patterns
on aircraft or terrain
with temporal flicker
```

Current interpretation:

> Replay changes scene/post state between the clean boundary and OriginalFinal strongly enough that a simple low-threshold frame difference stops being a pure HUD detector.

Open repair directions:

1. bypass restore in replay if replay UI is already present in SceneClean;
2. otherwise use a high-confidence seed plus lower-threshold neighbor growth/hysteresis rather than direct low-threshold classification.

## 6. ACZBeforeAfter

`ACZBeforeAfter` should remain last when enabled.

Two modes:

### Remove HUD on both sides = ON

```text
left  = raw SceneClean
right = ProcessedClean
```

This is the exact clean-scene processing comparison.

### Remove HUD on both sides = OFF

```text
left  = OriginalFinal
right = current final after HUD restoration
```

If any required bridge texture is stale, the shader fails safe to the current final target.

## 7. ACZLighting and iMMERSE Launchpad normals

`ACZLighting.fx` can use either:

```text
internal screen-space reconstructed normal
or
iMMERSE Launchpad deferred normal
```

Compile-time switch:

```text
ACZ_USE_IMMERSE_NORMALS=1
```

When enabled, the include order must remain:

```text
iMMERSE/MartysMods/mmx_deferred.fxh
then
ReShade.fxh
```

Reason:

- iMMERSE declares names such as `BUFFER_PIXEL_SIZE` / `BUFFER_SCREEN_SIZE`;
- `ReShade.fxh` defines macros with the same names;
- reversing the order causes macro expansion inside iMMERSE declarations and compiler syntax errors.

When iMMERSE normals are enabled, `ACZLighting` requests:

```text
MARTYSMODS_IPC_FEATURE_NORMALS
```

through the iMMERSE IPC/predication mechanism.

Runtime testing showed Launchpad's:

```text
Basic
Smoothed
Smoothed + Textured
```

normal modes can substantially reduce ACZ's low-poly normal faceting, with `Smoothed + Textured` also recovering high-frequency surface variation from the color/albedo signal.

That integration is local-only; no proprietary iMMERSE source or textures belong in this repository.

## 8. Recommended technique-order constraints

The exact middle stack can change, but these ordering constraints are architectural:

```text
ACZRouteSceneClean
↓
Launchpad / scene-processing effects
↓
...
↓
ACZRestoreHUD
↓
ACZBeforeAfter   (when enabled, last)
```

When iMMERSE Launchpad is used, it should be after `ACZRouteSceneClean` so its COLOR input observes the clean scene rather than the untouched Scene+HUD frame.

## 9. Current scene-admission limitation

The bridge currently gates techniques from SceneClean freshness.

This prevents many menu/non-game frames from receiving the combat stack, but it is not a final semantic scene classifier.

Known desired split:

```text
Combat
    → combat stack

Hangar / aircraft presentation
    → effects allowed, but likely a different profile/technique set

Movie/result/menu
    → combat stack disabled
```

The ACZ mode-state work for this is documented in:

- [`../reverse-engineering/MODE_LIFECYCLE.md`](../reverse-engineering/MODE_LIFECYCLE.md)

## 10. Fail-safe rule

Every ACZ bridge texture must be treated as stale unless its corresponding freshness signal says otherwise.

Never intentionally display or composite an old semantic texture just because the resource handle still exists.

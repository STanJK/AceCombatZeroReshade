# ReShade shader contract

The current debug shader is:

```text
shaders/ACZSceneClean.fx
```

It is intentionally simple. Its job is to prove that the add-on is supplying a valid current-frame pre-HUD texture.

## 1. Texture semantic

```hlsl
texture2D ACZSceneCleanTex : ACZ_SCENE_CLEAN;
```

The add-on binds the SceneClean SRV to this semantic at effect time.

## 2. Freshness semantic

```hlsl
uniform bool ACZSceneCleanFresh <
    source = "acz_scene_clean_fresh";
>;
```

The add-on updates this uniform through ReShade's effect-runtime API.

Meaning:

```text
true  = SceneClean was updated since the last effect-runtime use
false = no current/fresh capture available
```

This should be treated as a safety signal, not a gameplay-state signal.

## 3. Display Raw

The debug checkbox:

```hlsl
uniform bool DisplayRaw <
    ui_label = "Display Raw";
> = false;
```

Current pixel behavior:

```hlsl
if (DisplayRaw && ACZSceneCleanFresh)
    return tex2D(ACZSceneCleanSampler, texcoord);

return tex2D(ReShade::BackBuffer, texcoord);
```

Therefore:

| State | Output |
| --- | --- |
| Display Raw off | ordinary ReShade backbuffer |
| Display Raw on + fresh SceneClean | raw pre-combat-HUD SceneClean |
| Display Raw on + no fresh capture | ordinary ReShade backbuffer |

This avoids black main menus and stale-frame freezes.

## 4. Important semantic limitation

`SceneClean` currently means:

> image captured immediately before the first **combat HUD** PSO draw.

It does **not** mean "absolutely no UI has been drawn".

During development, `MISSION START` was visible inside SceneClean. This proves some temporary overlays can be drawn before the combat HUD boundary.

Subtitles or other overlays may similarly precede the combat-HUD boundary.

That distinction matters for the next mask/composite phase.

## 5. Planned post-processing architecture

Target pipeline:

```text
OriginalFinal = scene + all HUD/UI after the SceneClean boundary
SceneClean    = scene + any pre-boundary overlays

HUDDelta = abs(OriginalFinal - SceneClean)
HUDMask  = threshold/smooth/dilate/feather(HUDDelta)

ProcessedScene = postprocess(SceneClean)
Final = lerp(ProcessedScene, OriginalFinal, HUDMask)
```

Questions still to solve:

- how to preserve/copy `OriginalFinal` at the right ReShade phase;
- ordering relative to MXAO/Bloom/LUT/CAS and other effects;
- robust alpha/threshold behavior for antialiased HUD edges;
- handling UI that is already present in SceneClean;
- temporal stability of the mask.

No final production HUD mask has been implemented yet.

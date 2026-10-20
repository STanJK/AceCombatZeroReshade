# ACZRenderBridge production architecture

`addon/ACZRenderBridge.cpp` is the production ReShade add-on.

Its purpose is deliberately narrow:

> expose a fresh pre-combat-HUD scene texture every gameplay frame without retaining game-RVA hooks.

## 1. Production boundary

The add-on uses only ReShade events/resources after bootstrap.

It does **not**:

- patch ACZ code;
- hook known ACZ RVAs;
- read ACZ `DeviceResources` directly;
- patch system D3D12 vtables;
- depend on the temporary XInput oracle.

The only legacy knowledge retained in production logic is the one-time bootstrap draw sequence used to identify the first correct HUD PSO.

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
reshade_reloaded_effects
```

ReShade `draw` and `draw_indexed` callbacks occur before the actual draw executes, which is exactly what allows capture immediately before the first HUD draw.

## 3. Draw-stream state

A `thread_local` stream state tracks:

```text
current pipeline handle
current primitive topology
RTV0
DSV
global draw ordinal
previous draw history
last copied present serial
current frame draw diagnostics
```

The state is intentionally render-thread continuous rather than command-list-local.

A command-list-local implementation was tested and caused the detector to stop after a few frames when ACZ changed command-list scheduling.

## 4. Pipeline fingerprinting

### Legacy fingerprint

The original `stable` hash included mainly:

```text
shader hashes
topology
RT/DS formats
sample count
```

It remains in logs for historical comparison, but is not sufficient for production identity.

### Full PSO fingerprint

`full_pso` normalizes:

```text
pipeline layout/root signature
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
dynamic pipeline-state declarations
flags
```

The pipeline layout hash expands:

```text
push constants
descriptor tables
push descriptors
register indices/spaces
visibility
descriptor type/count
range flags
static sampler descriptions
```

Not hashed:

```text
pipeline.handle
pipeline_layout.handle
raw pointers
structure padding
```

Runtime handles are logged only for diagnostics.

## 5. Bootstrap

Before bootstrap, the known calibrated sequence remains useful:

```text
IDX64
DRAW4
IDX89
```

When this sequence matches the old HUD shader/topology family on the same target, the add-on latches:

```text
current.fp.full_pso
```

Observed value in the validated run:

```text
0x3ef04bb2bb111cce
```

The add-on does not rely on that literal value in source.

## 6. Runtime detector

After bootstrap:

```cpp
match =
    bootstrapped &&
    latched_full_pso != 0 &&
    current.fp.full_pso == latched_full_pso &&
    current.topology == 0x5 &&
    current.rtv0 != 0 &&
    current.dsv != 0;
```

The first match in a present interval triggers capture.

Draw count is intentionally ignored.

This change was required after logs showed the same correct `full_pso` appearing with a different first draw count (`89` in one state, `94` in another).

## 7. SceneClean resource

`bridge_device_data` owns:

```text
SceneClean resource
SceneClean SRV
resource descriptor
shader-ready flag
retired resources/views
copy counter
```

Retired resources/views are held until device teardown to avoid freeing resources that may still be referenced by in-flight GPU work during rare resize/recreate events.

## 8. MSAA resolve path

Tested source:

```text
2560×1440
8× MSAA
```

SceneClean is created as:

```text
Texture2D
same width/height
single sample
shader_resource
resolve_dest or copy_dest
```

For MSAA source:

```text
source: render_target → resolve_source
SceneClean: shader_resource → resolve_dest   (after first frame)
resolve_texture_region(...)
source: resolve_source → render_target
SceneClean: resolve_dest → shader_resource
```

For single-sample source:

```text
source: render_target → copy_source
copy_resource(...)
source: copy_source → render_target
SceneClean: copy_dest → shader_resource
```

## 9. Effect semantic

The add-on exposes:

```text
ACZ_SCENE_CLEAN
```

using:

```cpp
runtime->update_texture_bindings("ACZ_SCENE_CLEAN", srv, srv);
```

A separate uniform annotation reports whether the texture was updated since the previous effect-runtime use:

```text
source = "acz_scene_clean_fresh"
```

This freshness signal is part of the effect safety contract.

## 10. Fail-safe behavior

Before freshness tracking, two visible failures existed:

- main menu + `Display Raw` → black;
- detector miss → frozen old SceneClean.

Current contract:

```text
fresh = true  → effect may show SceneClean
fresh = false → effect should pass through ReShade::BackBuffer
```

This keeps detector problems visible without destroying normal rendering.

## 11. Diagnostics

Useful log fields:

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

Miss diagnostics can log compact candidate records containing:

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

These diagnostics were decisive in proving that full PSO, rather than draw count, was the stable discriminator.

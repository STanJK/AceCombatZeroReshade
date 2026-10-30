# ACZ rendering research index

This directory records the current reverse-engineering and ReShade integration state for the 2026 Windows port of **ACE COMBAT ZERO THE BELKAN WAR**.

The structure follows two principles used in the reference projects that motivated this documentation style:

1. keep **flow-level explanation** separate from **address-level function evidence**;
2. preserve **what failed and why**, not only the final working path.

This is research documentation, not a claim that reconstructed names or types match the original source tree.

## Target/version boundary

| Item | Value |
| --- | --- |
| Module | `acz.exe` |
| Architecture | PE64 / x86-64 |
| IDA image base | `0x140000000` |
| SHA-256 | `43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664` |
| ReShade | `6.8.0.2155` |
| ReShade API | 20 |
| D3D backend | D3D12 |

RVA is `IDA_VA - 0x140000000`.

Do not transplant these addresses to another ACZ executable without revalidation.

## Confidence convention

| Label | Meaning |
| --- | --- |
| **Verified** | Supported by static code plus repeated runtime behavior/logs, or by direct repeated runtime observation. |
| **High-confidence inference** | Static structure strongly supports the meaning, but the exact semantic label is not independently runtime-proven. |
| **Open / tentative** | Useful lead that has not yet been validated enough to use as a production contract. |

Analysis names such as `CombatHudPacketEmitter`, `CameraMode`, `DeviceResources`, or `FirstHudPso` are local labels.

## Document map

| Document | Scope |
| --- | --- |
| [`reverse-engineering/FLOW.md`](reverse-engineering/FLOW.md) | Main semantic path from combat HUD packet generation to GPU draw and SceneClean capture |
| [`reverse-engineering/FUNCTIONS.md`](reverse-engineering/FUNCTIONS.md) | IDA VA/RVA index, globals, camera-state fields and normalized pseudocode |
| [`reverse-engineering/RENDERER.md`](reverse-engineering/RENDERER.md) | Legacy display-list/parser behavior, D3D12 builder, frame lifecycle and semantic seam |
| [`reverse-engineering/CAMERA.md`](reverse-engineering/CAMERA.md) | `CameraMode` input normalization, three-state view cycle and FOV/projection leads |
| [`reverse-engineering/HISTORY.md`](reverse-engineering/HISTORY.md) | Experiment timeline, rejected approaches and failure-derived design rules |
| [`reverse-engineering/MODE_LIFECYCLE.md`](reverse-engineering/MODE_LIFECYCLE.md) | ACZ mode stack, GameControl/GameEnd lifecycle, lifecycle flag and hangar-state leads |
| [`reshade/BRIDGE.md`](reshade/BRIDGE.md) | `ACZRenderBridge.addon64` production architecture |
| [`reshade/SHADERS.md`](reshade/SHADERS.md) | `ACZ_SCENE_CLEAN`, freshness contract and effect behavior |
| [`reshade/BUILD_TEST.md`](reshade/BUILD_TEST.md) | Build, install, acceptance and calibration procedures |

## Current closure

The following behavior is verified or implemented:

1. ACZ's combat HUD has a semantic CPU packet seam at `sub_1400AE510`.
2. CPU parser/draw-builder scope does not overlap ReShade draw callbacks because the renderer queues/translates work before the draw callbacks occur.
3. A pure ReShade render path can identify the first combat-HUD GPU PSO after one-time bootstrap.
4. The tested main render target is 8× MSAA at 2560×1440.
5. The add-on resolves the current pre-HUD target to a single-sample shader-readable `SceneClean`.
6. A normalized full graphics-PSO fingerprint remains usable across `MISSION START` changes, cockpit rendering, third-person view, camera switching and ordinary maneuvering where draw-count/adjacency methods fail.
7. The bridge now also captures `OriginalFinal` before effects and an optional `ProcessedClean` before HUD restore/A-B.
8. Technique admission currently fails safe on SceneClean freshness without disabling ReShade globally.
9. `ModeHolder`, `ModeGameControl` and `ModeGameEnd` have been statically recovered well enough to expose a separate gameplay lifecycle axis.
10. `ModeGameControl` enter/leave write `acz.exe + 0x032C933` to 1/0 respectively; the bridge exposes that byte as a diagnostic, but other gameplay code also writes it, so it is not yet a production `combat_active` contract.
11. Hangar/aircraft presentation should eventually remain post-processed with a different profile or technique policy rather than being treated as simply "ReShade off".

The next open scene-state problems are:

- runtime correlation of the GameControl diagnostic through pause/replay/mission-end;
- identification of the semantic hangar mode;
- mode-aware combat vs hangar effect policy;
- verification of whether ReShade 6.8 exposes a supported live whole-preset switch suitable for the bridge;
- replay-specific false positives in the HUD difference mask.

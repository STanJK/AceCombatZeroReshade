# Research history and rejected approaches

This page preserves the path that led to the current full-PSO SceneClean bridge.

The failed approaches are kept because each one exposed an important renderer invariant or non-invariant.

## 1. Starting goal

The practical goal was:

```text
apply ReShade effects to the 3D scene
without post-processing the combat HUD
```

Desired eventual image path:

```text
OriginalFinal = Scene + HUD
SceneClean    = Scene before HUD

process(SceneClean)
→ derive/restore HUD
→ final output
```

The first problem was therefore:

> find a reliable point immediately before the combat HUD begins rendering.

## 2. Static semantic seam

Reverse engineering identified:

```text
sub_1400AE510
```

as the whole combat-HUD packet emitter.

Call site:

```asm
0x140108976 call sub_1400AE510
0x14010897B mov  rdx, rax
0x140108981 call sub_1402011A0
```

Downstream chain:

```text
1400AE510
→ 14018F920
→ 14019D160
→ 14019CBF0
→ 140194840
→ 14020F8E0
→ 14020F680
```

## 3. Temporary oracle proxy

A short-lived game-side oracle was built to export HUD semantic scope.

### First proxy: `winmm.dll`

Problem:

```text
major performance regression / WARP-like behavior
```

The oracle was moved to:

```text
xinput1_4.dll
```

This avoided the WinMM rendering problem but interfered with controller input.

That was accepted because the oracle was never intended as production architecture.

## 4. ReShade calibration add-on

`ACZCalibrate.addon64` was built to correlate:

```text
CPU semantic oracle
↔ ReShade D3D12 draw callbacks
```

Environment:

```text
ReShade 6.8.0.2155
API 20
64-bit D3D12
```

Calibration work also fixed:

- packet interpreter ABI from three args to four;
- removal of system D3D12 vtable patching;
- builder-depth bookkeeping;
- full ReShade draw-stream telemetry.

## 5. Major finding: CPU scope and ReShade draw do not overlap

Expected model:

```text
HUD parser active
→ modern draw builder active
→ ReShade callback sees HUD scope
```

Observed:

```text
relevant ReShade draw callbacks: scope = 0
```

Conclusion:

```text
ACZ queues/translates legacy work first
and records actual D3D12 draws later.
```

The CPU-scope bridge was abandoned.

## 6. First pure-GPU anchor

Full-stream alignment found:

```text
IDX64
DRAW4
IDX89
```

with:

```text
stable   = 0xc45ffe89e386cb09
VS       = 0x70848fc93426bb4e
PS       = 0xae6370c8685b4894
topology = 0x5
```

An anchor validator produced roughly one hit per frame in the first validation window.

This proved a pure ReShade production bridge was possible.

## 7. Production SceneClean Phase 1

`ACZRenderBridge.addon64` responsibilities:

- observe ReShade pipeline/draw events;
- detect first HUD draw;
- copy/resolve current main render target to `SceneClean`;
- expose `SceneClean` to ReShade effects.

`ACZSceneClean.fx` added `Display Raw`.

## 8. Failure: black raw texture

Runtime log:

```text
unsupported HUD target desc type=3 size=2560x1440 samples=8
```

The main target was 8× MSAA.

Initial bridge only handled single-sample copy.

Fix:

```text
MSAA source: render_target → resolve_source
SceneClean: resolve_dest
resolve_texture_region(...)
SceneClean → shader_resource
```

After this, `Display Raw` showed a valid clean image.

## 9. Failure: only first frame updated

Symptom:

```text
copies=1
then no further copies
```

A per-command-list anchor state had replaced calibration's continuous render-thread draw stream.

Wrong abstraction.

Fix:

```text
restore one thread_local continuous draw stream
```

Then:

```text
copies=1,2,3,4,5,60,120,...
```

continued normally.

Design rule:

> logical draw-stream history must not be arbitrarily fragmented by command-list-local tracking.

## 10. Failure: apparent V/camera freeze

Initially:

```text
press V
→ raw frame freezes
```

Further observation showed the last frozen frame often still contained:

```text
MISSION START
```

This shifted diagnosis away from resolve/resource handling and toward transient UI changing the anchor sequence.

## 11. Runtime PSO handle latch

Next detector:

```text
bootstrap known sequence once
→ latch first-HUD pipeline.handle
→ later match handle + IDX89
```

It survived some transient UI changes but failed in third-person.

Reason:

```text
runtime D3D12 PSO pointer/handle is not a stable semantic key
```

## 12. Partial fingerprint-only detector

Relaxed detector:

```text
partial stable fingerprint
+ IDX89
+ first match per frame
```

Produced wrong captures:

- cockpit geometry flashed into `SceneClean`;
- airspeed/HUD elements flashed into raw;
- entire screen occasionally flashed black.

Later evidence showed many different PSOs shared the same partial fingerprint.

## 13. `DRAW4 → IDX89` adjacency detector

Old full-stream logs showed `DRAW4 → IDX89` was unique in a small calibration sample.

It was better than `IDX89` alone but still failed when:

- `MISSION START` disappeared;
- subtitles/temporary UI changed;
- camera/render mode changed.

Conclusion:

> adjacency is a sample property, not a renderer invariant.

## 14. Freshness fail-safe

Separate UX issue:

- `Display Raw` in main menu sampled missing/uninitialized SceneClean → black;
- when capture stopped, old SceneClean remained displayed indefinitely.

A per-effect-runtime freshness contract was added.

Current behavior:

```text
fresh SceneClean this frame
→ show SceneClean when Display Raw is enabled

no fresh capture this frame
→ show normal ReShade backbuffer
```

So detector misses no longer freeze or black out the image.

## 15. CameraMode reverse engineering

DInput semantics showed:

```text
V → RSC → CameraMode
```

IDA then identified:

```text
action ID 0x22
camera mode byte +0x2094
cycle 0 → 2 → 1 → 0
```

`sub_140108620` branches on camera mode repeatedly while building render/display-list work.

This explained why views materially alter draw sequences.

## 16. Full normalized PSO fingerprint

Partial fingerprint was replaced with a normalized full graphics-PSO hash.

Included:

```text
root signature / pipeline layout contents
all graphics shader bytecode hashes
input layout
blend state
rasterizer state
depth/stencil state
topology
RT/DS formats
sample mask/count
dynamic state declarations
pipeline flags
```

Excluded:

```text
runtime pointers/handles
C++ padding
temporary subobject pointers
```

Bootstrap result:

```text
full_pso = 0x3ef04bb2bb111cce
```

Diagnostic miss frame proved:

```text
the correct full_pso was still present
but first draw count changed from 89 to 94
```

Therefore:

```text
draw count = incidental
full normalized PSO = useful semantic GPU identity
```

## 17. Current production closure

Current algorithm:

```text
not bootstrapped:
    use old known anchor once
    latch current normalized full_pso

every later frame:
    first draw with full_pso == latched full_pso
    and valid RTV/DSV
    → capture SceneClean
```

Validated by user across:

```text
MISSION START transitions
normal maneuvering
first-person/no-cockpit
cockpit
third-person
camera switching
```

This is the first version in the session that survived all previously known failure cases.

## 18. Sidequest: FOV

A quick IDA pass found:

- attractive 60°/90°/120° constants are likely camera rotation limits, not projection FOV;
- `sub_1401FBEC0` is the stronger projection/frustum entry;
- `sub_140202C90` is a likely projection builder and has only one caller.

This was intentionally left for later.

## 19. Design lessons worth keeping

1. **Use semantic CPU seams to calibrate, not necessarily to hook production.**
2. **Do not assume CPU parser scope overlaps D3D12 draw callbacks.**
3. **Do not use runtime object pointers as semantic identity.**
4. **Shader identity alone is not enough when legacy renderers reuse shaders with different state.**
5. **Draw counts and local adjacency are observations, not invariants.**
6. **Normalize PSO state field-by-field; never hash pointers or C++ padding.**
7. **Fail safe visually:** stale capture should degrade to normal output, not freeze/black.
8. **Camera mode can change render-graph/display-list construction, not just matrices.**


## 20. SceneClean routing moved to a shader pass

Direct C++ routing from SceneClean into the ReShade effect target exposed a format mismatch:

```text
SceneClean     = R16G16B16A16_FLOAT
effect target  = R10G10B10A2_UNORM
```

The route moved to:

```text
ACZRouteSceneClean.fx
```

as the first ACZ shader pass.

Sampling FP16 SceneClean and writing the current effect target performs the format conversion without a separate manual copy/conversion path.

## 21. Freshness-based technique admission

Menu/non-game frames should not run the gameplay post stack when no valid clean scene exists.

The bridge therefore keeps ReShade globally enabled but temporarily disables the currently enabled techniques when SceneClean is stale.

Reason for not globally disabling effects:

> the bridge must continue receiving effect callbacks so it can detect recovery and restore the techniques automatically.

This solved the simple stale/menu case but later exposed a larger semantic problem: a fresh render fingerprint is not the same thing as being in active combat.

## 22. OriginalFinal, HUD restore and exact A/B

The bridge added:

```text
ACZ_ORIGINAL_FINAL
ACZ_PROCESSED_CLEAN
```

`OriginalFinal` is copied before effects.

`ProcessedClean` is captured only when the A/B technique is enabled and tracks the latest processed clean state before HUD restore.

The resulting shader order became:

```text
ACZRouteSceneClean
→ scene post-processing
→ ACZRestoreHUD
→ ACZBeforeAfter
```

`ACZRestoreHUD` reconstructs a HUD/UI mask from:

```text
abs(OriginalFinal - SceneClean)
```

after quantizing SceneClean into the 10-bit target domain to suppress FP16→RGB10A2 conversion noise.

This works well in ordinary gameplay.

Known unresolved case:

> Replay can generate scene differences that look like HUD to the simple threshold mask, producing contour/woodgrain-like false positives and flicker.

## 23. Game lifecycle reverse engineering

A mission-end bug remained:

```text
mission finishes
→ movie/result/hangar
→ render detector may still see a compatible HUD PSO
→ combat post stack can be admitted
```

Rather than adding more render fingerprints, RE moved to ACZ's semantic mode layer.

MSVC RTTI exposed classes including:

```text
ModeBase
ModeHolder
ModeGameControl
ModeGameEnd
ModeGameSeq
ModeMoviePlay
ModeDebrief
CModeCampaignResult
CModeAircraftSelect
CModeAircraftData
```

The `ModeHolder` stack operations were recovered:

```text
0x140200FD0 set initial/current
0x140200FF0 replace current
0x140201040 push
0x140201070 pop
0x1402010B0 re-enter current
```

The key GameControl lifecycle was recovered as:

```text
0x14016E0B0 enter
0x14016E4C0 leave
0x14016E880 update
```

and GameEnd as:

```text
0x14016FF00 enter
0x14016FFF0 update
```

`GameControl::update` statically selects `ModeGameEnd` or another return constructor once its mission-exit state completes.

This established a real gameplay lifecycle independent of rendering.

## 24. Lifecycle flag diagnostic

`ModeGameControl::enter` writes:

```text
byte_14032C933 = 1
```

and `ModeGameControl::leave` writes:

```text
byte_14032C933 = 0
```

However additional gameplay code also writes this byte.

Therefore the project deliberately did **not** immediately convert it into a production `combat_active` gate.

Instead, the bridge added a read-only diagnostic:

```text
acz.exe + RVA 0x032C933
```

with transition logging and the shader uniform source:

```text
acz_gamecontrol_active
```

The purpose is runtime correlation through:

```text
combat
pause
replay
mission end
movie/result
hangar
```

before assigning a stronger semantic contract.

## 25. Scene classification supersedes binary admission

The next architecture should not become:

```text
combat = ReShade on
everything else = ReShade off
```

because the hangar/aircraft presentation scene is also a desired post-processing target, just not with the same combat profile.

Target semantic classes:

```text
Combat
Hangar / aircraft presentation
Movie / briefing / debrief / result
Menu / other
```

Open work:

1. correlate the current/top `ModeHolder` mode with the visible hangar;
2. map the hangar state to a proven RTTI/vtable identity;
3. choose between per-mode technique/uniform policy and supported whole-preset switching;
4. verify ReShade 6.8 API support before assuming live preset switching exists.

The detailed handoff is in [`MODE_LIFECYCLE.md`](MODE_LIFECYCLE.md).

## 26. Updated design lessons

The earlier renderer lessons remain valid, plus:

9. **Render-semantic freshness is not game-semantic state.**
10. **Do not solve a lifecycle problem with more PSO heuristics if the game already has a mode state machine.**
11. **Prefer read-only state over detours when it is stable enough.**
12. **Do not promote a lifecycle-looking global to a production contract until all writers are understood or runtime-correlated.**
13. **Scene admission should support multiple valid post-processing policies, not only an on/off combat gate.**

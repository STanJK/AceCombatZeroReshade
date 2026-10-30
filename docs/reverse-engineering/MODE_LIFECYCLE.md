# ACZ mode lifecycle and scene-state reverse engineering

Target:

| Item | Value |
| --- | --- |
| Module | `acz.exe` |
| Architecture | PE64 / x86-64 |
| IDA image base | `0x140000000` |
| SHA-256 | `43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664` |
| RVA | `IDA_VA - 0x140000000` |

This document records the game-mode/lifecycle work that is intentionally separate from the render/HUD PSO detector.

The renderer detector answers:

> did this frame reach the known pre-combat-HUD render boundary?

The mode system should eventually answer:

> what semantic scene is the game currently in: combat, hangar/aircraft presentation, movie/result/menu, etc.?

Those are different questions and should not be collapsed into one render fingerprint.

## 1. RTTI mode inventory

The executable retains useful MSVC RTTI names. Relevant classes observed statically include:

```text
ModeBase
ModeHolder
InitMode

CModeBriefing
ModeMoviePlay
ModeBriefingMovie
CModeCampaignResult
CModeCampaignSelect
ModeCampaignSelectEnd
ModeDebrief
ModeDebriefBase
ModeDebriefVS
CModeFreeMissionMenu

ModeGameControl
ModeGameControlVS
ModeGameEnd
ModeGameSeq
ModeGameSeqReturn
ModeGameSeqReturnGame
ModeGameSeqReturnReload
ModeGameSeqReturnSelect

ModeMissionTitle
ModeMovieViewer
CModeSelector

CModeAircraftSelect
CModeAircraftData
CSelectModel
CModeMainSelect
ModeShop
```

The presence of explicit `GameControl`, `GameEnd`, movie, briefing, debrief and selection modes establishes that ACZ has a semantic mode layer above the renderer.

The exact mapping of every RTTI class to an on-screen state is not yet runtime-proven.

## 2. ModeHolder structure

`ModeHolder` is allocated by `sub_1401FF340`.

Constructor-side initialization:

```text
+0x00  vftable
+0x08  mode slot 0
+0x10  mode slot 1
+0x18  mode slot 2
+0x20  mode slot 3
+0x28  mode slot 4
+0x30  mode slot 5
+0x38  mode slot 6
+0x40  mode slot 7
+0x48  signed current/top index, initialized to -1
```

The destructor walks slots `0..top` and invokes each mode's virtual destructor/cleanup, confirming this is a small mode stack/holder rather than an arbitrary object array.

### ModeHolder vtable operations

| Analysis role | IDA VA | RVA | Behavior |
| --- | --- | --- | --- |
| Set initial/current mode | `0x140200FD0` | `0x0200FD0` | Sets top/index to 0, writes slot 0, calls new mode vfunc `+0x08`. |
| Replace current mode | `0x140200FF0` | `0x0200FF0` | Calls current mode vfunc `+0x10`, replaces top slot, calls new mode vfunc `+0x08`. |
| Push mode | `0x140201040` | `0x0201040` | Increments top, stores new mode, calls new mode vfunc `+0x08`. |
| Pop mode | `0x140201070` | `0x0201070` | Calls current mode vfunc `+0x10`, decrements top, then calls resumed mode vfunc `+0x18` if a mode remains. |
| Re-enter current | `0x1402010B0` | `0x02010B0` | Calls current mode vfunc `+0x08`. |

This gives the following high-confidence lifecycle convention:

```text
mode vfunc +0x08  = enter/initialize
mode vfunc +0x10  = leave/shutdown
mode vfunc +0x18  = resume/re-enter-after-pop
```

Only the call roles above are claimed; original method names are unknown.

## 3. ModeGameControl

### Constructor

`sub_1401796F0`

| Item | Value |
| --- | --- |
| IDA VA | `0x1401796F0` |
| RVA | `0x01796F0` |
| Allocated size | 32 bytes |
| Vtable | `ModeGameControl::vftable` at `0x1402B3F90` |

Initialization:

```cpp
mode->vftable = ModeGameControl::vftable;
mode->field_08 = 0;
mode->field_10 = 0;
mode->field_18 = 0;   // byte at +0x18
mode->field_1C = 0;   // dword at +0x1C
dword_14033BBA4 = 0;
```

The VS constructor `sub_140179120` initializes the same shape with `ModeGameControlVS::vftable`.

### Confirmed vtable slots

| Vtable slot | Function | Role |
| --- | --- | --- |
| `+0x08` | `sub_14016E0B0` | GameControl enter/initialize |
| `+0x10` | `sub_14016E4C0` | GameControl leave/shutdown |
| `+0x20` | `sub_14016E880` | GameControl per-frame state/update |
| `+0x28` | `sub_14016E9B0` | Additional GameControl update/render-side work; exact label open |

### Enter

`sub_14016E0B0` / RVA `0x016E0B0` performs large gameplay-state allocation and initialization.

Near the end it writes:

```asm
0x14016E3CB  mov cs:byte_14032C933, 1
```

It also initializes gameplay/world state and camera-related structures, so this function is a strong semantic combat-entry seam.

### Leave

`sub_14016E4C0` / RVA `0x016E4C0` serializes/copies gameplay result state, clears several gameplay globals and unwinds memory-mark state.

Near the end it writes:

```asm
0x14016E737  mov cs:byte_14032C933, 0
```

Because `ModeHolder::replace` and `ModeHolder::pop` call the current mode's `+0x10` slot before removing/replacing it, this leave function is on the normal GameControl exit path.

### Per-frame update / transition

`sub_14016E880` / RVA `0x016E880` is the `ModeGameControl` vtable `+0x20` function.

The 2026-10-30 same-build headless analysis corrects the earlier interpretation:
`mode + 0x18` is an **initialization-ready** gate, not an exit-complete flag.
While initialization is incomplete it:

- increments `dword_14033BBA4`;
- advances an internal phase index at `mode + 0x1C` through `funcs_14016E966`;
- completes 18 setup callbacks, then sets `mode + 0x18` once the phase counter
  exceeds `0xEF`.

Once `mode + 0x18` is set, it first calls `sub_1400D1780(world)` on each update,
then examines gameplay state at:

```text
*(game_state + 0xA8822) // 690210 decimal
```

and chooses the next mode constructor.

Observed branches:

```text
case 4
case 5
case 8
    → ModeGameEnd constructor sub_1401798C0

case 6
    → constructor selected from off_140291248
```

It then writes the selected constructor into the global pending-mode constructor table:

```text
qword_140328458[dword_14030CAB4]
```

and invokes a `ModeHolder` virtual operation to continue the transition.

This is direct static evidence for a real:

```text
active gameplay / GameControl
    ↓
mission-exit transition
    ↓
GameEnd or another return mode
```

lifecycle independent of render fingerprints.

The campaign/VS setup tables, player allocation and evidence are archived in
[`coop/CAMPAIGN_VS.md`](coop/CAMPAIGN_VS.md). The VS update uses a separate
15-callback table and shares the active mission driver.

## 4. ModeGameEnd

### Constructor

`sub_1401798C0`

| Item | Value |
| --- | --- |
| IDA VA | `0x1401798C0` |
| RVA | `0x01798C0` |
| Allocated size | 16 bytes |
| Vtable | `ModeGameEnd::vftable` at `0x1402B4000` |

### Confirmed vtable slots

| Vtable slot | Function | Role |
| --- | --- | --- |
| `+0x08` | `sub_14016FF00` | GameEnd enter/initialize |
| `+0x20` | `sub_14016FFF0` | GameEnd per-frame transition |

`sub_14016FF00` chooses a selector/return path from mode/game-state tables and pushes a `CModeSelector`.

`sub_14016FFF0` continues into return/reload/sequence constructors such as `sub_140178530` (`ModeGameSeq`) depending on campaign state.

Therefore entering `ModeGameEnd` is already semantically later than active combat.

## 5. GameControl flag at RVA 0x032C933

Global:

| IDA VA | RVA |
| --- | --- |
| `0x14032C933` | `0x032C933` |

The obvious lifecycle writes are:

```text
GameControl enter  0x14016E3CB → 1
GameControl leave  0x14016E737 → 0
```

However this byte is **not yet accepted as a pure `combat_active` flag**.

Additional writes exist inside gameplay code:

- `sub_1400CE880` writes both 0 and 1 based on internal gameplay/control state;
- `sub_1400D1780` writes 0 in at least one gameplay branch;
- `sub_14021D4C0` reads the byte and compares/mirrors it against `byte_14032C932`.

This makes the current best interpretation:

> high-confidence GameControl/control-active lifecycle signal, but potentially allowed to toggle inside an active mission.

It must be runtime-correlated before it becomes a production scene-state contract.

## 6. Current bridge diagnostic

The production add-on currently contains a **read-only diagnostic probe**:

```cpp
GetModuleHandleW(nullptr) + 0x032C933
```

It does not patch ACZ and it does not currently participate in effect admission.

When the value changes, the bridge logs:

```text
ACZRenderBridge: GameControl flag transition
    value=<0|1>
    previous=<...>
    present=<...>
    rva=0x32c933
```

The bridge also exposes:

```text
source = "acz_gamecontrol_active"
```

which `ACZSceneClean.fx` displays as the read-only `GameControl Active` diagnostic.

## 7. Why SceneClean freshness alone is insufficient

The current render detector is intentionally render-semantic:

```text
known combat-HUD full PSO appears
→ capture pre-HUD SceneClean
```

It does not know why that PSO appears.

Observed problem:

```text
mission finishes
→ movie/result/hangar transition
→ a compatible render fingerprint may still appear
→ SceneClean becomes fresh
→ combat ReShade stack can be admitted incorrectly
```

Therefore production admission eventually needs two independent axes:

```text
render boundary valid?
AND
semantic scene/mode appropriate for this profile?
```

A binary `SceneCleanFresh && GameControlActive` gate may be sufficient for a combat-only profile, but it is not the final architecture because the hangar should also be post-processed with a different profile.

## 8. Desired scene classification

The next architecture should prefer a small semantic scene class rather than a single combat boolean:

```text
Combat
Hangar / aircraft presentation
Movie / briefing / debrief / result
Menu / other
```

Possible policy:

```text
Combat
    → combat preset / technique set

Hangar
    → hangar preset / technique set

Movie / menu
    → no gameplay post stack, or a dedicated lightweight stack
```

This classification should be driven by ACZ mode state and only secondarily by render fingerprints.

## 9. Hangar-state reverse engineering: OPEN

No class has yet been proven to mean the visible hangar/aircraft presentation scene.

Static candidates worth testing include:

```text
CModeAircraftSelect
CModeAircraftData
CSelectModel
CModeMainSelect
CModeCampaignSelect
```

These are candidates only.

Do not equate any of them with the hangar until runtime correlation or a direct construction/transition chain proves the mapping.

Preferred next investigation:

1. identify the current/top `ModeHolder` mode object during known screens;
2. record its vtable address while entering:
   - active combat;
   - mission-end movie/result;
   - hangar/aircraft screen;
   - main menu;
3. map runtime vtable addresses back to RTTI classes;
4. derive a stable scene-class classifier.

If direct access to the live `ModeHolder*` is inconvenient, a temporary diagnostic at its replace/push/pop operations is acceptable, but production should prefer read-only state where possible.

## 10. ReShade profile switching: OPEN

The bridge already proves that individual techniques can be changed live using the effect runtime:

```cpp
runtime->get_technique_state(...)
runtime->set_technique_state(...)
```

So a per-mode **technique set** is possible without changing the selected preset file.

What is not yet documented or proven in this project is whether the installed ReShade 6.8 add-on API exposes a supported live whole-preset/profile switch suitable for this bridge.

Two future implementation paths:

```text
A. Mode-aware technique/uniform policy
   - keep one preset loaded
   - enable/disable technique groups per ACZ scene class
   - optionally update uniforms from the add-on

B. Whole-preset switching
   - only if a supported ReShade API path is verified
   - must preserve effect-runtime stability and avoid reload churn
```

Do not assume path B exists until the API/source is checked.

## 11. Runtime validation checklist

For `0x032C933`, collect transitions across one complete route:

```text
hangar / pre-sortie
→ mission load
→ active combat
→ pause
→ replay if available
→ mission completion
→ result / movie
→ hangar
```

Expected useful output:

```powershell
Select-String `
  -Path D:\Games\ACZero\ReShade.log `
  -Pattern "GameControl flag transition"
```

Decision rule:

- stable 1 throughout active combat and 0 outside: candidate direct combat gate;
- short internal 0/1 pulses: add hysteresis/debounce or classify from mode object instead;
- substantial internal chatter: do not use the raw byte for admission.

## 12. Production fallback if read-only state is insufficient

If no stable read-only mode discriminator is found, the strongest already-identified lifecycle hooks are:

```text
RVA 0x016E0B0  ModeGameControl enter → combat entered
RVA 0x016E4C0  ModeGameControl leave → combat exited
```

These are preferable to hooking an arbitrary mission-result function because `ModeHolder` itself guarantees the leave slot is called on normal replace/pop transitions.

This is a fallback, not the current implementation.

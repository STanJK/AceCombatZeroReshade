# Reverse-engineering plan: from observed seams to complete co-op contracts

Baseline and evidence labels: [co-op research README](../reverse-engineering/coop/README.md).
This document records both the work executed in this investigation and the
remaining experiments required to turn static locations into usable contracts.

## 1. Executed passes

| Pass | Starting evidence | Work performed | Result |
| --- | --- | --- | --- |
| P0 | Existing renderer/input/mode documentation | Read repository documentation and relevant source; pin main commit and SHA-256; create `mp` | Same executable confirmed; older lifecycle interpretation identified for correction |
| P1 | GameControl, input and camera roots | Whole-image analysis; export function/direct-call/data-reference/string indexes; decompile initial roots | Frame/input/mode/mission hierarchy; two raw lanes |
| P2 | RTTI and setup tables | Validate x64 COL self-RVAs, reconstruct 404 vtable candidates, follow campaign and VS setup callbacks and UI binding table | Player allocation and differing setup sequences; `setControlPlayer` classified as UI broadcast |
| P3 | Player/context allocation and actor loops | Follow count/stride writes, actor binding, model state, pause/replay paths and history recorder | `0x27A0` player contexts, `0x520` actors, unit arrays, setup and update ownership |
| P4 | Unit/weapon RTTI, damage callers, world pointer | Follow vtables, damage/death, targeting and world consumers; export weapon family representatives | Damage/HP/attacker flow and initial group construction recovered; runtime spawn/despawn still open |
| P5 | History and determinism leads | Inspect state/event recording; identify LCG constants, seed routine, caller scope and outer frame order; cross-check key ABIs in assembly | Bounded history, CRT-style random state and broad consumers; deterministic networking not established |
| P6 | Whole collected evidence | Annotate three storage-only input/initializer ABIs; regenerate selected decompilation and full index; package hashes, usage ledger and patch plan | Initial 248 selected functions exported; final static index 4,792 functions |

| P7 | Playback reader and timed weapon records | Follow `1B7480/1B9400`, playback preparation, pose decoder/interpolator and three launch emitters; verify critical instructions | Final corpus 255 functions, 90 focused contracts; pointer-bearing selective replay distinguished from exact rollback |

P0–P7 are static/local-tool work. No runtime gate below is marked passed merely
because an address or a C-like listing exists. Individual exported functions
receive a review-depth label in the usage ledger; supporting exports are not all
claimed to have complete semantic interpretation.

## 2. Required contract matrix

Each requirement must end in an address/dispatch identity, typed arguments,
thread/lifetime rules, side effects, a trace, and a falsifiable acceptance test.

| ID | Contract | Current roots / result | Status and next observation |
| --- | --- | --- | --- |
| RE01 | Build identity / address resolver | Exact SHA, PE base, RVAs, candidate prologues | Static complete; startup must reject every other EXE |
| RE02 | Live GameControl instance/world | `16E0B0`, `16E4C0`, `16E880`; world `this+8` | Prove thread, nested VS wrappers and epoch transitions |
| RE03 | Simulation boundary / tick | `0D1780`, `0CE880`, `1FF820`, `W+A878C` | Trace pause, slow motion, frame drops, replay and result states |
| RE04 | Local/remote input ownership | `188A80 → 188180 → 187390 → 201DC0`, map `32C8F0` | Inject neutral P2 sample after raw normalization and before device/action mapping; verify presence and edge behavior |
| RE05 | Campaign P2 resource allocation | `0C6A50`, campaign `16EB20`, VS `16F6C0` | Recover all 10 argument positions and valid two-element selections; guard backing data |
| RE06 | Initial human aircraft/group creation | `135B50`, `12C410`, `135CB0`, `12C520`, `0CBCC0` | Mission definitions needed; add one friendly actor without repurposing scripted actors |
| RE07 | Runtime entity identity/spawn/despawn | Actor selectors/ID, `132240`, `115C20`, `117A10` | Find creation/reuse/free boundaries, generation, callbacks and cleanup |
| RE08 | Flight state / integrator | `1040C0`, `10EAD0`, context/actor vector copies | Identify velocity/angular state, coordinate units and all producer/consumer fields |
| RE09 | Weapons and target selection | `0C11C0`, `10C9A0`, `13D140`, `141200`, `13ACE0`, controller vtables | Trace gun, missile and every supported special weapon: launch/owner/target/hit/expiry |
| RE10 | Damage and kills | `118040`, `117A10`; actor `428`, `23A/23B` | Typed ABI, recursive damage, assists, invulnerability, scripted death and attribution |
| RE11 | AI allegiance/target rules | Group `15D`, table `2ACCC0`, `1338C0` | Enumerate every team/category consumer; prove both humans are friendlies to campaign AI |
| RE12 | Mission VM/events/objectives | `12BF60`, `0D1780`, `W+A8318`, `W+A8822` | Recover VM instruction/event boundaries and serialize one authoritative event order |
| RE13 | RNG/time equality | `242630`, `24265C`, configuration/tick fields | Trace thread-specific RNG draws/seeds and clock inputs; demonstrate determinism or keep authority |
| RE14 | Camera/HUD selection | `1040C0`, cameras `+10B0/+1270`, `0D2580` | Bind guest view to P2 at full resolution while host stays P1; audit RNG and sound listener effects |
| RE15 | History/restore completeness | `019EF0`, `01A2A0`, `1B7CE0`, `1B6480/1B9400` | Selective capture/playback and pose interpolation recovered; prove complete restore before offering rollback or join in progress |
| RE16 | Mission enter/leave/retry barriers | Mode tables, return modes and `16E4C0` | Both peers acknowledge readiness/epoch; drain commands before arena release |
| RE17 | Result/campaign/save ownership | `16E4C0`, `16FF00`, `16FFF0`, sequence constructors | Trace result computation, unlocks and disk write; prevent divergent/duplicate commits |
| RE18 | Transport/session | SDK strings/import audit | Add transport; no recovered game networking contract accepted |

## 3. Runtime experiment order

### R0 — read-only trace harness

Capture build hash, module base, mode/vtable, mode pointer, readiness, world
pointer, OS thread ID, local serial, game tick candidate, player/group counts,
actor binding, position, HP, phase and selected action edges. Log a bounded ring
and flush asynchronously. The render add-on can display telemetry, but must not
become the simulation mutator. Hash-check before enabling any game-RVA detour.

Artifacts: timestamped trace, scenario description, RVA/prologue manifest, call
stack samples and an explicit assertion table. Pass only if the same lifetime
rules survive enter/pause/replay/end/retry/return-to-menu.

### R1 — two humans in a campaign, locally

Obtain mission definitions/resources from the game install. Compare one
ordinary campaign definition with a stock VS definition before changing either.
Construct complete P2 loadout/resource data and add a separate friendly actor.
Keep script-owned wingmen/bosses under their native ownership.

Trace construction size calculation, allocation, group creation, player binding,
faction assignment and teardown. Prove independent throttle/roll/fire, distinct
HP/ammo, correct AI behavior and a clean result/retry. Test at least an airborne
start, ground-target mission and a scripted mission before progressing.

### R2 — state producer/consumer closure

For every proposed serialized field: record its writers, consumers, update
phase, precision, valid range and pointer-free representation. Verify pose
correction does not get overwritten by a second authoritative copy elsewhere.
Trace an ordinary missile and a special weapon through spawn → target → hit →
damage → effect → cleanup. Repeat with terrain collision, AI hits and scripted
death. Identify the exact point where an actor slot becomes reusable.

### R3 — mission and persistence closure

Observe an objective event from the mission VM through world effects and result
transition. Capture timers, radio/cutscene barriers, spawn waves, boss phases,
supply/rearm and mission-specific state. Decide which pieces the client can run
for presentation and which must be suppressed/replayed from the host.

Keep save writes disabled for the guest until the campaign ownership policy is
implemented. Prove one result commit for a mission epoch, including retry and
network timeout during the result transition.

### R4 — network and complete campaign acceptance

Only after R0–R3 pass: run two processes with a local transport, then network
impairment tests and finally remote peers. Compare authoritative entity/mission
checksums, event acknowledgements and score/results at every checkpoint. Capture
all campaign mission/route IDs from actual game data; do not infer route
coverage from visible mission names or a single normal playthrough.

## 4. Search and failure strategy

- Direct-call absence is not a negative result for a vtable function. Use the
  COL/vtable inventory and incoming data references.
- A class named `ObjPlane` can be a presentation object; follow the actor/context
  producer before declaring it a flight integrator.
- An apparently useful callback can be a UI or zero-result stub. `getMissionTime`
  / `getMissionScore` bind to `0x1EF650`, which writes zero to the result slot.
- Ghidra's `decompile_completed=true` means a listing was generated, not that its
  prototype, vector types or exception paths are correct.
- Inspect `0x16EB20.asm` / `0x16F6C0.asm` for initializer stack arguments. Do not
  implement a hook from the six-argument first-pass listing.
- If a mission definition cannot safely add a friendly actor, stop the P2
  construction milestone and document that exact blocker; do not steal an NPC
  and call the campaign supported.

## 5. Exit criteria for an implementation-ready function

An inventory row becomes callable only after all of these are attached:

1. Same-build RVA, prologue and enclosing function boundary.
2. Windows x64 ABI: used register widths, XMM arguments, stack arguments,
   return register and cleanup behavior.
3. Ownership/lifetime and allocator contract for every pointer.
4. Required thread, ordering and reentrancy rules.
5. Side effects and original-call/trampoline obligations.
6. At least one controlled experiment plus a failure/teardown experiment.

Remaining unresolved rows stay in the implementation specification as hard
dependencies. “All required functions identified” is not claimed by this static
investigation.

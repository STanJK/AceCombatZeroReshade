# Findings from reading the collected code

## 1. Initialization and mission exit were mixed in the earlier explanation

The decisive evidence is the early `!mode[0x18]` branch in `16E880`: it advances
the setup table and returns before `0D1780`. The callback bodies load resources,
allocate players and wire the world. After readiness, `0D1780` executes before
the phase is inspected for GameEnd/return. This changes where a co-op load barrier
belongs: after valid world setup, before the first accepted mission tick.

## 2. Existing two-player scaffolding is substantial but mission-dependent

`0C6A50` has real count-based allocations; `0CBCC0` wires all contexts and actor
links; the active world step iterates them. VS also has distinct initialization
tables, resource IDs, difficulty/rule logic and return modes. Reuse the common
mechanisms and supply campaign-correct data instead of copying VS mode wholesale.

## 3. The second player's aircraft must exist in the mission graph

At binding, context i is connected to group i's first actor. Context count does
not by itself add that friendly actor, resource definition or script identity.
The native sizing/construction order and group-reference fixups make shallow
copying unsafe. This is the most important prerequisite before online work.

## 4. Input is a pipeline with history

Raw input normalization, device selection, mapping and edge/repeat tracking are
separate. Network injection after pressed-edge construction loses the native
history contract; applying the same sample twice creates different outcomes.
The recovered order gives a useful injection window but still requires proof
of device binding and the accepted simulation tick.

## 5. A player update is more than a flight integrator

`1040C0` mixes view state, controls, targeting, weapon/presentation updates,
effects and actor lookup. Some movement dependencies live in subobjects and
later helpers. Serializing only its apparent position fields cannot certify a
correct co-op player. The usage catalog deliberately avoids naming every scalar
“speed”, “HP” or “FOV” without its producer/consumer evidence.

## 6. Damage is an event with side effects

`118040` proves health reduction at actor `+428`, but also assigns attacker
selectors, changes flags, affects score, handles invulnerability/script branches,
uses RNG and can recurse. A guest that independently runs it can diverge even
while rendered positions appear synchronized. Authoritative event IDs and
exactly-once application are necessary design contracts.

## 7. History contains useful structure, with explicit loss of detail

`1B7CE0/01A2A0` preserve current/previous vectors and selected actor events.
The reader `1B9400` applies/interpolates those records and replays weapon/death
events. Decimation, bounded windows, synthetic playback health and native resource
pointers show that this is not an exact full-world checkpoint. It informs event
taxonomy, but equality tests are still required for rollback/resync/late joining.
See [the reader/weapon analysis](../reverse-engineering/coop/PLAYBACK_AND_WEAPONS.md).

## 8. Randomness crosses system boundaries

The actual LCG and seed writer are small, but their consumers are broad.
Gameplay, damage, AI and presentation/effect paths can consume the same CRT-style
thread state. A shared seed is not a determinism certificate. Trace calls/seeds
and view-dependent paths before choosing lockstep or resimulation.

## 9. Names are useful search roots, not contracts

`setControlPlayer` forwards to a UI-listener broadcast. Two mission-query
bindings point to a result-zeroing stub. Four networking interface names have no
direct references in the bounded index. Each was followed to its actual body or
reference boundary before being excluded from the co-op API assumptions.

## 10. Class-specific vtables and ABI recovery matter

ModeHolder's enter/leave convention cannot be applied to every class. Unit slot
0 is an initialization routine in this binary. Leaf/tail wrappers missing from
the initial function table required explicit executable seeds. The ten-position
player initializer needed assembly to recover its full argument storage.

## 11. What the broad supporting corpus contributes

The selected weapon-family vtables and their implementations establish concrete
research roots for launch/update/hit/cleanup work. World-pointer consumers expose
AI/view assumptions about the selected group. Related reset/result functions
show that world lifetime and persistence span multiple paths. Their listings are
archived and structurally inventoried, but unresolved semantics remain O in the
per-function ledger rather than being promoted to supported APIs.

## 12. Launch events expose both reuse opportunities and hazards

The history consumer identifies three native launch roots: a 16-slot projectile
pool, a controller-family dispatcher, and a 32-slot scatter pool. Their emitted
records retain source/target selectors and a native resource pointer; the scatter
path also consumes RNG. They are useful native adapter seams, but cannot be
transmitted as raw packets or treated as complete projectile lifetimes.

## 13. Implementation consequence

The strongest path is a small read-only runtime harness, then local two-human
campaign construction, then an authority-aware network layer. The hard remaining
work is native lifetime, mission data and authoritative side effects. The
[implementation book](../mp/COOP_PATCH_IMPLEMENTATION.md) turns each into a
dependency, artifact and acceptance gate rather than assuming that online co-op
follows automatically from two input slots.

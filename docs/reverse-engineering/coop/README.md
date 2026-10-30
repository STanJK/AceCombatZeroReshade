# Two-player campaign co-op research

Research date: **2026-10-30**. Branch: **`mp`**. Baseline commit:
`56cb5594fe199e93129380ce76dd5ae42345256c`.

Target SHA-256:
`43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664`.
Preferred image base: `0x140000000`. Use module-relative RVAs under ASLR.

## What this investigation establishes

The supplied executable can be analyzed with **Ghidra 12.2 Headless / JDK 25**.
It has two input lanes, count-based player-context allocation, distinct campaign
and VS initialization sequences, and a shared entity/mission update path. These
are substantial starting points for co-op. They do **not** establish that campaign
data accepts a second human, that a network replication protocol already exists,
or that two independent instances remain deterministic.

This branch is a reverse-engineering dossier and implementation specification.
It does not contain an installed or playable co-op patch. No Windows gameplay,
second-client session, or complete campaign playthrough was performed in this
Linux environment. Missing DLLs/assets were not synthesized to claim a runtime
result. The EXE and its license files are not included in the repository.

## Evidence vocabulary

| Label | Meaning in the new co-op documents |
| --- | --- |
| **S: static-confirmed** | The stated instruction, offset, table entry, branch, or direct call is present in this exact executable. |
| **H: semantic inference** | A role is supported by its data flow, but its full gameplay meaning or parameter units need runtime confirmation. |
| **O: open** | A required contract is not recovered or not validated sufficiently for implementation. |
| **D: proposed design** | New patch behavior, packet format, policy, or acceptance target; not an existing game feature. |
| **R: runtime-confirmed** | Reserved for recorded gameplay traces. This investigation adds **no new R claims**. |

The older repository uses “Verified” for a mixture of static and runtime facts.
Its previous render observations remain prior evidence, not new co-op runtime
validation. `FUN_...`, proposed names, decompiler parameter types, and structure
names are research labels rather than original symbols.

## Read order

1. [Player, input and entity layout](PLAYER_STATE.md)
2. [Simulation, history, RNG and synchronization boundaries](SIMULATION_AND_SYNC.md)
3. [Campaign/VS initialization and lifecycle](CAMPAIGN_VS.md)
4. [Playback and weapon launch consumers](PLAYBACK_AND_WEAPONS.md)
5. [Function and capability inventory](FUNCTION_MAP.md)
6. [Evidence and reproduction](EVIDENCE.md)
7. [Executed research plan](../../mp/REVERSE_ENGINEERING_PLAN.md)
8. [Code usage and interpretation](../../usage/README.md)
9. [Co-op patch implementation specification](../../mp/COOP_PATCH_IMPLEMENTATION.md)

`evidence/decompiled/` contains selected pseudocode, corresponding instruction
listings, and call/reference metadata. The full program index is retained as a
compressed research artifact; its direct-call graph is not a complete graph of
virtual dispatch. [Archive manifest](ARCHIVE.md) records the final snapshots.

## Corrections to earlier assumptions

- `ModeGameControl +0x18` gates **initialization completion**, not mission-exit
  completion. `+0x1C` advances 18 setup callbacks; after readiness, the update
  calls the actual mission state driver. See [CAMPAIGN_VS.md](CAMPAIGN_VS.md).
- `setControlPlayer` resolves to a UI listener broadcast. Its name alone does not
  identify a flight-control ownership API.
- Four `SteamNetworking*` version strings were found, but the initial whole-image
  defined-string/data-reference indexes found no references to them. A working
  gameplay networking layer has not been recovered.
- A history/event recorder **and selective playback reader** are present. The
  reader interpolates pose and replays weapon/effect/death events, but is not a
  demonstrated exact rollback save state or network serializer.

## Scope and completion boundary

The deliverable covers a broad static pass through the identified player and
simulation seams, followed by focused passes and an implementation contract.
There is no defensible denominator for “all player code” from a stripped EXE;
export counts must not be presented as a percentage of gameplay understood.
The inventory explicitly retains unresolved contracts (spawn lifetime, campaign
asset expansion, mission authority, camera isolation and replay completeness).
They are blocking acceptance gates, not silently completed functions.

# Campaign/VS initialization and lifecycle

## 1. A corrected interpretation of GameControl

The same-build disassembly and recovered initializer calls clarify the older
[mode lifecycle document](../MODE_LIFECYCLE.md).

| Object offset | Actual observed use |
| --- | --- |
| GameControl `+0x08` | World pointer; allocated as `0xA8940` bytes by enter |
| `+0x10` | Separate `0x1C0` view/camera object |
| `+0x18` | Initialization-ready byte; initialized to zero |
| `+0x1C` | Setup callback index; initialized to zero |

`0x16E880` behaves structurally as follows:

```cpp
if (!mode->ready) {
    ++phase_counter;
    if (mode->setup_index < 18) {
        if (campaign_setup[mode->setup_index](mode)) ++mode->setup_index;
        mode->ready = false;
    } else {
        mode->ready = phase_counter > 0xEF;
    }
    return;
}
MissionDriver(mode->world); // 0x0D1780
// Then inspect W+0xA8822 and schedule the corresponding return/end mode.
```

VS `0x16F550` uses **15** callbacks and a different completion gate. Both modes
ultimately call `0x0D1780`. Their auxiliary slot shares `0x16E9B0`, which dispatches
scene packet construction `0x0D2580` after readiness.

## 2. Setup tables (S)

The campaign callback table starts at VA `0x140290DE0`; its 18 entries are:

```text
16EA60 16EA70 16EAB0 16EAE0 16EB20 16EC40 16EC80 16ECB0
16ECF0 16ED10 16EA90 16EB00 16EC60 16ECD0 16EDD0 16EF50
0A3FA0 16F080
```

These numbers are RVAs. The VS table starts at VA `0x140290E70` and has 15 entries:

```text
16EA60 16EA70 16F640 16EAE0 16F6C0 16EC40 16F7E0 16ECB0
16EA90 16EB00 16EC60 16ECD0 16F860 0A3FA0 16FA80
```

The next pointers after entry 14 in the VS region belong to other data; they must
not be called as a continuation of the 15-element table.

| Campaign | VS | Difference relevant to co-op |
| --- | --- | --- |
| `0x16EAB0` | `0x16F640` | Select different mission/resource identifiers; VS uses the `0x20..` family. |
| `0x16EB20` | `0x16F6C0` | Build loadout argument data; both invoke `0x0C6A50`. VS explicitly supplies two player selections. |
| `0x16EC80` | `0x16F7E0` | Different mission/resource load paths. |
| `0x16EF50` | `0x16F860` | Common world wiring through `0x0CBCC0`, with different difficulty/VS options. |
| `0x16F080` | `0x16FA80` | Apply per-player controls/options; VS additionally configures VS rules/state. |

`0x16EB20` derives its count as `1 + ((mission_id - 0x20) <= 9)` using unsigned
comparison. This is a mission-family decision, not a discovered campaign co-op
toggle. Its call-site assembly provides ten argument positions (including an
unused/hole position), while the first decompiler pass displayed only six.
`ApplyKnownInputContracts.java` records the storage annotation used in final
exports. Any semantic names for the ten arguments still need validation.

## 3. Safe second-player construction requirements (D)

Before accepting player count 2 in an ordinary campaign mission:

1. Build two complete sets of loadout and initialization arrays with valid
   lifetimes; account for every argument and every count-based read.
2. Extend/copy mission definitions through their actual data format so that a
   new friendly human-owned actor/group exists before size calculation.
3. Re-run the native sizing/constructor/wiring order, rather than shallow-copy
   `0x27A0` contexts or `0x520` actors containing owning pointers.
4. Bind player slots explicitly. The stock wiring binds `P[i]` to group `i`'s
   first actor; validate or replace this mapping for campaign assets.
5. Preserve script-owned wingmen and bosses. In particular, do not assume the
   second visible aircraft can be taken over without breaking story scripts.
6. Establish correct allegiance, collision, targeting, score attribution,
   HUD/radar identification, resource loading and both camera ownership paths.
7. Test leave/retry/reload without a leaked arena mark or stale entity mapping.

The first **runtime** gate is a local two-human campaign mission, before any
Internet networking. A successful stock VS session is insufficient evidence for
this gate.

## 4. Mode identity and lifetime

RTTI/COL validation reconstructs:

| Class | Vtable VA | Slots `+0x08 / +0x10 / +0x20 / +0x28` |
| --- | --- | --- |
| `ModeGameControl` | `0x1402B3F90` | `16E0B0 / 16E4C0 / 16E880 / 16E9B0` |
| `ModeGameControlVS` | `0x1402B3FC8` | `16F470 / 16F4C0 / 16F550 / 16E9B0` |

Entries in the slot column are RVAs. VS enter calls the common enter and adds
VS-specific transitions; VS leave calls the common leave after extra cleanup.
Do not install nested hooks that increment/decrement mission epochs twice.

RVA `0x32C933` is written by enter/leave **and** by normal mission state branches.
Use it as telemetry, not the sole proof of a live world or a safe network-write
window. Track the mode object, readiness, world lifetime and the authoritative
tick explicitly.

`0x16E4C0` copies campaign/result fields and releases arena-style state. Co-op
must invalidate queued commands before this work frees world-owned objects.
`0x16FF00` / `0x16FFF0` and the sequence-return constructors form transition
research roots, but complete save/result ownership across all routes is O.

## 5. Current blockers

- Campaign mission/unit/loadout assets are not present in the supplied files.
- No gameplay traces or PDB were supplied; none were fabricated.
- Ordinary campaign dual-player construction, native spawn/despawn ownership,
  guest-only camera selection, mission result replication and complete save
  policy remain runtime gates.
- No exact network protocol or existing online co-op entry was recovered.

These blockers affect which patch can be implemented reliably. The research
plan gives each a concrete observation, artifact and pass condition.

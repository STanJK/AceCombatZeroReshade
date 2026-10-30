# Player, input and entity state

Build and confidence rules: [README](README.md). All offsets below are bytes.
`W` means the world pointer stored in `ModeGameControl +0x08`; `P[i]` is a player
context; `G[g]` is a unit/group; `A[g,a]` is an actor record. These are separate
objects and must not be cast interchangeably.

## 1. Input path (S)

| Operation | RVA | Concrete evidence |
| --- | --- | --- |
| Frame/mode driver | `0x1FF820` | Calls `0x201DC0` before holder virtual calls `+0x30` and `+0x38`. |
| Poll/normalize/bind inputs | `0x201DC0` | Calls `0x188A80`, then `0x188180`; binds the two selected device pointers into action maps. |
| Read physical devices | `0x21D4C0` | Called by the raw normalizer; combines platform/controller sources. |
| Raw two-lane normalization | `0x188A80` | Writes lane 0 at raw base and lane 1 at raw base `+0x24`. |
| Device/action rebuild | `0x188180` | Uses normalized device records of stride `0x50`; selects logical slots at `+0x140/+0x148`. |
| Analog/button conversion | `0x188550` | Converts raw bytes and constructs held bitmaps at device `+0x24/+0x28`. |
| Edge/repeat calculation | `0x187390` | Calculates `pressed = held & (held ^ previous)`, then stores previous held state. |
| Action query | `0x187C80` | Uses logical player index in `DL`, action ID in `R8B`, and the mapping root at RVA `0x32C8F0`. |

Global pointer locations:

| RVA | Meaning | Confidence |
| --- | --- | --- |
| `0x32C8E0` | Raw input block pointer | S |
| `0x32C8E8` | Normalized device records / selected-device container | S |
| `0x32C8F0` | Logical gameplay-action mapping root, two selected pointers at `+0/+8` | S |
| `0x33ABE0` | Port-side aggregate lane 0; lane 1 begins at `+0x30` | S |

Raw input lane fields observed in `0x188A80`:

| Lane-relative offset | Observed operation |
| --- | --- |
| `+0x00..03` | Four converted axis bytes; neutral/scale constants require runtime calibration. |
| `+0x04..0B` | Button-derived bytes, written as `0x00/0xFF`. |
| `+0x0C..0F` | Four analog/button magnitudes from the aggregate source. |
| `+0x20` | 16-bit button field. |
| `+0x22` | Device/status conversion. |
| lane stride `0x24` | Second lane repeats the same operations at `+0x24..46`. |

Device `+0x38/+0x3C` contains previous held bitmaps, `+0x40/+0x44` pressed-edge
bitmaps, and `+0x48/+0x4C` repeat-related bitmaps. Do not forward an old edge mask
repeatedly over the network: rebuild edges once for each accepted simulation tick.
`0x187C80` returns the logical result in **AL**; upper return bits are not a
boolean contract. Its unused-looking RCX and several other Ghidra signatures are
ABI recovery issues, not parameters to copy into a DLL typedef.

**D: preferred first injection experiment:** replace the remote raw lane after
`0x188A80` and before `0x188180`. Device presence/selection still needs validation;
copying axes alone may leave logical slot 1 unbound. Run the normalizer/history
path once, on the simulation thread. Network callbacks must only enqueue data.

## 2. Player allocation and binding (S)

`0x0C6A50` writes `W+0xA87E4` and allocates:

| Allocation | Destination | Size expression |
| --- | --- | --- |
| Player contexts | `W+0xA8248` | `count * 0x27A0`, alignment `0x10` |
| Per-player object/interface records | `W+0x671C0` | `count * 0x70` |
| Pointer array A | `W+0x67180` | `count * 8` |
| Pointer array B | `W+0x67188` | `count * 8` |
| Additional per-player view storage | `W+0xA8218` | `count * 0x3A0` |

```cpp
// Structural pseudocode only; not an ABI-safe implementation.
P(i) = *(byte **)(W + 0xA8248) + i * 0x27A0;
player_count = *(uint8_t *)(W + 0xA87E4);
```

`0x0CBCC0` initializes references inside every context, including:

| Player offset | Observed relationship | Confidence |
| --- | --- | --- |
| `+0x2040` | `&W[0x697B8]`, the group-manager/table root | S |
| `+0x20A1/+0x20A2` | Group/actor byte selectors used to resolve the controlled actor | S |
| `+0x1FC0` | Pointer to world subobject `W+0x240` (corrected during execution audit) | S |
| `+0x10B0/+0x1270` | Camera objects passed to the existing matrix updater | S |
| `+0x2094` | Camera-mode byte, cycle `0 → 2 → 1 → 0` | S; view labels from earlier repository runtime work |
| `+0x2058` | Mixed gameplay/view/control flags; e.g. bit 1 gates portions of player processing | S; full bit meanings O |
| `+0x20C8` | Set from `player_count > 1` | S; exact UX role H |
| `+0x70` | Position-like float4 used by movement/view/effect paths | H |
| `+0x80` | Orientation/transform input to matrix helpers | H; representation/units O |
| `+0x1640` and nearby | Flight-related scalars copied to HUD/model state | H; do not label these HP |

The controlled actor is resolved in `0x1040C0` using:

```cpp
manager = *(byte **)(P + 0x2040);
group = (*(Group ***)manager)[P[0x20A1]];
actor = *(byte **)(group + 0x110) + P[0x20A2] * 0x520;
```

At initial binding, `0x0CBCC0` stores `P[i]` in the **first actor of group i**
at actor `+0x1B8`. Consequently a campaign cannot simply inherit VS binding:
the asset-defined group at index 1 must be checked before it becomes human-owned.
An ordinary wingman/enemy group must not accidentally be reassigned to the guest.

## 3. Group and actor layout

| Object/offset | Observed use | Confidence |
| --- | --- | --- |
| `W+0x697B8` | Pointer to group-pointer array; also beginning of manager subobject | S |
| `W+0x697EC` | Byte group count (`manager+0x34`) | S |
| group `+0x110` | Pointer to actor record array | S |
| group `+0x118` | Signed actor count | S |
| group `+0x15C` | Group selector/identity byte used in lookups | S |
| group `+0x15D` | Category/allegiance discriminator used in targeting/damage rules | S; enum labels O |
| actor stride | `0x520` | S |
| actor `+0x1B8` | Optional player-context pointer | S |
| actor `+0x1F0`, `+0x1F4`, `+0x1FC` | Mixed active/status/event bitfields | S; complete meanings O |
| actor `+0x228` | 16-bit identity-like value used by the history path | S; generation semantics O |
| actor `+0x234/+0x235` | Group/actor selector pair | S |
| actor `+0x236/+0x237` | Target selector pair in observed lookup paths | H |
| actor `+0x23A/+0x23B` | Last attacker selector pair copied by the damage routine, or `0xFF/0xFF` | S/H |
| actor `+0x258` (`600` decimal) | Current position-like float4 | H; supported by distance calculations and copy sites |
| actor `+0x268` | Current orientation-like float4 | H |
| actor `+0x288/+0x298` | Previous copies of those vectors | S |
| actor `+0x428` | Signed 16-bit health-like value reduced by damage and tested against zero | S/H |

Never ship these memory blocks directly. They contain pointers, vtables,
renderer references, local resource ownership, allocator state, and transient
bits. A patch needs an explicit field schema and its own entity identity with
mission epoch and spawn generation.

## 4. Damage, death and allegiance

`0x118040` accepts an actor, a group-related context, optional hit-suppression
storage, an integer damage magnitude, a damage-class byte, an optional source
actor, and another event/reason byte (inferred order; see the assembly before
calling). It applies guards and scaling, subtracts from actor `+0x428`, records
the attacker pair, changes flags, updates score-like state, and can recursively
propagate damage. It calls `0x117A10` on a lethal path.

`0x117A10` checks actor flag bit `0x02`, generates effects/events and updates
death-related state. It is **not** a proven destructor or free-list release API.
The companion `0x115C20` and additional callers also participate in lifecycle;
the complete despawn contract remains open.

The damage path indexes an 8×8 byte table at RVA `0x2ACCC0` using category values
from group/object data. This is concrete evidence that relations affect outcomes;
the table's full semantics and all targeting consumers require validation.
“Set both teams equal” is not yet a complete friendly-fire or AI-policy patch.

## 5. Requirements for safe use

Capture `W` through a known live GameControl instance. RVA `0x33D9D8` is assigned
that world pointer during setup and read by many AI/view helpers, but the recorded
exact-address references do not establish that it is cleared on leave. Treat it
as a potentially stale diagnostic outside the tracked lifecycle.

Every lookup must validate mode identity, epoch, count, bounds, pointer lifetime,
and expected actor binding. Trace both a read and its producer before declaring
a field authoritative. Runtime writes or detours are a future gated experiment,
not validated operations from this static pass.

Execution audit correction: `0CBCC0.asm` at `1400CBE0D` loads `R12 = W+0x240`;
`1400CC77D` stores R12 to `P+0x1FC0`. Reset `0CD880.asm` repeats this at
`1400CE067/1400CE30D`. Do not treat this field as the world base pointer.

# Native adapter reading and usage contracts

## 1. Turn an address into a usable contract

For each adapter read its `.c`, `.asm` and `.json` together. Establish what object
RCX refers to, which register widths are consumed, which stack positions are
used, the return register, and every mutated object. Then establish the allowed
mode, thread and allocator lifetime. A large decompiler prototype with phantom
XMM/stack inputs is a reason to inspect instructions, not to add those parameters
to a DLL signature.

The most concrete ABI correction is `0C6A50`: campaign and VS call sites use
four register argument positions plus stack positions through caller
`[RSP+0x48]`, including an unused seventh position at `[RSP+0x30]`. The first-pass
caller decompilation showed only six arguments; the annotated exports show ten.
The unused position appears as `in_stack_...` because the caller does not write
it. This is **not** a missing initialized network parameter.

| Position | Windows x64 storage at call site | Recovered storage type / meaning |
| --- | --- | --- |
| 1 | RCX | World pointer |
| 2 | DL | Player count byte |
| 3 | R8B | Auxiliary count/option byte; complete semantics need validation |
| 4 | R9 | Byte-array pointer built from selected aircraft data |
| 5 | `[RSP+0x20]` | Byte-array pointer, auxiliary selections/options |
| 6 | `[RSP+0x28]` | Byte-array pointer, selected weapon/loadout data |
| 7 | `[RSP+0x30]` | Unused ABI position in recovered body |
| 8 | `[RSP+0x38]` | Byte-array pointer; role to finish tracing |
| 9 | `[RSP+0x40]` | Byte-array pointer; role to finish tracing |
| 10 | `[RSP+0x48]` | Three-byte selection/palette data (VS prepares two triples); consumption must be validated |

Those stack locations are the **caller's** pre-CALL RSP, not callee entry offsets.
The return address changes callee-relative stack locations. Reconstruct the
whole prologue before reading a callee's stack. The table is a research storage
contract; precise option/loadout semantics and lifetime still block a callable
production adapter.

## 2. Input adapter

The native path owns held→pressed/repeat history. A network sample should enter
before `188180/187390`, not overwrite the pressed bitmap after it has been
consumed. Recover neutral axis values and device presence using controlled
samples. Prove that receiving the same sequence twice produces no second press.

`187C80` reads the logical slot in DL and action ID in R8B; its result is in AL.
The camera action example uses ID `0x22`. Action-number semantics for flight,
fire and targeting must be traced; do not assign them from the camera example.

Candidate sequence:

```cpp
// Ordering pseudocode; not a detour implementation or validated native typedef.
native_poll_and_raw_normalize();
if (session_armed && epoch_matches && remote_slot_is_bound)
    copy_validated_remote_controls_to_raw_lane();
native_device_selection_and_edge_update();
// Later, normal native mode/gameplay dispatch consumes the mapped actions.
```

Input workers enqueue; the simulation owner consumes exactly once per accepted
tick. After a bounded stale-input timeout, neutralize dangerous continuous input
according to session policy and enter controlled recovery. Never recycle a
pressed-edge mask from an earlier packet as a new press.

## 3. Player and actor lookup

Player context and actor record are different types:

```cpp
// Address arithmetic only; production must validate every read and lifetime.
P = read_ptr(W + 0xA8248) + player_slot * 0x27A0;
manager = read_ptr(P + 0x2040);
groups = read_ptr(manager);
group = read_ptr(groups + group_selector * 8);
A = read_ptr(group + 0x110) + actor_selector * 0x520;
```

Validate player count, group count, signed actor count, selectors, actor binding
and world epoch. No pointer from a previous mission survives a retry. The world
global at RVA `33D9D8` is a useful observation root, but lifecycle tracking is the
authority for whether it is live.

Do not use actor `+0x1B8` as an aircraft model pointer: it is a player-context
link in observed controlled actors. Do not call a `ModeHolder` slot convention
on `Unit`: the recovered Unit vtable's slot 0 initializes actors, slot 8 resets
them, and slot `0x10` updates them. Virtual offsets have class-specific meaning.

## 4. Damage and outcome application

`118040` is a broad damage/outcome routine. It applies guards/scaling, subtracts
health, assigns attacker identity, changes flags and can trigger recursive
damage and effects. Calling it “set HP” would omit most of its contract.

On the host, record the native accepted outcome and its event identity. On the
guest, choose one validated method: either replay the native event with all its
preconditions and deterministic side effects, or apply a complete resolved
outcome with duplicate cascades suppressed. Do not combine both methods.

`117A10` triggers death-related effects/state. It does not prove an actor has
been freed. Entity retirement still requires the actual reuse/release seam and
all references to the actor to be invalidated or rebound.

## 5. Mission and camera adapter

`0D1780` calls the active-world path conditionally and also handles special
states. Hooking `0CE880` alone misses transitions and may not identify paused
versus active world time. Track readiness, phase and accepted tick separately.

Camera state is embedded in player processing. The guest's local view cannot be
implemented by globally swapping every reference to the first player. AI/view
helpers also read a shared world and selected group; reentrancy and RNG ordering
must be preserved. Update presentation for the local pilot at validated seams.

The existing ReShade bridge is a render observer/texture producer. Its lifecycle
diagnostic reads `32C933` and exposes a uniform; it is not a mission/authority
controller. Existing Rust code provides a useful SHA guard and hook-bootstrap
example, but its calibration thread and two-export XInput forwarder are not a
complete co-op loader/input contract.

## 6. Minimal future trace record

Suggested fields for RE runtime gates:

| Group | Fields |
| --- | --- |
| Provenance | EXE SHA, patch/tool version, source commit, scenario ID |
| Lifetime | Mode/vtable RVA, mode pointer, world pointer, epoch, readiness |
| Scheduling | Thread ID, monotonic timestamp, frame serial, native tick candidate, accepted tick |
| Input | Owned slot, received sequence, accepted held state, calculated pressed edges |
| Entity | Patch entity ID, native group/actor selectors, generation, context binding, active flags |
| State | Position/orientation representation ID, velocity when recovered, signed HP, ammo when recovered |
| Mission | VM phase/event ID, objective result, transition barrier, result/save sequence |

Keep pointer values local to diagnostic traces; network messages use stable IDs.
Bound trace buffers and flush off the simulation thread. A trace that cannot
correlate an outcome to a single epoch/tick is insufficient evidence for adapter
approval.

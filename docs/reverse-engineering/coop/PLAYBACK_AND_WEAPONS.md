# Playback consumers and weapon launch seams

Build and confidence labels: [README](README.md). This late focused pass follows
the **reader** of the history records, not just the capture functions. All
observations below are static. No playback or weapon was executed here.

## 1. A real recorded-state consumer exists

The mission driver calls `1B7480` on its playback branch. That routine invokes
`1B9400(manager, world)`, then copies each controlled actor's `+258/+268` vectors
into the corresponding player context's `+70/+80`. It still assumes player i is
group i's first actor; changing only the initial binding would miss this reader.

| RVA | Body-level observation | Interpretation / boundary |
| --- | --- | --- |
| [`1B8130`](evidence/decompiled/1401b8130.c) | First-entry branch copies selected live player fields into backup fields, copies selected world regions, resets effects/controllers, then calls `1B6480` | Playback enter/restart; broad mutation rather than a read-only helper |
| [`1B6480`](evidence/decompiled/1401b6480.c) | Chooses start/end times, builds record cursors and linked actor list; writes actor `+428 = 0xFF` | Prepares a bounded replay world; health is not restored as an exact live checkpoint |
| [`1B7480`](evidence/decompiled/1401b7480.c) | Applies playback, mirrors actor pose into players and runs view/presentation work | Playback-specific world step, not ordinary input-driven simulation |
| [`1B9400`](evidence/decompiled/1401b9400.c) | Applies flags/target selectors/pose, player scalar state and timed weapon/effect/death events; advances `33BD74` | Selective event/state playback, with native side effects |
| [`01DDC0`](evidence/decompiled/14001ddc0.c) | Reads record tag `+6B`, state values `+20..54`, time `+60`, and produces an intermediate state block | Tag-aware decode; position-like inputs are scaled by XMM2 |
| [`01DF10`](evidence/decompiled/14001df10.c) | Uses requested time in R9D and two decoded states; cubic position-like interpolation plus orientation-related helper calls | Useful interpolation research; coordinate and orientation conventions still need validation |

`1B9400` copies actor current vectors to previous vectors before new values are
applied. It interpolates between adjacent records, also restoring selected player
fields such as `+1640/+1650/+1664/+1668/+166C/+1670` and model fields through
`P+1630`. Thus `P+1640` is demonstrably part of a flight/presentation scalar path,
not actor HP. The death-record branch sets HP to zero and calls `118040`; it does
not merely display a death animation.

This closes the narrow question “is there a history consumer?” **Yes, statically.**
It does not close exact save/restore: window selection, capture decimation,
synthetic playback health, selective backups, effects and unrecovered mission VM
state prevent treating these functions as rollback or join-in-progress APIs.
No restore-and-resimulate equality test has passed.

## 2. Weapon event dispatch supplies three concrete launch roots

Timed records with tag `+6B == 2` use a subtype at `+20`:

| Subtype | Playback callee | Other indexed callers | Static storage / dispatch |
| --- | --- | --- | --- |
| 0 | [`13D140`](evidence/decompiled/14013d140.c) | `1031B0`, `11E140`, `11F160`, `121880` | Searches 16 slots; active mask at owner `+6E8`, record stride `58`, returns `FFFFFFFF` on no slot/invalid source |
| 1 | [`141200`](evidence/decompiled/140141200.c) | `1040C0`, `11B6D0`, `11FDD0`, `1251B0`, `125400` | Selects a controller through `owner+1DA30+type*8`, calls virtual `+38`, records accepted non-`1F` type |
| 2 | [`13ACE0`](evidence/decompiled/14013ace0.c) | `1040C0`, `11E140`, `11F160`, `121880` | Searches 32 slots; mask at owner `+738`, stride `38`; takes two random draws and constructs scatter/velocity-like values |

“Projectile” and “gun-like scatter” are H labels. The native subtype numbers
above are history taxonomy, not a complete aircraft weapon enumeration. The
specialized launch dispatcher still has an inferred ABI; its pseudocode contains
an `in_R9` artifact. Assembly preserves the fourth scalar from **XMM3**, so an
integer fourth argument inferred from R9 would be wrong. Inspect the remaining
register/stack storage before declaring a callable signature.

The emitters attach source group/actor selectors, target-like selectors,
position/orientation-like data and a resource/definition pointer. When playback
flag `33BD60` is clear, they append corresponding tag-2 history events. On the
playback path the flag prevents ordinary re-recording. It is not a co-op
authority flag and must not be globally repurposed.

## 3. Why the records cannot become packets by memcpy

The history event stores a native resource pointer at record `+28` (the field
shown as `record[5]`); `1B9400` passes it back to the launch routines. It is valid
only with the current install/process/resource lifetime. Source selectors are
also local slots, not stable network identities. A patch must encode a bounded
content/definition ID and resolve it locally after content agreement.

`13ACE0` consumes RNG while constructing scatter, including when reached through
the playback reader. Replaying the same event bytes is therefore insufficient
evidence for identical flight/combat outcomes. The new protocol must carry an
authoritative accepted outcome or a fully validated reproducible launch state;
it cannot assume replay flag plus a shared seed solves this.

The playback reader contains primary-player-only branches for some ammunition/
presentation accounting. Two-player support in the capture/actor loop does not
prove every replay event is symmetric. Audit those branches before using any
playback helper for guest presentation.

## 4. Concrete next experiments

1. Correlate one accepted launch with a history event and native pool slot;
   recover all used ABI positions and distinguish failure from valid slot zero.
2. Follow that slot through update, collision, hit, expiry and mask clear/reuse.
   The launch roots do not complete the projectile lifetime contract.
3. Compare a live trace with playback for pose, health, ammo, score, RNG draws and
   mission state. Record omissions rather than assuming equality from video.
4. Resolve resource pointers to content IDs, then test on two independent
   processes. Never transmit a pointer or use local slot numbers as entity IDs.

These observations refine RE07/RE09/RE15 in the
[contract matrix](../../mp/REVERSE_ENGINEERING_PLAN.md). They strengthen the
host-authoritative implementation plan without certifying a native network API.

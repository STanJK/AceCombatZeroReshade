# Evidence and reproduction

## Provenance

| Item | Value |
| --- | --- |
| Source baseline | `STanJK/AceCombatZeroReshade` main at `56cb5594fe199e93129380ce76dd5ae42345256c` |
| Binary | User-supplied `acz.exe`, 3,803,248 bytes |
| SHA-256 | `43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664` |
| Analysis | Ghidra 12.2 Headless, x86 little-endian 64-bit / Windows compiler specification |
| Java | Temurin JDK 25.0.5 |
| New runtime gameplay validation | None |
| New playable patch | None; this is the research/implementation handoff |

The analysis and exporters ran against the actual supplied bytes. No file was
identified as the target from its filename alone. The target SHA matches the
existing repository's documented build.

## Corpus

| Artifact | Contents |
| --- | --- |
| [`evidence/coverage.json`](evidence/coverage.json) | Exact counts and explicit static/runtime boundary |
| [`evidence/metadata.json`](evidence/metadata.json) | Program SHA, preferred base, compiler/language and memory blocks |
| [`evidence/program-index.json.gz`](evidence/program-index.json.gz) | Complete collected function/call/data/string/symbol/PE/RTTI indexes |
| [`evidence/imports.json`](evidence/imports.json) | 255 imports/ordinals from 17 DLLs |
| [`evidence/rtti-vtables.json`](evidence/rtti-vtables.json) | 404 COL-validated vtable candidates and executable slot targets |
| [`evidence/function-manifest.json`](evidence/function-manifest.json) | Every selected function and its confidence/review boundary |
| [`evidence/structural-review.json`](evidence/structural-review.json) | Per-body offsets/globals/calls, warning and unresolved-decompiler-input inventory |
| [`evidence/selection.txt`](evidence/selection.txt) | Reproduction seeds for all 255 selected functions |
| `evidence/decompiled/` | Matching `.c`, `.asm`, `.json` for each selected VA |
| `evidence/passes/` | The six adaptive selection passes, retained separately |
| [`../../mp/HOOK_CANDIDATES.json`](../../mp/HOOK_CANDIDATES.json) | Same-build candidate prologues; no runtime approval implied |

Final index: **4,792 functions**, **19,313 direct call sites**, **47,655 direct
data references**, **1,918 defined strings**. Selected corpus: **255** completed
decompilations, **38,575** pseudocode lines and **50,057** instruction lines.
The focused semantic/data-flow catalog has **90** entries; remaining exports are
supporting evidence with unresolved callable contracts.

The initial full automatic pass completed successfully in about 94 seconds and
contained 4,772 inferred functions. The final pass adds 20 explicitly seeded
executable leaf/tail wrappers. Different function recovery settings can change
these counts; they are corpus metrics, not measures of gameplay understood.

Ghidra produced warnings on two auto-analysis decompilation callbacks involving
unreadable inferred addresses (`140102800`, `1401A9630`). No PDB was available.
The final selected export manifest records completion/error state per function;
all 255 selected exports completed, but completion does not prove inferred types
or every control-flow branch is correct.

## Primary chains checked

- `1FF820 → 201DC0 → 188A80/188180`, device edge routine and action map binding.
- Campaign `16E880 → 0D1780`; VS `16F550 → 0D1780`.
- Campaign/VS loadout callers → `0C6A50`; argument storage checked in assembly.
- `0CBCC0 → 135B50/135CB0`; Unit vtable slots → actor initialization/update.
- `0CE880 → 1040C0/1363C0/1B7CE0` under their branch conditions.
- `118040 → 117A10`, health subtraction/attacker fields and recursive paths.
- `1B7CE0 → 01A2A0`; explicit previous-vector copies and bounded event selection.
- `0D1780 → 1B7480 → 1B9400`; recorded pose/flags and timed weapon replay.
- Playback subtype dispatch → `13D140/141200/13ACE0`; pool masks, strides and resource-pointer-bearing events.
- `242630/24265C`; LCG/seed writes to the CRT per-thread context.

## Reproduce and verify

Use [the tooling guide](../../usage/RESEARCH_TOOLING.md). The local helpers are
under `tools/ghidra/`; they do not need IDA, a license, a GUI or an MCP server.
The EXE and assets remain external inputs and are not stored in this branch.

After changing source/evidence, run the archive validator and refresh the frozen
plan/usage snapshot intentionally. [ARCHIVE.md](ARCHIVE.md) describes the final
archive. Its hashes establish which bytes were retained; they do not constitute
runtime or semantic validation.

## Subsequent execution audit

The Rust implementation pass corrected player +1FC0 to W+240 by rechecking both
initial/reset writers. It also retained [two extra ModeHolder ABI exports](../../mp/execution/evidence/native-dispatch/README.md).
Those supplemental bodies are separate from the original 255-function corpus.
Implementation/module verification is recorded [here](../../mp/execution/VALIDATION.md).

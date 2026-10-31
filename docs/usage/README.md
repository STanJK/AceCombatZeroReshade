# Using the co-op research code and evidence

This is the third-stage reading/usage handoff. It covers extraction tooling,
the collected code corpus and the native seams that a future patch would use.
No new game-RVA hook is production-approved by these documents.

| Document | Purpose |
| --- | --- |
| [WINGMAN_LOCAL.zh-CN.md](WINGMAN_LOCAL.zh-CN.md) | Campaign-wingman direction, in-game probe and unfinished native takeover gates |
| [COOP_DEMO.zh-CN.md](COOP_DEMO.zh-CN.md) | Complete Windows demo walkthrough: one-PC two-process CLI, LAN, EXE checks, and experimental game observation |
| [RESEARCH_TOOLING.md](RESEARCH_TOOLING.md) | Run the exact CLI extraction and inspect the archived indexes |
| [NATIVE_ADAPTERS.md](NATIVE_ADAPTERS.md) | Read the recovered code as ABI, lifetime and authority contracts |
| [CODE_READING_NOTES.md](CODE_READING_NOTES.md) | Findings/corrections from following code across subsystem boundaries |
| [FUNCTION_REVIEW_LEDGER.md](FUNCTION_REVIEW_LEDGER.md) | All 255 selected functions, evidence links, review depth and limitations |
| [RUST_COOP_FOUNDATION.md](RUST_COOP_FOUNDATION.md) | Run the implemented Rust modules, understand their boundaries, and reproduce validation |

The core path to read first is:

1. `1FF820 → 201DC0 → 188A80/188180/187390` for input and scheduling.
2. `16E880` and `16F550` plus their setup tables for lifecycle.
3. `16EB20/16F6C0 → 0C6A50 → 0CBCC0` for player allocation/binding.
4. `135B50/12C410 → 135CB0 → 12C520` for definition-driven actor construction.
5. `0D1780 → 0CE880 → 1040C0/1363C0` for active simulation.
6. `118040 → 117A10` for damage outcomes and lethal effects.
7. `1B7CE0 → 01A2A0` for capture; `1B7480 → 1B9400` for playback.
8. `1B9400 → 13D140/141200/13ACE0` for timed weapon events; `242630/24265C` for RNG.

Each number above is an RVA. The `.c` files are **Ghidra-generated pseudocode**;
the accompanying `.asm` is the stronger evidence for storage/branch/call details.
The `.json` records callers, callees and incoming code/data references.

The structural pass covers every selected body. The focused catalog covers 90
contracts; supporting exports retain open semantic review. This distinction is
intentional: generating 255 listings does not establish 255 fully understood,
callable functions. The usage ledger exposes that boundary for the next engineer.

The [research dossier](../reverse-engineering/coop/README.md) owns factual findings.
The [implementation specification](../mp/COOP_PATCH_IMPLEMENTATION.md) owns proposed
behavior. Keep those separate when adding new evidence.

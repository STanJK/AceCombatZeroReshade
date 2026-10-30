# Runtime ABI supplement

Two additional same-build Ghidra exports, separate from the earlier 255-function
research selection. Target SHA is in each C header; all decompilations completed.

- [2010D0 C](1402010d0.c) / [instructions](1402010d0.asm): ModeHolder vfunc +30
  loads the active mode, sets RDX=holder and calls mode vfunc +20. It overwrites
  AL with 1 after that call. This supports a two-argument, void mode-update hook;
  the frame driver's AL test is of the holder result, not the game-mode result.
- [201100 C](140201100.c) / [instructions](140201100.asm): auxiliary dispatch.

These exports were generated with the existing CLI exporter against the same
Ghidra program. They add ABI evidence, not Windows gameplay validation.

The auxiliary tail wrapper `201100` was absent from the P7 function table and
was explicitly created from its RTTI slot seed. The latest Ghidra function count
is 4,793. [index-delta.json](index-delta.json) preserves the exact additions/removals
relative to the frozen 4,792-function P7 index; direct-call and data-reference
counts stay unchanged. This does not alter the original 255-body selection.

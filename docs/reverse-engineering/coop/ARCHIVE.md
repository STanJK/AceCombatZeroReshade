# Frozen plans, usage and integrity

The readable working documents remain in [`docs/mp`](../../mp/README.md) and
[`docs/usage`](../../usage/README.md). To retain the complete second/third-stage
handoff inside `docs/reverse-engineering`, this dossier also contains:

| File | Purpose |
| --- | --- |
| [archive/plans-and-usage.tar.gz](archive/plans-and-usage.tar.gz) | Frozen bytes of every file in `docs/mp` and `docs/usage`, preserving repository-relative paths |
| [archive/manifest.json](archive/manifest.json) | Per-file size and SHA-256 for that snapshot |
| [evidence/integrity.json](evidence/integrity.json) | Hashes of the dossier, plans/usage, extraction tools and modified entry/lifecycle documents; excludes itself |
| [evidence/program-index.json.gz](evidence/program-index.json.gz) | Full collected static indexes, separately compressed |

The tar/gzip containers use normalized timestamps and owner metadata. The
snapshot stores the original `docs/mp/...` / `docs/usage/...` paths; extracting
it at a repository root preserves relative links into this dossier. It contains
no EXE, game assets, license file or Ghidra project.

From the repository root, validate without the proprietary binary:

```bash
python3 tools/ghidra/verify_coop_archive.py
```

For the stronger same-build byte checks:

```bash
python3 tools/ghidra/verify_coop_archive.py --binary /path/to/acz.exe
```

This verifies file sets/hashes, snapshot equality, VA/RVA arithmetic, matching
C/asm/metadata files, coverage counts, critical direct-call edges, selected
instruction evidence and local Markdown file targets. With the EXE, it also
checks both initialization tables and every candidate's first 32 file bytes.
It does not validate Markdown fragments, all decompiler semantics, safe detour
lengths, native ABIs, Windows builds, gameplay or networking.

After intentional edits, review the diff, then regenerate and verify:

```bash
python3 tools/ghidra/verify_coop_archive.py --freeze --binary /path/to/acz.exe
```

Freezing records the current files, so a successful hash check is an integrity
claim only. Retain Git history to review semantic changes. Do not use a fresh
freeze to conceal an unexplained mismatch.

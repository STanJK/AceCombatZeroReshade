# CLI research tooling

## 1. Reproduce extraction

Requirements: Ghidra **12.2**, a supported **JDK 25**, Python 3.12+ for the local
helpers, and the exact target EXE. Java scripts run in Ghidra; ordinary Python
does not have its program/decompiler context.

From the repository root:

```bash
GHIDRA_INSTALL_DIR=/path/to/ghidra_12.2_PUBLIC \
JAVA_HOME=/path/to/jdk-25 \
bash tools/ghidra/run_coop_research.sh /path/to/acz.exe /fresh/acz-research
```

The script rejects an existing project at the destination and validates the
EXE hash before starting Ghidra. It imports/analyzes the program, annotates three
explicitly recovered argument-storage contracts, exports the selected functions,
then exports the final program index. It never runs the game executable.

The equivalent headless stage used in this investigation was `analyzeHeadless`
with `-process acz.exe`, `-noanalysis` for repeated focused export, and the three
post scripts in the same order. Initial whole-image analysis ran once before
those focused exports. The initial index contained 4,772 functions; 20 explicitly
seeded executable leaf/tail wrappers brought the final index to 4,792.

Do not re-run whole-image analysis merely to retrieve one more function. Extend
the selection file and process the existing project without analysis once its
baseline is established. Do not open a second writer on the same Ghidra project.

## 2. Tool responsibilities and limits

| Source | Behavior | Important limitation |
| --- | --- | --- |
| `pe_evidence.py` | SHA/PE64 validation, imports, section map, x64 RTTI/COL/vtable candidates | File-backed bytes only; vtable candidate is not a semantic class contract |
| `ExportProgramIndex.java` | Function table, direct call sites, direct data refs, defined strings, non-default symbols | Does not resolve every virtual call, offcut reference or unknown code region |
| `ApplyKnownInputContracts.java` | Storage annotations for `188550`, `187C80`, `0C6A50` | Assigns generic arg names; not a completed semantic ABI certificate |
| `ExportSelectedFunctions.java` | C-like listing, instruction text, callers/callees and incoming refs | 90-second decompiler limit; missing executable leaves may be created from explicit seeds |
| `package_coop_evidence.py` | Canonical index archive, per-function evidence, structural review, hook candidates and ledger | Focused catalog remains distinct from automated structural inspection |
| `coop_catalog.json` | Human research labels/confidence/usage boundaries | Labels are local research names, not recovered original symbols |
| `verify_coop_archive.py` | Freeze plan/usage copies and verify archive, provenance, call/field evidence, tables and fingerprints | Static checks only; no gameplay or detour/ABI certification |

`ExportSelectedFunctions` only creates a missing function when the supplied
address is executable and does not already lie inside a function. It does not
silently substitute a containing function for a requested entry. A `NO_FUNCTION`
line must be investigated rather than counted as successful export.

Refresh the repository dossier intentionally:

```bash
python3 tools/ghidra/package_coop_evidence.py \
  /path/to/acz.exe /fresh/acz-research --repo /path/to/AceCombatZeroReshade
```

This replaces generated research evidence/ledgers. Review the resulting diff;
freeze the plan/usage snapshot only after final documentation validation.

```bash
python3 tools/ghidra/verify_coop_archive.py --freeze --binary /path/to/acz.exe
# Subsequent read-only validation, without the EXE:
python3 tools/ghidra/verify_coop_archive.py
```

The frozen snapshot is retained under `docs/reverse-engineering/coop/archive`.
See [archive conventions](../reverse-engineering/coop/ARCHIVE.md) before updating it.

## 3. Inspect the full index without IDA or a GUI

From the repository root:

```python
import gzip, json
from pathlib import Path

p = Path('docs/reverse-engineering/coop/evidence/program-index.json.gz')
index = json.loads(gzip.decompress(p.read_bytes()))

print(index['metadata'])
print([r for r in index['calls'] if r['target'] == '0x140118040'])
print([r for r in index['data-references'] if r['target'] == '0x14033d9d8'])
```

The `strings` index records references to defined-string **starts**. An empty
reference list is bounded negative evidence; it does not cover arbitrary pointer
arithmetic into a string. The `calls` table is direct-call evidence; inspect
`rtti-vtables` and selected function `.json` data references for virtual paths.

## 4. File and version conventions

- Filename `140118040.c` refers to preferred VA `0x140118040` for this build.
- Runtime lookup uses `module_base + 0x118040`, never that preferred VA directly.
- Preserve the SHA in every listing header and every future trace.
- Keep raw facts in `docs/reverse-engineering/coop`, plans in `docs/mp`, usage
  in `docs/usage`, and frozen copies under the reverse-engineering archive.
- Do not commit EXEs, license files, game assets, Ghidra projects or local logs
  containing account/installation details. The exported index and scripts are
  sufficient to reproduce this static dossier from the user-supplied binary.

## 5. Validation already performed

Ghidra headless import and an independent decompiler smoke test passed before
the game investigation. Whole-image analysis completed; both Java exporters and
the storage-annotation script executed successfully. The final selected corpus
contains 255 completed decompilations with matching instruction/metadata files.

The Python PE/index packagers ran against the exact supplied file. Archive
validation checks hashes, VA↔RVA arithmetic, body file completeness, selected
function counts, the two setup tables, critical call edges and key field evidence.
These are static/tooling checks. They do not test Windows DLL compilation,
gameplay, runtime hook safety, network performance or campaign completion.

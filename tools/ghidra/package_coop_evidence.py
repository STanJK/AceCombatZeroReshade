#!/usr/bin/env python3
"""Package the selected same-build Ghidra exports and their bounded review ledger."""
from __future__ import annotations
import argparse
from collections import Counter
import gzip
import hashlib
import json
from pathlib import Path
import re
import shutil
from pe_evidence import PE, EXPECTED_SHA256


def write_json(path: Path, value):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(value, indent=2, sort_keys=True)+"\n", encoding="utf-8")


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("binary", type=Path)
    ap.add_argument("work", type=Path)
    ap.add_argument("--repo", type=Path, default=Path(__file__).resolve().parents[2])
    args = ap.parse_args()
    repo, work = args.repo.resolve(), args.work.resolve()
    pe = PE(args.binary)
    if pe.sha256 != EXPECTED_SHA256:
        raise SystemExit("Build mismatch")
    target = repo/"docs/reverse-engineering/coop"
    evidence = target/"evidence"
    selected = evidence/"decompiled"
    selected.mkdir(parents=True, exist_ok=True)
    catalog = json.loads((Path(__file__).parent/"coop_catalog.json").read_text())
    index = {p.stem: json.loads(p.read_text()) for p in sorted((work/"index").glob("*.json"))}
    blob = json.dumps(index, sort_keys=True, separators=(",", ":")).encode()
    (evidence/"program-index.json.gz").write_bytes(gzip.compress(blob, mtime=0))
    for name in ["metadata", "imports", "pe-layout", "rtti-vtables"]:
        write_json(evidence/(name+".json"), index[name])
    manifest, review, hooks = [], [], []
    map_lines = ["# Function and capability inventory", "", "Build/confidence: [README](README.md).",
                 "All names below are research labels. S confirms mechanics; H denotes inferred semantics.",
                 "No row grants permission to call an inferred ABI directly from a patch.", "",
                 "## Focused contracts", "", "| RVA | Research label | Evidence | Area | Usage boundary |",
                 "| --- | --- | --- | --- | --- |"]
    ledger = ["# Per-function review ledger", "",
              "Every selected function has a pseudocode listing, instruction listing and call/reference metadata.",
              "The automated structural pass visits every exported body. Focused interpretation is limited to",
              "the catalogued contracts; supporting exports retain open semantics. Neither tier is runtime proof.",
              "A generated listing is not evidence that all original source or all player behavior is understood.", "",
              "| RVA | Label | Review depth | Usage boundary | Evidence |", "| --- | --- | --- | --- | --- |"]
    for meta_file in sorted((work/"selected").glob("*.json")):
        if meta_file.name == "manifest.json":
            continue
        meta = json.loads(meta_file.read_text())
        stem = meta_file.stem
        code_file = work/"selected"/(stem+".c")
        asm_file = work/"selected"/(stem+".asm")
        if not meta["decompile_completed"] or not code_file.is_file() or not asm_file.is_file():
            raise ValueError("Incomplete export: "+stem)
        text, asm = code_file.read_text(), asm_file.read_text()
        label, confidence, area, note = catalog.get(meta["rva"], [meta["name"], "O", "supporting", "Supporting export: semantic and callable contract remain open."])
        depth = "focused data-flow/assembly checks" if meta["rva"] in catalog else "automated structural inventory; semantic review open"
        meta = dict(meta, research_label=label, confidence=confidence, area=area,
                    review_depth=depth, usage_boundary=note)
        for suffix in [".c", ".asm"]:
            shutil.copyfile(work/"selected"/(stem+suffix), selected/(stem+suffix))
        write_json(selected/(stem+".json"), meta)
        manifest.append(meta)
        warnings = [line.strip() for line in text.splitlines() if "WARNING:" in line]
        unresolved = sorted(set(re.findall(r"\b(?:unaff_\w+|extraout_\w+|in_stack_\w+|in_R\w+)", text)))
        review.append(dict(va=meta["va"], rva=meta["rva"], label=label, review_depth=depth,
                          pseudocode_lines=len(text.splitlines()), instruction_lines=len(asm.splitlines()),
                          direct_callees=meta["callees"], callers=meta["callers"], warnings=warnings,
                          unresolved_decompiler_inputs=unresolved,
                          pseudocode_offsets=sorted(set(re.findall(r"\+ (0x[0-9a-f]+)\b", text))),
                          globals=sorted(set(re.findall(r"(?:DAT|PTR|UNK)_([0-9a-f]{9,})",text)))))
        link=f"evidence/decompiled/{stem}.c"
        if meta["rva"] in catalog:
            map_lines.append(f"| [`{meta['rva']}`]({link}) | {label} | {confidence} | {area} | {note} |")
            start=pe.file_offset(int(meta["va"],16))
            hooks.append(dict(rva=meta["rva"], va=meta["va"], research_label=label,
                              first_32_file_bytes=pe.data[start:start+32].hex(" "),
                              state="STATIC_CANDIDATE_NOT_RUNTIME_APPROVED", confidence=confidence,
                              abi=meta["prototype"], warning="Decompiler prototype is not a callable ABI certificate; verify instruction boundaries and all side effects."))
        evidence_link=f"../reverse-engineering/coop/{link}"
        asm_link=evidence_link.removesuffix(".c")+".asm"
        ledger.append(f"| `{meta['rva']}` | {label} | {depth} | {note} | [C]({evidence_link}) / [asm]({asm_link}) |")
    write_json(evidence/"function-manifest.json",manifest)
    write_json(evidence/"structural-review.json",review)
    write_json(repo/"docs/mp/HOOK_CANDIDATES.json",dict(sha256=pe.sha256,image_base=hex(pe.base),
               production_approved=False,candidates=hooks))
    (evidence/"selection.txt").write_text("\n".join(m["va"] for m in manifest)+"\n")
    for p in sorted(work.glob("seeds-pass*.txt")):
        (evidence/"passes").mkdir(exist_ok=True)
        shutil.copyfile(p,evidence/"passes"/p.name)
    map_lines += ["", "## Unrecovered/new contracts", "",
                  "| Capability | Current result | Implementation consequence |", "| --- | --- | --- |",
                  "| Online session/send/receive/replication | No accepted gameplay networking contract | New transport and protocol |",
                  "| Safe arbitrary runtime spawn/despawn | Initial constructors and death effects recovered; release/reuse closure open | RE07 blocks entity replication |",
                  "| Complete snapshot/rollback | Selective history/event pools only | No join-in-progress/rollback promise |",
                  "| Campaign P2 actor definitions | Asset format/content not supplied | RE05/RE06 must precede networking |",
                  "| Typed flight integrator state | Several movement/control seams; full dependency closure open | No pose-only correctness claim |",
                  "| Complete mission VM/commit/save API | Lifecycle/result roots recovered; semantic closure open | RE12/RE17 block campaign certification |",
                  "", "The full selected-function ledger is [here](../../usage/FUNCTION_REVIEW_LEDGER.md).",
                  "All required contracts and experiments are tracked in [the plan](../../mp/REVERSE_ENGINEERING_PLAN.md)."]
    (target/"FUNCTION_MAP.md").write_text("\n".join(map_lines)+"\n",encoding="utf-8")
    (repo/"docs/usage").mkdir(exist_ok=True)
    (repo/"docs/usage/FUNCTION_REVIEW_LEDGER.md").write_text("\n".join(ledger)+"\n",encoding="utf-8")
    rand_sites=[c for c in index["calls"] if c["target"]=="0x140242630"]
    stats=dict(sha256=pe.sha256,functions=len(index["functions"]),direct_call_sites=len(index["calls"]),
               data_references=len(index["data-references"]),defined_strings=len(index["strings"]),
               rtti_vtable_candidates=len(index["rtti-vtables"]),imports=len(index["imports"]),
               imported_dlls=len(set(x["dll"].lower() for x in index["imports"])),
               selected_functions=len(manifest),focused_catalog_entries=sum(m["rva"] in catalog for m in manifest),
               pseudocode_lines=sum(r["pseudocode_lines"] for r in review),
               instruction_lines=sum(r["instruction_lines"] for r in review),
               rand_direct_sites=len(rand_sites),rand_direct_callers=len(set(c["caller"] for c in rand_sites)),
               runtime_scenarios_executed=0,playable_coop_patch=False)
    write_json(evidence/"coverage.json",stats)
    print(json.dumps(stats,indent=2))


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
"""Freeze/verify the co-op dossier; all checks are static, never game execution."""
from __future__ import annotations

import argparse
import gzip
import hashlib
import io
import json
from pathlib import Path
import re
import tarfile

from pe_evidence import EXPECTED_SHA256, PE

BASE = 0x140000000
ROOT = Path(__file__).resolve().parents[2]
DOSSIER = Path("docs/reverse-engineering/coop")
EVIDENCE = DOSSIER / "evidence"
ARCHIVE = DOSSIER / "archive"
INTEGRITY = EVIDENCE / "integrity.json"
AREAS = [DOSSIER, Path("docs/mp"), Path("docs/usage"), Path("tools/ghidra"), Path("coop")]
EXTRA = [Path("README.md"), Path("docs/README.md"),
         Path("docs/reverse-engineering/MODE_LIFECYCLE.md"), Path(".github/workflows/coop.yml"), Path(".gitattributes")]
SETUP_TABLES = {
    0x290DE0: [0x16EA60, 0x16EA70, 0x16EAB0, 0x16EAE0, 0x16EB20,
              0x16EC40, 0x16EC80, 0x16ECB0, 0x16ECF0, 0x16ED10,
              0x16EA90, 0x16EB00, 0x16EC60, 0x16ECD0, 0x16EDD0,
              0x16EF50, 0xA3FA0, 0x16F080],
    0x290E70: [0x16EA60, 0x16EA70, 0x16F640, 0x16EAE0, 0x16F6C0,
              0x16EC40, 0x16F7E0, 0x16ECB0, 0x16EA90, 0x16EB00,
              0x16EC60, 0x16ECD0, 0x16F860, 0xA3FA0, 0x16FA80],
}
CALLS = [
    (0x1FF820, 0x201DC0), (0x201DC0, 0x188A80), (0x201DC0, 0x188180),
    (0x188180, 0x187390), (0x16E880, 0xD1780), (0x16F550, 0xD1780),
    (0x16EB20, 0xC6A50), (0x16F6C0, 0xC6A50),
    (0xCBCC0, 0x135B50), (0xCBCC0, 0x135CB0),
    (0xD1780, 0xCE880), (0xCE880, 0x1040C0), (0xCE880, 0x1363C0),
    (0xCE880, 0x1B7CE0), (0x118040, 0x117A10), (0x1B7CE0, 0x1A2A0),
    (0xD1780, 0x1B7480), (0x1B7480, 0x1B9400),
    (0x1B9400, 0x13D140), (0x1B9400, 0x141200), (0x1B9400, 0x13ACE0),
    (0x242630, 0x25244C), (0x24265C, 0x25244C),
]


def require(condition, message):
    if not condition:
        raise ValueError(message)


def digest(data):
    return hashlib.sha256(data).hexdigest()


def read_json(path):
    return json.loads((ROOT / path).read_text(encoding="utf-8"))


def write_json(path, data):
    p = ROOT / path
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_text(json.dumps(data, indent=2, sort_keys=True) + "\n", encoding="utf-8", newline="\n")


def files_in(areas):
    return sorted({p.relative_to(ROOT) for a in areas for p in (ROOT / a).rglob("*")
                   if p.is_file() and "__pycache__" not in p.parts and p.suffix != ".pyc"
                   and not (a == Path("coop") and any(v in ("target", "dist") for v in p.relative_to(ROOT/a).parts))
                   and not p.name.endswith(".trace.jsonl")},
                  key=str)


def entry(path):
    data = (ROOT / path).read_bytes()
    return dict(path=path.as_posix(), bytes=len(data), sha256=digest(data))


def tracked_dossier_files():
    return sorted((set(files_in(AREAS)) | set(EXTRA)) - {INTEGRITY}, key=str)


def freeze():
    plans = files_in([Path("docs/mp"), Path("docs/usage")])
    rows = [entry(p) for p in plans]
    write_json(ARCHIVE / "manifest.json", dict(
        format=1, research_date="2026-11-02 UTC", target_sha256=EXPECTED_SHA256,
        contents="Canonical docs/mp and docs/usage at this research revision", files=rows))
    stream = io.BytesIO()
    with tarfile.open(fileobj=stream, mode="w", format=tarfile.PAX_FORMAT) as tar:
        for p in plans:
            data = (ROOT / p).read_bytes()
            info = tarfile.TarInfo(p.as_posix())
            info.size, info.mode = len(data), 0o644
            info.mtime = info.uid = info.gid = 0
            info.uname = info.gname = ""
            tar.addfile(info, io.BytesIO(data))
    (ROOT / ARCHIVE / "plans-and-usage.tar.gz").write_bytes(
        gzip.compress(stream.getvalue(), mtime=0))
    write_json(INTEGRITY, dict(format=1, target_sha256=EXPECTED_SHA256,
                              files=[entry(p) for p in tracked_dossier_files()]))


def verify(binary):
    integrity = read_json(INTEGRITY)
    require(integrity["target_sha256"] == EXPECTED_SHA256, "Integrity target SHA mismatch")
    expected_paths = {r["path"] for r in integrity["files"]}
    actual_paths = {p.as_posix() for p in tracked_dossier_files()}
    require(expected_paths == actual_paths, "Archive file set changed; review and freeze intentionally")
    for r in integrity["files"]:
        require(entry(Path(r["path"])) == r, "Hash/size mismatch: " + r["path"])

    archive_rows = read_json(ARCHIVE / "manifest.json")["files"]
    require({r["path"] for r in archive_rows} ==
            {p.as_posix() for p in files_in([Path("docs/mp"), Path("docs/usage")])},
            "Plan/usage snapshot file set mismatch")
    with tarfile.open(ROOT / ARCHIVE / "plans-and-usage.tar.gz", "r:gz") as tar:
        members = tar.getmembers()
        require(len(members) == len(archive_rows), "Snapshot member count mismatch")
        for member, r in zip(members, archive_rows):
            require(member.isfile() and member.name == r["path"], "Unexpected archive member")
            data = tar.extractfile(member).read()
            require(data == (ROOT / r["path"]).read_bytes(), "Frozen/canonical content mismatch")
            require(digest(data) == r["sha256"] and len(data) == r["bytes"], "Snapshot digest mismatch")
            require(member.mtime == 0 and member.uid == 0 and member.gid == 0, "Noncanonical tar metadata")

    index = json.loads(gzip.decompress((ROOT / EVIDENCE / "program-index.json.gz").read_bytes()))
    require(index["metadata"]["sha256"] == EXPECTED_SHA256, "Index target SHA mismatch")
    require(int(index["metadata"]["image_base"], 16) == BASE, "Wrong image base")
    manifest = read_json(EVIDENCE / "function-manifest.json")
    review = read_json(EVIDENCE / "structural-review.json")
    hooks = read_json(Path("docs/mp/HOOK_CANDIDATES.json"))
    catalog = read_json(Path("tools/ghidra/coop_catalog.json"))
    coverage = read_json(EVIDENCE / "coverage.json")
    require(hooks["sha256"] == EXPECTED_SHA256 and not hooks["production_approved"], "Hook approval boundary changed")
    vas = {m["va"] for m in manifest}
    require(len(vas) == len(manifest), "Duplicate selected function")
    require(set(catalog) <= {m["rva"] for m in manifest}, "Unexported catalog entry")
    require({r["va"] for r in review} == vas, "Structural-review set mismatch")
    require(set((ROOT / EVIDENCE / "selection.txt").read_text(encoding="utf-8").split()) == vas, "Selection mismatch")
    index_vas = {f["va"] for f in index["functions"]}
    body_paths = set()
    for m in manifest:
        va, rva = int(m["va"], 16), int(m["rva"], 16)
        require(va - BASE == rva and m["va"] in index_vas, "Function VA/RVA/index mismatch")
        require(m["decompile_completed"] and not m["decompile_error"], "Incomplete decompilation")
        stem = f"{va:x}"
        for suffix in [".c", ".asm", ".json"]:
            path = EVIDENCE / "decompiled" / (stem + suffix)
            require((ROOT / path).is_file(), "Missing body file: " + str(path))
            body_paths.add(path)
        c = (ROOT / EVIDENCE / "decompiled" / (stem + ".c")).read_text(encoding="utf-8")
        asm = (ROOT / EVIDENCE / "decompiled" / (stem + ".asm")).read_text(encoding="utf-8")
        require(EXPECTED_SHA256 in c and f"VA {m['va']}; RVA {m['rva']}" in c, "Listing provenance mismatch")
        require(asm.splitlines()[0].startswith(m["va"] + "  "), "Instruction entry mismatch")
        require(read_json(EVIDENCE / "decompiled" / (stem + ".json")) == m, "Body metadata mismatch")
    require(body_paths == set(files_in([EVIDENCE / "decompiled"])), "Unexpected or stale body file")
    call_edges = {(int(c["caller"], 16) - BASE, int(c["target"], 16) - BASE)
                  for c in index["calls"] if c["target"].startswith("0x")}
    for edge in CALLS:
        require(edge in call_edges, "Missing critical call: %x -> %x" % edge)
    for stem, needles in {
        "1401b6480": ["MOV word ptr [RBX + 0x428],0xff"],
        "14013d140": ["0x6e8", "CMP EBX,0x10"],
        "14013ace0": ["0x738", "CMP EAX,0x20"],
        "140141200": ["VMOVAPS XMM6,XMM3", "CALL qword ptr [RAX + 0x38]"],
    }.items():
        asm = (ROOT / EVIDENCE / "decompiled" / (stem + ".asm")).read_text(encoding="utf-8")
        require(all(s in asm for s in needles), "Key field/dispatch evidence mismatch: " + stem)

    computed = dict(functions=len(index["functions"]), direct_call_sites=len(index["calls"]),
                    data_references=len(index["data-references"]), defined_strings=len(index["strings"]),
                    selected_functions=len(manifest), focused_catalog_entries=len(catalog),
                    pseudocode_lines=sum(r["pseudocode_lines"] for r in review),
                    instruction_lines=sum(r["instruction_lines"] for r in review))
    require(all(coverage[k] == v for k, v in computed.items()), "Coverage counts disagree")
    require(coverage["runtime_scenarios_executed"] == 0 and not coverage["playable_coop_patch"], "Runtime boundary changed")
    require(len(hooks["candidates"]) == len(catalog), "Hook/catalog count mismatch")
    for h in hooks["candidates"]:
        require(len(bytes.fromhex(h["first_32_file_bytes"])) == 32, "Bad candidate fingerprint")
        require(int(h["va"], 16) - BASE == int(h["rva"], 16), "Hook VA/RVA mismatch")
    links = 0
    for path in files_in([DOSSIER, Path("docs/mp"), Path("docs/usage")]):
        if path.suffix != ".md":
            continue
        body = re.sub(r"```.*?```", "", (ROOT / path).read_text(encoding="utf-8"), flags=re.S)
        for link in re.findall(r"\[[^\]\n]+\]\(([^)\n]+)\)", body):
            link = link.strip("<>").split("#", 1)[0]
            if not link or re.match(r"[a-zA-Z][a-zA-Z0-9+.-]*:", link):
                continue
            require((ROOT / path.parent / link).exists(), f"Broken local link: {path}: {link}")
            links += 1

    if binary:
        pe = PE(binary)
        require(pe.sha256 == EXPECTED_SHA256 and pe.base == BASE, "Supplied EXE build mismatch")
        for rva, targets in SETUP_TABLES.items():
            actual = [v - BASE for v in pe.read(BASE + rva, "<" + "Q" * len(targets))]
            require(actual == targets, f"Setup table mismatch at {rva:x}")
        for h in hooks["candidates"]:
            off = pe.file_offset(int(h["va"], 16))
            require(pe.data[off:off + 32] == bytes.fromhex(h["first_32_file_bytes"]), "PE fingerprint mismatch")
    print(json.dumps(dict(result="PASS", checks="static artifacts only", **computed,
                          integrity_files=len(integrity["files"]), frozen_files=len(archive_rows),
                          critical_call_edges=len(CALLS), local_file_links=links,
                          exact_exe_tables_and_prologues_checked=bool(binary),
                          gameplay_executed=False), indent=2))


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--freeze", action="store_true", help="Intentionally replace snapshot and integrity manifest")
    ap.add_argument("--binary", type=Path, help="Also compare setup tables/prologues to exact supplied EXE")
    args = ap.parse_args()
    if args.freeze:
        freeze()
    verify(args.binary)


if __name__ == "__main__":
    main()

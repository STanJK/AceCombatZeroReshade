#!/usr/bin/env python3
"""Package and verify the R6–R10 static evidence."""
import argparse
import gzip
import io
import json
from pathlib import Path
import tarfile

from pe_evidence import EXPECTED_SHA256, PE
from verify_coop_archive import digest, require

ROOT = Path(__file__).resolve().parents[2]
PREVIOUS = ROOT / "docs/reverse-engineering/coop/cockpit"
DATA = PREVIOUS / "v1"
ROUNDS = {
    6: ("r6", "r6b"),
    7: ("r7", "r7b", "r7c"),
    8: ("r8", "r8b", "r8c"),
    9: ("r9", "r9b", "r9c"),
    10: ("r10", "r10b"),
}
WITNESSES = {
    "passes/r6/1400ce880.asm": [
        "0x1400cf038  CALL 0x1401040c0",
        "0x1400cf865  CALL 0x1401040c0",
        "0x1400cff20  INC dword ptr [RSI + 0xa878c]",
    ],
    "passes/r6b/140201100.asm": ["0x140201110  JMP qword ptr [RAX + 0x28]"],
    "passes/r7/1401fbec0.asm": [
        "0x1401fc2b4  VMOVUPS ymmword ptr [RBX + 0x110],YMM0",
        "0x1401fc2fc  VMOVUPS ymmword ptr [RBX + 0x150],YMM0",
    ],
    "passes/r8/140201a40.asm": ["0x140201a82  MOV qword ptr [R14 + 0x18],RAX"],
    "passes/r9/140108620.asm": [
        "0x140108959  LEA R8,[RSI + 0x10b0]",
        "0x140108976  CALL 0x1400ae510",
    ],
    "passes/r9b/14020ef50.asm": [
        "0x14020f2f2  MOV dword ptr [0x14031e1a0],EAX",
        "0x14020f2fc  MOV dword ptr [0x14031e1a4],EAX",
    ],
    "passes/r10/1401040c0.asm": [
        "0x140105a57  MOV byte ptr [R15 + 0x1eee],AL",
        "0x140105b2a  MOV byte ptr [R15 + 0x20a7],0x1",
    ],
}


def prefix(pe, va):
    offset = pe.file_offset(int(va, 16))
    data = pe.data[offset:offset + 32]
    require(len(data) == 32, f"Missing PE bytes for {va}")
    return data.hex()


def package(work, pe):
    files = {}
    passes = []
    entries = {}
    for number, batches in ROUNDS.items():
        for batch in batches:
            folder = work / batch
            name = f"passes/{batch}"
            rows = json.loads((folder / "manifest.json").read_bytes())
            for row in rows:
                va = row["va"]
                entries[va] = prefix(pe, va)
                for suffix in ("c", "asm", "json"):
                    path = f"{va[2:]}.{suffix}"
                    files[f"{name}/{path}"] = (folder / path).read_bytes()
            for filename, source in (
                ("seeds.txt", work / f"{batch}-seeds.txt"),
                ("headless.log", work / f"{batch}-headless.log"),
                ("manifest.json", folder / "manifest.json"),
            ):
                files[f"{name}/{filename}"] = source.read_bytes()
            passes.append(dict(round=number, name=batch, functions=len(rows)))
    for name in ("r6-operands.json", "r6-operands.log", "r6-watch.txt"):
        files[name] = (work / name).read_bytes()
    calls = json.loads((work / "index/calls.json").read_bytes())
    targets = {f"0x140{rva}" for rva in ("1040c0", "106f30", "0b7b40", "111d40")}
    files["direct-calls.json"] = (json.dumps(
        [row for row in calls if row["target"] in targets], indent=2
    ) + "\n").encode()

    buffer = io.BytesIO()
    with tarfile.open(fileobj=buffer, mode="w", format=tarfile.PAX_FORMAT) as archive:
        for name, data in sorted(files.items()):
            item = tarfile.TarInfo(name)
            item.size = len(data)
            item.mode = 0o644
            archive.addfile(item, io.BytesIO(data))
    packed = gzip.compress(buffer.getvalue(), mtime=0)
    old = json.loads((PREVIOUS / "manifest.json").read_bytes())
    old_entries = {row["va"] for row in old["entries"]}
    manifest = dict(
        target_sha256=pe.sha256,
        image_base=hex(pe.base),
        previous_commit="1f8bdcfd4fdafc3952167b21a96f70578814c0a0",
        tools=old["tools"],
        native_gameplay_executed=False,
        passes=passes,
        entries=entries,
        new_to_cockpit_archive=len(entries.keys() - old_entries),
        archive_sha256=digest(packed),
        members={name: digest(data) for name, data in sorted(files.items())},
    )
    (DATA / "exports.tar.gz").write_bytes(packed)
    (DATA / "manifest.json").write_text(json.dumps(manifest, indent=2) + "\n", newline="\n")


def verify(pe):
    m = json.loads((DATA / "manifest.json").read_bytes())
    require(m["target_sha256"] == EXPECTED_SHA256 and not m["native_gameplay_executed"],
            "Target/provenance")
    require(m["image_base"] == "0x140000000", "Image base")
    require([(p["round"], p["name"]) for p in m["passes"]] ==
            [(r, b) for r, batches in ROUNDS.items() for b in batches], "Round order")
    packed = (DATA / "exports.tar.gz").read_bytes()
    require(digest(packed) == m["archive_sha256"], "Archive digest")
    files = {}
    with tarfile.open(fileobj=io.BytesIO(packed), mode="r:gz") as archive:
        for item in archive:
            path = Path(item.name)
            require(item.isfile() and not path.is_absolute() and ".." not in path.parts,
                    f"Invalid member {item.name}")
            require(item.name not in files, f"Duplicate member {item.name}")
            files[item.name] = archive.extractfile(item).read()
    require({name: digest(data) for name, data in files.items()} == m["members"], "Member digests")
    seen = set()
    instances = 0
    for row in m["passes"]:
        name = f"passes/{row['name']}"
        log = files[f"{name}/headless.log"]
        require(b"Save succeeded for" in log and b"NO_FUNCTION" not in log, f"Log {name}")
        functions = json.loads(files[f"{name}/manifest.json"])
        require(len(functions) == row["functions"], f"Count {name}")
        seeds = files[f"{name}/seeds.txt"].decode().splitlines()
        require([f["va"] for f in functions] == seeds, f"Seed match {name}")
        for f in functions:
            va = f["va"]
            stem = f"{name}/{va[2:]}"
            require(f["decompile_completed"] and f == json.loads(files[f"{stem}.json"]),
                    f"Function metadata {stem}")
            require(EXPECTED_SHA256.encode() in files[f"{stem}.c"], f"Source SHA {stem}")
            require(int(va, 16) - int(f["rva"], 16) == 0x140000000, f"RVA {stem}")
            require(files[f"{stem}.asm"].startswith(va.encode()), f"Entry {stem}")
            seen.add(va)
            instances += 1
    require(seen == m["entries"].keys(), "Unique function set")
    for name, anchors in WITNESSES.items():
        require(all(s.encode() in files[name] for s in anchors), f"Witness {name}")
    calls = json.loads(files["direct-calls.json"])
    require({r["site"] for r in calls if r["target"] == "0x1401040c0"} ==
            {"0x1400cf038", "0x1400cf865", "0x1400d4ff4", "0x1401b8fc2"}, "1040C0 direct callers")
    operands = json.loads(files["r6-operands.json"])
    require({r["va"] for r in operands["rows"] if "a878c" in r["operands"]} ==
            {"0x1400cd8bc", "0x1400cff20", "0x14016dc9c"}, "A878C literal candidates")
    if pe:
        require(all(prefix(pe, va) == data for va, data in m["entries"].items()), "PE entry bytes")
    return dict(result="PASS", rounds=len(ROUNDS), batches=len(m["passes"]),
                unique_functions=len(seen), export_instances=instances,
                new_to_cockpit_archive=m["new_to_cockpit_archive"], members=len(files),
                original_pe_checked=pe is not None, native_gameplay_executed=False)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--binary", type=Path)
    parser.add_argument("--work", type=Path, help="Build the archive from the exported work tree")
    parser.add_argument("--record", type=Path)
    args = parser.parse_args()
    pe = PE(args.binary) if args.binary else None
    if pe:
        require(pe.sha256 == EXPECTED_SHA256, "Unexpected ACZ executable")
    if args.work:
        require(pe is not None, "--work requires --binary")
        package(args.work, pe)
    report = json.dumps(verify(pe), indent=2) + "\n"
    if args.record:
        args.record.write_text(report, newline="\n")
    print(report, end="")


if __name__ == "__main__":
    main()

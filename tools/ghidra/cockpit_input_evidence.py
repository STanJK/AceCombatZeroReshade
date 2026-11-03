#!/usr/bin/env python3
"""Package and verify the R11–R15 input evidence."""
import argparse
import gzip
import io
import json
from pathlib import Path
import re
import tarfile

from cockpit_v1_evidence import DATA, prefix
from pe_evidence import EXPECTED_SHA256, PE
from verify_coop_archive import digest, require

ARCHIVE = DATA / "input"
ROUNDS = {
    11: ("r11", "r11b"),
    12: ("r12", "r12b"),
    13: ("r13",),
    14: ("r14", "r14b"),
    15: ("r15", "r15b"),
}
BATCHES = [(number, batch) for number, batches in ROUNDS.items() for batch in batches]
WITNESSES = {
    "passes/r11/140188a80.asm": (
        "0x140188ab8  CALL 0x14021d4c0",
        "0x140188abd  MOVZX EAX,word ptr [0x14033ac08]",
    ),
    "passes/r13/140188550.asm": (
        "0x1401885e2  AND AL,0x2",
        "0x1401885e8  MOV byte ptr [R8 + 0x8],AL",
    ),
    "passes/r14/140201dc0.asm": (
        "0x140201dc4  CALL 0x140188a80",
        "0x140201dc9  CALL 0x140188180",
    ),
    "passes/r15/1401040c0.asm": (
        "0x140105a57  MOV byte ptr [R15 + 0x1eee],AL",
        "0x140105b2a  MOV byte ptr [R15 + 0x20a7],0x1",
    ),
    "passes/r15/1401031b0.asm": (
        "0x140103425  MOV byte ptr [RBX + 0x20c0],AL",
        "0x140103451  MOV word ptr [RBX + 0x20be],AX",
        "0x140103a89  CALL 0x14013d140",
    ),
}


def package(work, pe):
    files, entries, passes = {}, {}, []
    for number, batch in BATCHES:
        folder = work / batch
        name = f"passes/{batch}"
        rows = json.loads((folder / "manifest.json").read_bytes())
        for row in rows:
            va = row["va"]
            entries[va] = prefix(pe, va)
            for suffix in ("c", "asm", "json"):
                filename = f"{va[2:]}.{suffix}"
                files[f"{name}/{filename}"] = (folder / filename).read_bytes()
        files[f"{name}/manifest.json"] = (folder / "manifest.json").read_bytes()
        for filename in ("headless.log", "seeds.txt"):
            files[f"{name}/{filename}"] = (work / f"{batch}-{filename}").read_bytes()
        passes.append(dict(round=number, name=batch, functions=len(rows)))
    for name in ("r12-default-bindings.json", "r13-mask-fixtures.json",
                 "r15-watch.txt", "r15-operands.json"):
        files[name] = (work / name).read_bytes()
    targets = {"0x140" + rva for rva in (
        "1ff820", "201dc0", "188a80", "188180", "21d4c0", "21cd80",
        "1040c0", "102ab0", "0c4660", "13d140",
    )}
    calls = json.loads((work / "index/calls.json").read_bytes())
    files["direct-calls.json"] = (json.dumps(
        [row for row in calls if row["target"] in targets], indent=2
    ) + "\n").encode()

    buffer = io.BytesIO()
    with tarfile.open(fileobj=buffer, mode="w", format=tarfile.PAX_FORMAT) as tar:
        for name, data in sorted(files.items()):
            info = tarfile.TarInfo(name)
            info.size = len(data)
            tar.addfile(info, io.BytesIO(data))
    packed = gzip.compress(buffer.getvalue(), mtime=0)
    previous = json.loads((DATA / "manifest.json").read_bytes())
    manifest = dict(target_sha256=pe.sha256, image_base=hex(pe.base),
                    previous_commit="2576100f81ed617a423b0fb85a473670f9ec8661",
                    tools=previous["tools"], native_gameplay_executed=False,
                    passes=passes, entries=entries, archive_sha256=digest(packed),
                    members={name: digest(data) for name, data in sorted(files.items())})
    (ARCHIVE / "exports.tar.gz").write_bytes(packed)
    (ARCHIVE / "manifest.json").write_text(json.dumps(manifest, indent=2) + "\n", newline="\n")


def verify_bindings(files):
    assembly = files["passes/r12b/140187560.asm"].decode()
    initial, tail = assembly.split("0x14018784d", 1)
    stores = re.compile(
        r"^0x[0-9a-f]+  MOV (byte|word|dword) ptr \[(RAX|RCX) \+ (-?0x[0-9a-f]+)\],(0x[0-9a-f]+)$",
        re.M,
    )
    size_by_kind = {"byte": 1, "word": 2, "dword": 4}
    layout = bytearray(0x2B8)
    for block, bases in ((initial, (0x12, 0xBA)), (tail, (0,))):
        for base in bases:
            for kind, register, offset, value in stores.findall(block):
                index = int(offset, 16) + (base if register == "RAX" else 0)
                size = size_by_kind[kind]
                require(0 <= index <= len(layout) - size, "Binding initializer store")
                layout[index:index + size] = int(value, 16).to_bytes(size, "little")

    bindings = json.loads(files["r12-default-bindings.json"])["bindings"]
    require([(b["slot"], b["profile"]) for b in bindings] ==
            [(s, p) for s in range(2) for p in range(4)], "Binding profiles")
    for binding in bindings:
        base = (binding["slot"] * 4 + binding["profile"]) * 42
        require(len(binding["rows"]) == 42, "Binding count")
        for action, row in enumerate(binding["rows"]):
            count = layout[0x160 + base + action]
            channel = 0x10 + base + action
            require(row["action"] == f"{action:02x}" and row["count"] == count and
                    row["channels"] == [f"{b:02x}" for b in layout[channel:channel + count]],
                    f"Binding row {base}/{action}")
            if count != 1:
                require(row["operator"] == layout[0x161 + base + action], "Binding operator")

    channels = {row["action"]: row["channels"] for row in bindings[0]["rows"]}
    require({a: channels[a] for a in ("02", "0c", "0d", "0e", "0f", "26")} == {
        "02": ["0e"], "0c": ["0d"], "0d": ["10"], "0e": ["0f"], "0f": ["ff"], "26": ["08"],
    }, "P0 role channels")
    fixtures = json.loads(files["r13-mask-fixtures.json"])
    raw_by_channel = {"08": 0x0002, "0d": 0x2000, "0e": 0x8000, "0f": 0x1000, "10": 0x4000}
    first, target = (sum(raw_by_channel[channels[a][0]] for a in actions)
                     for actions in (("02", "0c"), ("0e", "26")))
    mask = int(fixtures["mask"], 16)
    require(first == 0xA000 and first | target == mask == 0xB002 and
            mask & raw_by_channel[channels["0d"][0]] == 0, "P0 role masks")
    for case in fixtures["cases"]:
        p1, ready, result = (int(case[key], 16) for key in ("p1", "ready", "result"))
        require((p1 & ~mask) | (ready & mask) == result, case["name"])
    return len(bindings), len(fixtures["cases"])


def verify(pe):
    manifest = json.loads((ARCHIVE / "manifest.json").read_bytes())
    require(manifest["target_sha256"] == EXPECTED_SHA256 and
            manifest["image_base"] == "0x140000000" and
            not manifest["native_gameplay_executed"], "Target/provenance")
    require([(p["round"], p["name"]) for p in manifest["passes"]] == BATCHES, "Round order")
    packed = (ARCHIVE / "exports.tar.gz").read_bytes()
    require(digest(packed) == manifest["archive_sha256"], "Archive digest")
    files = {}
    with tarfile.open(fileobj=io.BytesIO(packed), mode="r:gz") as tar:
        for item in tar:
            path = Path(item.name)
            require(item.isfile() and not path.is_absolute() and ".." not in path.parts
                    and item.name not in files, f"Invalid member {item.name}")
            files[item.name] = tar.extractfile(item).read()
    require({n: digest(data) for n, data in files.items()} == manifest["members"], "Member digests")

    seen = set()
    instances = 0
    for batch in manifest["passes"]:
        name = f"passes/{batch['name']}"
        log = files[f"{name}/headless.log"]
        require(b"Save succeeded for" in log and b"NO_FUNCTION" not in log, f"Log {name}")
        rows = json.loads(files[f"{name}/manifest.json"])
        require(len(rows) == batch["functions"], f"Count {name}")
        require([r["va"] for r in rows] == files[f"{name}/seeds.txt"].decode().splitlines(),
                f"Seeds {name}")
        for row in rows:
            va = row["va"]
            stem = f"{name}/{va[2:]}"
            require(row["decompile_completed"] and row == json.loads(files[f"{stem}.json"]),
                    f"Function metadata {stem}")
            require(int(va, 16) - int(row["rva"], 16) == 0x140000000 and
                    files[f"{stem}.asm"].startswith(va.encode()) and
                    EXPECTED_SHA256.encode() in files[f"{stem}.c"], f"Export provenance {stem}")
            seen.add(va)
            instances += 1
    require(seen == manifest["entries"].keys(), "Unique entries")
    for name, instructions in WITNESSES.items():
        require(all(ins.encode() in files[name] for ins in instructions), f"Witness {name}")
    calls = json.loads(files["direct-calls.json"])
    require({r["site"] for r in calls if r["target"] == "0x14021d4c0"} ==
            {"0x140188ab8", "0x14022c0c1"}, "21D4C0 direct callers")
    operands = json.loads(files["r15-operands.json"])
    require(operands["sha256"] == EXPECTED_SHA256 and len(operands["rows"]) == 35
            and set(operands["watched"]) == {"20a6", "20a8", "20be", "20c0", "1eee"},
            "R15 literal candidates")
    profiles, cases = verify_bindings(files)
    if pe:
        require(all(prefix(pe, va) == data for va, data in manifest["entries"].items()),
                "PE entry bytes")
    return dict(result="PASS", rounds=len(ROUNDS), batches=len(BATCHES),
                unique_functions=len(seen), export_instances=instances, members=len(files),
                binding_profiles=profiles, button_word_cases=cases,
                original_pe_checked=pe is not None, native_gameplay_executed=False)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--binary", type=Path)
    parser.add_argument("--work", type=Path)
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

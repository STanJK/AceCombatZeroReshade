#!/usr/bin/env python3
"""Read PE64 headers, MSVC RTTI/vtables and imports without running the EXE.

The RTTI scanner validates the x64 CompleteObjectLocator self-RVA. A vtable
candidate is not proof that every virtual slot has an understood gameplay role.
"""
from __future__ import annotations
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct

EXPECTED_SHA256 = "43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664"


class PE:
    def __init__(self, path: Path):
        self.data = path.read_bytes()
        self.sha256 = hashlib.sha256(self.data).hexdigest()
        pe = struct.unpack_from("<I", self.data, 0x3C)[0]
        if self.data[:2] != b"MZ" or self.data[pe:pe+4] != b"PE\0\0":
            raise ValueError("not a PE image")
        machine, count = struct.unpack_from("<HH", self.data, pe+4)
        opt_size = struct.unpack_from("<H", self.data, pe+20)[0]
        opt = pe+24
        if machine != 0x8664 or struct.unpack_from("<H", self.data, opt)[0] != 0x20B:
            raise ValueError("expected AMD64 PE32+")
        self.base = struct.unpack_from("<Q", self.data, opt+24)[0]
        self.directories = [struct.unpack_from("<II", self.data, opt+112+i*8) for i in range(16)]
        self.sections = []
        for i in range(count):
            off = opt+opt_size+i*40
            name = self.data[off:off+8].rstrip(b"\0").decode("ascii")
            size, rva, raw_size, raw = struct.unpack_from("<IIII", self.data, off+8)
            flags = struct.unpack_from("<I", self.data, off+36)[0]
            self.sections.append(dict(name=name, size=size, rva=rva, raw_size=raw_size, raw=raw, flags=flags))

    def file_offset(self, va: int) -> int:
        rva = va-self.base
        for s in self.sections:
            if s["rva"] <= rva < s["rva"]+s["raw_size"]:
                return s["raw"]+rva-s["rva"]
        raise ValueError(f"VA {va:#x} has no file-backed bytes")

    def va(self, offset: int) -> int:
        for s in self.sections:
            if s["raw"] <= offset < s["raw"]+s["raw_size"]:
                return self.base+s["rva"]+offset-s["raw"]
        raise ValueError("unmapped file offset")

    def read(self, va: int, fmt: str):
        return struct.unpack_from(fmt, self.data, self.file_offset(va))

    def string(self, va: int) -> str:
        o = self.file_offset(va)
        return self.data[o:self.data.index(b"\0", o)].decode("ascii", errors="replace")

    def executable(self, va: int) -> bool:
        return any(s["flags"] & 0x20000000 and self.base+s["rva"] <= va < self.base+s["rva"]+s["size"] for s in self.sections)

    def imports(self):
        root, _ = self.directories[1]
        rows = []
        va = self.base+root
        while True:
            original, stamp, forward, name, first = self.read(va, "<IIIII")
            if not any((original, stamp, forward, name, first)):
                break
            dll = self.string(self.base+name)
            i = 0
            while True:
                ptr, = self.read(self.base+(original or first)+8*i, "<Q")
                if not ptr:
                    break
                symbol = "ordinal:"+str(ptr & 0xFFFF) if ptr >> 63 else self.string(self.base+ptr+2)
                rows.append(dict(dll=dll, name=symbol, iat_va=hex(self.base+first+8*i)))
                i += 1
            va += 20
        return rows

    def rtti(self):
        rows = []
        for match in re.finditer(rb"\.\?A[UV][ -~]{1,180}?@@\x00", self.data):
            name_va = self.va(match.start())
            td = name_va-16
            needle = struct.pack("<I", td-self.base)
            search = 0
            while True:
                at = self.data.find(needle, search)
                if at < 0:
                    break
                search = at+1
                col_off = at-12
                if col_off < 0 or col_off+24 > len(self.data):
                    continue
                sig, offset, cd_offset, type_rva, hierarchy_rva, self_rva = struct.unpack_from("<IIIIII", self.data, col_off)
                try:
                    col = self.va(col_off)
                except ValueError:
                    continue
                if sig != 1 or col-self.base != self_rva:
                    continue
                p = 0
                while True:
                    p = self.data.find(struct.pack("<Q", col), p)
                    if p < 0:
                        break
                    vt_off = p+8
                    try:
                        vt = self.va(vt_off)
                    except ValueError:
                        p += 1
                        continue
                    slots = []
                    for i in range(160):
                        if vt_off+8*(i+1) > len(self.data):
                            break
                        target, = struct.unpack_from("<Q", self.data, vt_off+8*i)
                        if not self.executable(target):
                            break
                        slots.append(dict(offset=hex(i*8), target=hex(target)))
                    if slots:
                        rows.append(dict(name=match.group()[:-1].decode(), type_descriptor=hex(td),
                                         locator=hex(col), object_offset=offset, cd_offset=cd_offset,
                                         hierarchy=hex(self.base+hierarchy_rva), vtable=hex(vt), slots=slots))
                    p += 1
        return rows


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("binary", type=Path)
    ap.add_argument("output", type=Path)
    args = ap.parse_args()
    pe = PE(args.binary)
    if pe.sha256 != EXPECTED_SHA256:
        raise SystemExit("Build mismatch: do not transplant this research to another binary")
    args.output.mkdir(parents=True, exist_ok=True)
    for name, value in [("pe-layout.json", dict(sha256=pe.sha256, image_base=hex(pe.base), sections=pe.sections)),
                        ("imports.json", pe.imports()), ("rtti-vtables.json", pe.rtti())]:
        (args.output/name).write_text(json.dumps(value, indent=2)+"\n", encoding="utf-8")
        print(name, len(value))


if __name__ == "__main__":
    main()

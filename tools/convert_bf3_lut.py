#!/usr/bin/env python3
"""
Convert BF3-Render-Stack's extracted legacy 32x32x32 RGBA8 DDS LUT into
a ReShade-friendly 1024x32 TGA strip.

No third-party Python packages are required.

Output layout:
  Z slice 0 | Z slice 1 | ... | Z slice 31
Each slice is 32x32, with X=R and Y=G.
"""

from __future__ import annotations

import argparse
import struct
from pathlib import Path

SIZE = 32
DDS_HEADER = 128
EXPECTED_PAYLOAD = SIZE * SIZE * SIZE * 4


def load_legacy_rgba8_volume(path: Path) -> bytes:
    data = path.read_bytes()

    if len(data) < DDS_HEADER or data[:4] != b"DDS ":
        raise RuntimeError(f"{path} is not a legacy DDS file")

    payload = data[DDS_HEADER:DDS_HEADER + EXPECTED_PAYLOAD]
    if len(payload) != EXPECTED_PAYLOAD:
        raise RuntimeError(
            f"DDS payload is {len(payload)} bytes; expected "
            f"{EXPECTED_PAYLOAD} bytes for 32x32x32 RGBA8"
        )

    return payload


def build_strip_bgra(payload: bytes) -> bytes:
    width = SIZE * SIZE
    height = SIZE
    out = bytearray(width * height * 4)

    # Source ordering matches BF3-Render-Stack:
    # payload.reshape(z=32, y=32, x=32, rgba=4)
    for z in range(SIZE):
        for y in range(SIZE):
            for x in range(SIZE):
                src = (((z * SIZE + y) * SIZE + x) * 4)
                r, g, b, a = payload[src:src + 4]

                dst_x = z * SIZE + x
                dst = (y * width + dst_x) * 4

                # Uncompressed 32-bit TGA stores BGRA.
                out[dst:dst + 4] = bytes((b, g, r, a))

    return bytes(out)


def write_tga(path: Path, pixels_bgra: bytes) -> None:
    width = SIZE * SIZE
    height = SIZE

    # 18-byte TGA header:
    # image type 2 = uncompressed true-color
    # 32 bpp, alpha depth 8, top-left origin (0x20)
    header = struct.pack(
        "<BBBHHBHHHHBB",
        0, 0, 2,
        0, 0, 0,
        0, 0,
        width, height,
        32,
        0x28,
    )

    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(header + pixels_bgra)


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("dds", type=Path)
    parser.add_argument(
        "-o", "--output",
        type=Path,
        default=Path("BF3_ColorGrading_32.tga"),
    )
    args = parser.parse_args()

    payload = load_legacy_rgba8_volume(args.dds)
    pixels = build_strip_bgra(payload)
    write_tga(args.output, pixels)

    print(f"Wrote {args.output}")
    print("Layout: 1024x32 RGBA8 TGA, 32 Z-slices left-to-right")


if __name__ == "__main__":
    main()

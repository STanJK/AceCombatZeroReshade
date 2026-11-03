#!/usr/bin/env python3
"""Compute static R7 projection fixtures without running ACZ."""
import argparse
import json
import math
from pathlib import Path

from pe_evidence import EXPECTED_SHA256, PE


def row_product(vector, matrix):
    return [sum(value * row[column] for value, row in zip(vector, matrix))
            for column in range(len(matrix[0]))]


def transpose(matrix):
    return list(zip(*matrix))


def yaw_matrix(angle):
    sine, cosine = math.sin(angle), math.cos(angle)
    return [[cosine, 0, -sine], [0, 1, 0], [sine, 0, cosine]]


def clip_accepts(clip):
    x, y, z, w = clip
    return all(map(math.isfinite, clip)) and all(-w < v < w for v in (x, y, z))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--binary", type=Path, required=True)
    args = parser.parse_args()
    pe = PE(args.binary)
    if pe.sha256 != EXPECTED_SHA256:
        raise ValueError("Unexpected ACZ executable")

    # 004E80 defaults, then 1FBEC0 with +1A8=1 and +1A0=0.
    half_extent, = pe.read(pe.base + 0x2D216C, "<f")
    flip, = pe.read(pe.base + 0x2D2D64, "<f")
    depth_factor, = pe.read(pe.base + 0x2D2D9C, "<f")
    near, far, focal = 1, 65535, 512
    sx, sy = focal / (640 * half_extent), focal / (480 * half_extent)
    dz = (far + near) / (far - near)
    dt = depth_factor * near * far / (far - near)
    projection = [[sx, 0, 0, 0], [0, flip * sy, 0, 0],
                  [0, 0, flip * dz, flip], [0, 0, dt, 0]]
    cases = []
    for name, eye, point, yaw in [
        ("forward", [0, 0, 0], [0, 0, -10], 0),
        ("translated_eye", [3, -2, 20], [3, -2, 10], 0),
        ("positive_yaw_30", [0, 0, 0], [0, 0, -10], math.pi / 6),
        ("turn_120", [0, 0, 0], [0, 0, -10], 2 * math.pi / 3),
        ("at_near_plane", [0, 0, 0], [0, 0, -1], 0),
        ("behind_eye", [0, 0, 0], [0, 0, 10], 0),
    ]:
        reference_ray = [p - e for p, e in zip(point, eye)]
        inverse_rotation = transpose(yaw_matrix(yaw))
        camera_ray = row_product(reference_ray, inverse_rotation)
        clip = row_product([*camera_ray, 1], projection)
        reference_clip = row_product([*reference_ray, 1], projection)
        ndc = [clip[0] / clip[3], clip[1] / clip[3]] if clip[3] > 0 else None
        if reference_clip[3] > 0 and ndc is not None:
            u, v = (component / reference_clip[3] for component in reference_clip[:2])
            ray = [u / sx, v / (flip * sy), -1]
            rotated = row_product(ray, inverse_rotation)
            remapped = [sx * rotated[0] / -rotated[2],
                        flip * sy * rotated[1] / -rotated[2]]
            if not all(math.isclose(a, b, rel_tol=0, abs_tol=1e-12)
                       for a, b in zip(ndc, remapped)):
                raise ValueError("Reference reprojection differs from direct projection")
        cases.append(dict(name=name, eye=eye, point=point, yaw_radians=yaw,
                          camera_ray=camera_ray, clip=clip, ndc_xy=ndc,
                          accepted=clip_accepts(clip)))

    # P90 keeps the legacy depth mapping and center. D0 supplies homogeneous clipping.
    legacy_max = 16777215
    a = (far - legacy_max * near) / (far - near)
    b = (legacy_max - 1) * near * far / (far - near)
    print(json.dumps(dict(target_sha256=pe.sha256, arithmetic="binary64 model of float32 instructions",
                          normalized_projection=projection, cases=cases,
                          legacy_depth=dict(near=a + b / near, far=a + b / far)),
                     indent=2))


if __name__ == "__main__":
    main()

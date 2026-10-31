#!/usr/bin/env python3
"""Freeze supplemental local Ghidra passes without replacing the older function index."""
import argparse
import gzip
import hashlib
import io
import json
from pathlib import Path
import tarfile
from pe_evidence import PE

ROOT = Path(__file__).resolve().parents[2]
DEST = ROOT / 'docs/reverse-engineering/coop/wingman'
TARGET = '43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664'
PASSES = ['r1', 'r1b', 'r1c', 'r1d', 'r2', 'r2b', 'r3', 'r3b']
DIRECT = set('0c6a50 0cbcc0 0cd880 0ce880 0d1780 0d2580 1040c0 115c20 119a30 121880 121eb0 1228b0 12aa30 12f340 132240 16eb20 16f6c0 166ee0 166f80 167080 167b00 16d1c0 18c6c0 1bd460'.split())

def digest(b):
    return hashlib.sha256(b).hexdigest()

def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--work', type=Path, required=True)
    ap.add_argument('--binary', type=Path, required=True)
    args = ap.parse_args()
    pe = PE(args.binary)
    if pe.sha256 != TARGET:
        raise ValueError('Target SHA mismatch')
    latest, passes, logs = {}, [], {}
    for name in PASSES:
        folder = args.work / name
        log = (args.work / f'{name}-headless.log').read_text()
        logs[name] = log
        if not ('Save succeeded for processed file: /acz.exe' in log or 'Save succeeded for: /acz.exe' in log):
            raise ValueError('Incomplete headless pass: ' + name)
        rows = []
        for meta_path in sorted(folder.glob('140*.json')):
            meta = json.loads(meta_path.read_text())
            if not meta.get('decompile_completed'):
                raise ValueError('Incomplete decompilation: ' + str(meta_path))
            stem = meta_path.stem
            files = {stem + ext: (folder / (stem + ext)).read_bytes() for ext in ['.c', '.asm', '.json']}
            if TARGET.encode() not in files[stem + '.c']:
                raise ValueError('Missing source provenance: ' + stem)
            latest.update(files)
            rows.append(stem)
        passes.append(dict(name=name, functions=rows, log_sha256=digest(log.encode())))
    DEST.mkdir(parents=True, exist_ok=True)
    (DEST / 'decompiled').mkdir(exist_ok=True)
    stream = io.BytesIO()
    with tarfile.open(fileobj=stream, mode='w', format=tarfile.PAX_FORMAT) as tar:
        for filename, data in sorted(latest.items()):
            info = tarfile.TarInfo('decompiled/' + filename)
            info.size, info.mode, info.mtime, info.uid, info.gid = len(data), 0o644, 0, 0, 0
            tar.addfile(info, io.BytesIO(data))
            if filename[3:9] in DIRECT:
                (DEST / 'decompiled' / filename).write_bytes(data)
    packed = gzip.compress(stream.getvalue(), mtime=0)
    (DEST / 'exports.tar.gz').write_bytes(packed)
    toolchain = json.loads((args.work / 'toolchain.json').read_text())
    for component in toolchain:
        component.pop('path', None)
    manifest = dict(
        format=1, date='2026-10-31', target_sha256=TARGET, image_base='0x140000000',
        tools=toolchain, scope='Supplemental exports; inferred Ghidra types; no game execution',
        native_gameplay_executed=False, base_index_replaced=False,
        passes=passes, unique_functions=len(latest)//3, direct_functions=len(DIRECT),
        archive_sha256=digest(packed),
        members=[dict(path='decompiled/'+n, bytes=len(b), sha256=digest(b)) for n,b in sorted(latest.items())],
        entries=[dict(va='0x'+n[:-5],rva=hex(int(n[:-5],16)-pe.base),first_32_file_bytes=pe.data[pe.file_offset(int(n[:-5],16)):pe.file_offset(int(n[:-5],16))+32].hex()) for n in sorted(latest) if n.endswith('.json')],
    )
    (DEST / 'manifest.json').write_text(json.dumps(manifest, indent=2)+'\n')
    (DEST / 'headless-logs.json.gz').write_bytes(gzip.compress(json.dumps(logs,sort_keys=True).encode(),mtime=0))
    candidates = json.loads((args.work / 'r2-operands.json').read_text())
    (DEST / 'operand-candidates.json.gz').write_bytes(gzip.compress(json.dumps(candidates, sort_keys=True).encode(),mtime=0))
    print(json.dumps(dict(functions=manifest['unique_functions'],members=len(latest),archive_bytes=len(packed))))

if __name__ == '__main__':
    main()

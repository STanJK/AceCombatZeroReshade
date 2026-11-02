#!/usr/bin/env python3
"""Freeze all five recursive cockpit rounds, including original pass versions."""
import argparse,gzip,hashlib,io,json,tarfile
from pathlib import Path
from pe_evidence import PE,EXPECTED_SHA256
ROOT=Path(__file__).resolve().parents[2]
DEST=ROOT/'docs/reverse-engineering/coop/cockpit'
ROUNDS=[['r1','r1b'],['r2','r2b'],['r3','r3b','r3c'],['r4','r4b'],['r5','r5b','r5c','r5d','r5e','r5f','r5g']]
DIRECT='0d2580 108620 0ae510 1fbec0 1fc350 187ec0 193cc0 20a000 20eeb0'.split()
def sha(b):return hashlib.sha256(b).hexdigest()
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('--work',type=Path,required=True);ap.add_argument('--binary',type=Path,required=True);a=ap.parse_args()
    pe=PE(a.binary);assert pe.sha256==EXPECTED_SHA256
    files={};latest={};passes=[];logs={}
    for rnd,names in enumerate(ROUNDS,1):
        for name in names:
            folder=a.work/name;log=(a.work/f'{name}-headless.log').read_bytes();logs[name]=log.decode()
            assert b'Save succeeded for processed file: /acz.exe' in log or b'Save succeeded for: /acz.exe' in log,name
            rows=[]
            for m in sorted(folder.glob('140*.json')):
                meta=json.loads(m.read_text());assert meta['decompile_completed'],m
                stem=m.stem;rows.append(stem)
                for ext in ['.c','.asm','.json']:
                    fn=stem+ext;b=(folder/fn).read_bytes();files[f'passes/{name}/{fn}']=b;latest[fn]=b
            files[f'passes/{name}/manifest.json']=(folder/'manifest.json').read_bytes()
            files[f'passes/{name}/seeds.txt']=(a.work/f'{name}-seeds.txt').read_bytes()
            misses=[l.split('NO_FUNCTION ',1)[1].split(' ',1)[0] for l in log.decode().splitlines() if 'NO_FUNCTION ' in l]
            passes.append(dict(round=rnd,name=name,functions=rows,no_function=misses,log_sha256=sha(log)))
    logs['r2b-incomplete-original']=(a.work/'r2b-incomplete-original.log').read_text()
    for fn,b in latest.items():files['decompiled/'+fn]=b
    stream=io.BytesIO()
    with tarfile.open(fileobj=stream,mode='w',format=tarfile.PAX_FORMAT) as tar:
        for fn,b in sorted(files.items()):
            i=tarfile.TarInfo(fn);i.size=len(b);i.mode=0o644;i.mtime=i.uid=i.gid=0;tar.addfile(i,io.BytesIO(b))
    packed=gzip.compress(stream.getvalue(),mtime=0);DEST.mkdir(parents=True,exist_ok=True)
    (DEST/'exports.tar.gz').write_bytes(packed);(DEST/'decompiled').mkdir(exist_ok=True)
    for stem in DIRECT:
        for ext in ['.c','.asm','.json']:
            fn='140'+stem+ext;(DEST/'decompiled'/fn).write_bytes(latest[fn])
    for src,dst in [('r1-operands.json','operand-candidates.json.gz'),('d3d12-methods.json','d3d12-methods.json')]:
        b=(a.work/src).read_bytes();(DEST/dst).write_bytes(gzip.compress(b,mtime=0) if dst.endswith('.gz') else b)
    (DEST/'headless-logs.json.gz').write_bytes(gzip.compress(json.dumps(logs,sort_keys=True).encode(),mtime=0))
    entries=[]
    for fn in sorted(latest):
        if fn.endswith('.json'):
            va=int(fn[:-5],16);off=pe.file_offset(va);entries.append(dict(va=hex(va),rva=hex(va-pe.base),first_32_file_bytes=pe.data[off:off+32].hex()))
    manifest=dict(format=1,research_date='2026-11-02 UTC',target_sha256=pe.sha256,image_base=hex(pe.base),tools=json.loads((a.work/'toolchain.json').read_text()),
        native_gameplay_executed=False,base_index_replaced=False,passes=passes,unique_functions=len(entries),export_instances=sum(len(p['functions']) for p in passes),
        direct_functions=len(DIRECT),archive_sha256=sha(packed),entries=entries,members=[dict(path=n,bytes=len(b),sha256=sha(b)) for n,b in sorted(files.items())])
    (DEST/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(json.dumps({k:manifest[k] for k in ['unique_functions','export_instances','direct_functions']}));print('archive_bytes',len(packed))
if __name__=='__main__':main()

#!/usr/bin/env python3
"""Verify five cockpit rounds, exact listings, ABI evidence and optional original PE."""
import argparse,gzip,hashlib,json,tarfile
from pathlib import Path
from pe_evidence import PE,EXPECTED_SHA256
ROOT=Path(__file__).resolve().parents[2];DATA=ROOT/'docs/reverse-engineering/coop/cockpit'
def require(v,msg):
    if not v:raise ValueError(msg)
def sha(b):return hashlib.sha256(b).hexdigest()
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('--binary',type=Path);ap.add_argument('--record',type=Path);a=ap.parse_args()
    m=json.loads((DATA/'manifest.json').read_text());require(m['target_sha256']==EXPECTED_SHA256,'Target SHA')
    require(not m['native_gameplay_executed'] and not m['base_index_replaced'],'Evidence scope')
    require({p['round'] for p in m['passes']}==set(range(1,6)),'Five rounds')
    require(sha((DATA/'exports.tar.gz').read_bytes())==m['archive_sha256'],'Archive SHA')
    expected={r['path']:r for r in m['members']};bodies={}
    with tarfile.open(DATA/'exports.tar.gz','r:gz') as tar:
        members=tar.getmembers();require(len(members)==len(expected),'Member count')
        require({v.name for v in members}==set(expected),'Member paths')
        for v in members:
            require(v.isfile() and '..' not in Path(v.name).parts and not Path(v.name).is_absolute(),'Safe archive member')
            b=tar.extractfile(v).read();r=expected[v.name];require(len(b)==r['bytes'] and sha(b)==r['sha256'],'Member digest '+v.name);bodies[v.name]=b
    entries={e['va'][2:]:e for e in m['entries']};require(len(entries)==m['unique_functions'],'Unique count')
    logs=json.loads(gzip.decompress((DATA/'headless-logs.json.gz').read_bytes()));instances=0
    for p in m['passes']:
        require(sha(logs[p['name']].encode())==p['log_sha256'],'Pass log');instances+=len(p['functions'])
        for stem in p['functions']:
            prefix='passes/'+p['name']+'/'+stem;meta=json.loads(bodies[prefix+'.json'])
            require(meta['decompile_completed'] and meta['va']=='0x'+stem,'Complete export')
            require(EXPECTED_SHA256.encode() in bodies[prefix+'.c'],'Listing provenance')
    require(instances==m['export_instances'],'Instance count')
    for stem in entries:
        meta=json.loads(bodies['decompiled/'+stem+'.json']);require(int(meta['va'],16)-int(meta['rva'],16)==0x140000000,'VA/RVA')
    for f in (DATA/'decompiled').iterdir():require(f.read_bytes()==bodies['decompiled/'+f.name],'Direct listing '+f.name)
    for stem,needles in {
        '108620':['0x140108959  LEA R8,[RSI + 0x10b0]','0x140108976  CALL 0x1400ae510'],
        '187ec0':['0x140187f3b  VCVTSI2SS XMM0,XMM0,ECX','0x140187f3f  VMULSS XMM0,XMM0,dword ptr [0x1402d1e98]'],
        '20eeb0':['0xb0]'], '20a000':['0xa8]','0xb0]','0x170]'],
    }.items():
        asm=bodies['decompiled/140'+stem+'.asm'].decode();require(all(s in asm for s in needles),'Instruction facts '+stem)
    require('float FUN_140187ec0' in bodies['decompiled/140187ec0.c'].decode(),'Correct analog ABI')
    api=json.loads((DATA/'d3d12-methods.json').read_text());methods={r['name']:r['offset'] for r in api['methods']}
    require(methods['RSSetViewports']=='0xa8' and methods['RSSetScissorRects']=='0xb0' and methods['OMSetRenderTargets']=='0x170','Official API slots')
    if a.binary:
        pe=PE(a.binary);require(pe.sha256==EXPECTED_SHA256,'PE SHA')
        for e in entries.values():
            o=pe.file_offset(int(e['va'],16));require(pe.data[o:o+32].hex()==e['first_32_file_bytes'],'PE entry '+e['va'])
    report=dict(result='PASS',rounds=5,passes=len(m['passes']),functions=m['unique_functions'],export_instances=instances,members=len(expected),original_pe_checked=bool(a.binary),native_gameplay_executed=False)
    if a.record:a.record.write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps(report,indent=2))
if __name__=='__main__':main()

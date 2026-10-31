#!/usr/bin/env python3
"""Verify supplementary corpus, direct excerpts and native-code facts; optionally original PE."""
import argparse
import hashlib
import gzip
import json
from pathlib import Path
import tarfile
from pe_evidence import PE, EXPECTED_SHA256

ROOT = Path(__file__).resolve().parents[2]
DATA = ROOT / 'docs/reverse-engineering/coop/wingman'

def require(value, why):
    if not value:
        raise ValueError(why)

def sha(b):
    return hashlib.sha256(b).hexdigest()

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--binary',type=Path)
    ap.add_argument('--record',type=Path)
    args=ap.parse_args()
    manifest=json.loads((DATA/'manifest.json').read_text())
    require(manifest['target_sha256']==EXPECTED_SHA256,'Target provenance')
    require(not manifest['native_gameplay_executed'] and not manifest['base_index_replaced'],'Evidence scope')
    require(sha((DATA/'exports.tar.gz').read_bytes())==manifest['archive_sha256'],'Export archive digest')
    expected={r['path']:r for r in manifest['members']}
    with tarfile.open(DATA/'exports.tar.gz','r:gz') as tar:
        require(len(tar.getmembers())==len(expected),'Duplicate/extra export member')
        require({m.name for m in tar.getmembers()}==set(expected),'Export member set')
        for member in tar.getmembers():
            require(member.isfile(),'Unexpected export kind')
            data=tar.extractfile(member).read();row=expected[member.name]
            require(len(data)==row['bytes'] and sha(data)==row['sha256'],'Export content '+member.name)
    direct=list((DATA/'decompiled').glob('*'))
    require(len(direct)==manifest['direct_functions']*3,'Direct excerpt count')
    for p in direct:
        require(sha(p.read_bytes())==expected['decompiled/'+p.name]['sha256'],'Direct excerpt drift '+p.name)
    for stem,needles in {
        '0cbcc0':['0x1400cd0c9  MOV qword ptr [R8 + RDX*0x1 + 0x1c0],R9','0xa82f8','0xa82f0','0x360'],
        '115c20':['0x140115ef3  CMP byte ptr [RBX + 0x235],R12B','0x140115efa  JNZ 0x140115f8a','0x140115f00  MOV RCX,qword ptr [RBX + 0x1b8]'],
        '0ce880':['0x1400d0075  MOV qword ptr [RSI + RAX*0x8 + 0x671f0],R15','0x1400d0084  MOV qword ptr [RSI + RAX*0x8 + 0x67210],R12','0x1400d0093  MOV dword ptr [RSI + RAX*0x4 + 0x67234],R14D'],
        '0d1780':['0x1400d19a3  MOVZX ECX,byte ptr [RDX + 0x3c9]','0x1400d19cb  MOVZX EBX,byte ptr [RDX + 0x3cc]'],
    }.items():
        asm=(DATA/'decompiled'/('140'+stem+'.asm')).read_text()
        require(all(n in asm for n in needles),'Instruction fact drift '+stem)
    require(len(manifest['entries'])==manifest['unique_functions'],'Entry count')
    logs=json.loads(gzip.decompress((DATA/'headless-logs.json.gz').read_bytes()))
    for row in manifest['passes']:
        require(sha(logs[row['name']].encode())==row['log_sha256'],'Headless log provenance '+row['name'])
    if args.binary:
        pe=PE(args.binary);require(pe.sha256==EXPECTED_SHA256,'Original PE SHA')
        for row in manifest['entries']:
            offset=pe.file_offset(int(row['va'],16))
            require(pe.data[offset:offset+32].hex()==row['first_32_file_bytes'],'PE fingerprint '+row['va'])
    report=dict(result='PASS',functions=manifest['unique_functions'],members=len(expected),direct_functions=manifest['direct_functions'],original_pe_checked=bool(args.binary),native_gameplay_executed=False)
    if args.record:
        args.record.parent.mkdir(parents=True,exist_ok=True);args.record.write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps(report,indent=2))

if __name__=='__main__':main()

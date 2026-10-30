#!/usr/bin/env python3
"""Audit crate dependency ownership, same-build facts, compatibility ID, optional Win64 exports."""
from __future__ import annotations
import argparse
import hashlib
import gzip
import json
from pathlib import Path
import re
import shutil
import struct
import subprocess

ROOT=Path(__file__).resolve().parents[2]
EXPECTED={
 'contracts':set(), 'protocol':{'contracts'}, 'session':{'contracts'},
 'replication':{'contracts','protocol'}, 'transport':{'contracts','protocol'},
 'game':{'contracts'}, 'trace':{'contracts','game'},
 'runtime':{'contracts','game','trace'},
 'cli':{'contracts','protocol','session','replication','transport','game'},
}
EXTERNAL={'contracts':set(),'protocol':set(),'session':set(),'replication':{'sha2'},
 'transport':{'hmac','sha2','getrandom'},'game':{'sha2'},'trace':set(),
 'runtime':{'minhook-sys','windows-sys'},'cli':set()}
def check(condition,message):
 if not condition:raise ValueError(message)
def sha(data):return hashlib.sha256(data).hexdigest()
def pe_exports(path):
 data=path.read_bytes();pe=struct.unpack_from('<I',data,0x3c)[0]
 check(data[:2]==b'MZ' and data[pe:pe+4]==b'PE\0\0','Not a PE')
 check(struct.unpack_from('<H',data,pe+4)[0]==0x8664,'Not AMD64')
 check(struct.unpack_from('<H',data,pe+22)[0]&0x2000,'Not a DLL')
 opt=pe+24;check(struct.unpack_from('<H',data,opt)[0]==0x20b,'Not PE32+')
 base=struct.unpack_from('<Q',data,opt+24)[0]
 table=opt+struct.unpack_from('<H',data,pe+20)[0]
 sections=[]
 for i in range(struct.unpack_from('<H',data,pe+6)[0]):
  s=table+i*40;size,rva,raw_size,raw=struct.unpack_from('<IIII',data,s+8);sections.append((rva,raw_size,raw))
 def off(rva):
  for start,size,raw in sections:
   if start<=rva<start+size:return raw+rva-start
  raise ValueError('Unmapped PE RVA')
 def string(rva):
  start=off(rva);end=data.index(b'\0',start,start+4096);return data[start:end].decode('ascii')
 er=off(struct.unpack_from('<I',data,opt+112)[0]);count=struct.unpack_from('<I',data,er+24)[0]
 funcs,names,ords=struct.unpack_from('<III',data,er+28);result={}
 for i in range(count):
  name=string(struct.unpack_from('<I',data,off(names)+i*4)[0]);ordinal=struct.unpack_from('<H',data,off(ords)+i*2)[0]
  result[name]=struct.unpack_from('<I',data,off(funcs)+ordinal*4)[0]
 check({'AddonInit','AddonUninit','NAME','DESCRIPTION'}<=result.keys(),'Missing ReShade exports')
 for symbol,expected in [('NAME','ACZ Coop'),('DESCRIPTION','Experimental ACZ read-only co-op research observer.')]:
  pointer=struct.unpack_from('<Q',data,off(result[symbol]))[0]
  check(string(pointer-base)==expected,'ReShade metadata must be a const-char-pointer export')
 imports=[]
 ir=struct.unpack_from('<I',data,opt+120)[0]
 if ir:
  cursor=off(ir)
  while True:
   descriptor=struct.unpack_from('<IIIII',data,cursor)
   if not any(descriptor):break
   imports.append(string(descriptor[3]));cursor+=20
 check(not {'libunwind.dll','libgcc_s_seh-1.dll','libwinpthread-1.dll'}&{s.lower()for s in imports},'Unstaged GNU runtime DLL dependency; use crt-static')
 check(not any(s.lower().startswith(('vcruntime','msvcp','concrt')) for s in imports),'Unstaged MSVC runtime DLL dependency; use crt-static')
 return dict(bytes=len(data),sha256=sha(data),exports=sorted(result),imports=sorted(imports))
def main():
 ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('--cargo');ap.add_argument('--dll',type=Path);ap.add_argument('--record',type=Path);args=ap.parse_args()
 cargo=args.cargo or shutil.which('cargo') or str(Path.home()/'.cargo/bin/cargo')
 metadata=json.loads(subprocess.check_output([cargo,'metadata','--manifest-path',str(ROOT/'coop/Cargo.toml'),'--no-deps','--format-version','1'],text=True))
 seen=set()
 for p in metadata['packages']:
  name=p['name'].removeprefix('acz-coop-');seen.add(name)
  internal={d['name'].removeprefix('acz-coop-') for d in p['dependencies'] if d['name'].startswith('acz-coop-')}
  external={d['name'] for d in p['dependencies'] if not d['name'].startswith('acz-coop-')}
  check(internal==EXPECTED[name] and external==EXTERNAL[name],f'Dependency boundary drift: {name}')
  for source in (Path(p['manifest_path']).parent/'src').rglob('*.rs'):
   text=source.read_text(encoding="utf-8")
   check('unimplemented!' not in text and 'todo!' not in text,f'Unimplemented placeholder: {source}')
   if name!='runtime':
    check(not re.search(r'\*mut\s|\*const\s|windows_sys|std::os::windows',text),f'Platform/raw pointer leak: {source}')
  if name!='runtime':check('#![forbid(unsafe_code)]' in (Path(p['manifest_path']).parent/'src/lib.rs').read_text(encoding="utf-8"),f'Unsafe ownership: {name}')
 check(seen==set(EXPECTED),'Workspace module set drift')
 digest=hashlib.sha256((ROOT/'coop/compatibility-v1.json').read_bytes()).digest()
 literals=re.findall(r'0x([0-9a-fA-F]{2})\b',(ROOT/'coop/crates/contracts/src/compatibility.rs').read_text(encoding="utf-8"))
 check(bytes(int(x,16)for x in literals)==digest,'Patch compatibility manifest stale')
 candidates=json.loads((ROOT/'docs/mp/HOOK_CANDIDATES.json').read_text(encoding="utf-8"))
 generated=(ROOT/'coop/crates/game/src/build_manifest.rs').read_text(encoding="utf-8")
 check(sha((ROOT/'docs/mp/HOOK_CANDIDATES.json').read_bytes()) in generated,'Native manifest provenance stale')
 expected={int(r['rva'],16):bytes.fromhex(r['first_32_file_bytes']) for r in candidates['candidates']}
 rows=re.findall(r'HookSpec\s*\{\s*name:\s*"([^"]+)",\s*rva:\s*(0x[0-9a-f]+),\s*bytes:\s*\[([^]]+)\]',generated,re.S)
 check(len(rows)==4,'Expected four native observer seams')
 for name,rva,body in rows:check(bytes(int(x,16)for x in re.findall(r'0x([0-9a-f]{2})',body))==expected[int(rva,16)],f'Fingerprint drift: {name}')
 evidence=ROOT/'docs/reverse-engineering/coop/evidence/decompiled'
 for filename,needles in {
  '1400cbcc0.asm':['0x1400cbe0d  LEA R12,[RBP + 0x240]','0x1400cc77d  MOV qword ptr [RSI + 0x1fc0],R12'],
  '1400cd880.asm':['0x1400ce067  LEA R12,[RSI + 0x240]','0x1400ce30d  MOV qword ptr [R14 + 0x1fc0],R12'],
  '14016e880.asm':['MOV RDI,RDX'], '14016f550.asm':['MOV RDI,RDX'],
  '1401040c0.asm':['MOVZX EDX,byte ptr [R15 + 0x20a1]','MOVZX EAX,byte ptr [R15 + 0x20a2]','IMUL RCX,RAX,0x520'],
 }.items():check(all(n in (evidence/filename).read_text(encoding="utf-8") for n in needles),'Native source mismatch: '+filename)
 holder=(ROOT/'docs/mp/execution/evidence/native-dispatch/1402010d0.asm').read_text(encoding="utf-8")
 check(all(n in holder for n in ['MOV RDX,RCX','CALL qword ptr [RAX + 0x20]','MOV AL,0x1']),'Holder ABI evidence drift')
 delta=json.loads((ROOT/'docs/mp/execution/evidence/native-dispatch/index-delta.json').read_text(encoding="utf-8"))
 base_path=ROOT/'docs/reverse-engineering/coop/evidence/program-index.json.gz'
 check(sha(base_path.read_bytes())==delta['base_index_sha256'],'Index delta provenance drift')
 baseline=json.loads(gzip.decompress(base_path.read_bytes()))
 for dataset,change in delta['datasets'].items():
  if 'replacement' in change:baseline[dataset]=change['replacement'];continue
  key=lambda v:json.dumps(v,sort_keys=True,separators=(',',':'))
  current={key(v):v for v in baseline[dataset]}
  for v in change['removed']:check(key(v) in current,'Unknown delta removal');del current[key(v)]
  for v in change['added']:check(key(v) not in current,'Duplicate delta addition');current[key(v)]=v
  baseline[dataset]=list(current.values())
 check(len(baseline['functions'])==delta['latest_function_count']==4793,'Supplementary function count drift')
 report=dict(result='PASS',modules=len(seen),dependency_boundaries='PASS',compatibility_sha256=digest.hex(),native_candidates=4,native_source_facts='PASS',gameplay_executed=False)
 if args.dll:report['windows_dll']=pe_exports(args.dll)
 if args.record:
  args.record.parent.mkdir(parents=True,exist_ok=True);args.record.write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
 print(json.dumps(report,indent=2))
if __name__=='__main__':main()

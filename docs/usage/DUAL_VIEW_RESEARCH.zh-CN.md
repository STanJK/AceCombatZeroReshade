# 阅读与复现五轮双视图研究

此处交付逆向证据和实施契约，没有可运行的双视图补丁。当前目标：主机单飞机，P1飞行/机炮，P2其余武器，
两独立摄像机；语义HUD共享，显示锚在机头。开始阅读 [本轮索引](../reverse-engineering/coop/cockpit/README.md)，
再读 [模块合同](../mp/cockpit/IMPLEMENTATION_CONTRACT.md) 和 [最小运行实验](../reverse-engineering/coop/cockpit/IMPLEMENTATION_GATES.md)。

## 校验与浏览

```bash
python tools/ghidra/verify_cockpit_evidence.py
python tools/ghidra/verify_coop_archive.py
# 本地另有合法原EXE时，加上：
python tools/ghidra/verify_cockpit_evidence.py --binary /path/to/acz.exe
mkdir -p /tmp/acz-cockpit-evidence
tar -xzf docs/reverse-engineering/coop/cockpit/exports.tar.gz -C /tmp/acz-cockpit-evidence
```

`decompiled/` 是按轮次取最新的合并视图；`passes/r4b/` 可看修正模拟量XMM0 float ABI后的函数。
每个函数有 `.c`（推断伪代码）、`.asm`（指令）、`.json`（prototype、调用者/被调者、交叉引用）。
`passes/*/seeds.txt` 与 manifest/log 对应，能检查每个实际追过的地址。不要把C里的推断形参数量直接抄成FFI。
同函数不同批次可能因ABI注释而改变伪代码；应交叉核对指令而非比较变量名。

## 本地重导出

使用归档 manifest 的固定 Ghidra12.2/JDK25.0.5+8及下载SHA。参考已有 [RESEARCH_TOOLING](RESEARCH_TOOLING.md)
首次导入合法EXE到自己的Ghidra项目，随后单写者执行定点导出；原始EXE和Ghidra数据库不在git内。

```bash
export JAVA_HOME=/path/to/jdk-25.0.5
/path/to/ghidra/support/analyzeHeadless /path/to/projects Cockpit \
  -process acz.exe -noanalysis -max-cpu 6 \
  -scriptPath "$PWD/tools/ghidra" \
  -postScript ApplyKnownInputContracts.java \
  -postScript ApplyCockpitContracts.java \
  -postScript ExportSelectedFunctions.java /path/to/output /path/to/extracted/passes/r4b/seeds.txt
```

若该项目尚无 `acz.exe`，先用 `-import /path/to/acz.exe` 完整分析一次，再用 `-process -noanalysis`。
`ApplyCockpitContracts` 要求相应函数已经被分析识别；它只修正存储类型，不会证明用户动作语义。
ZIP工具解压须保留Unix执行权限；headless日志必须有保存成功，且每个metadata的`decompile_completed`为true。

本轮使用 `ExportOperandCandidates.java` 将 watchfile 中的常量反查指令，只生成候选，不自动命名结构。
打包器 `package_cockpit_evidence.py` 是维护用冻结工具：它需要完整16批work目录、日志、工具来源、
原PE和SDK方法复核文件；普通读者无需重新打包即可独立校验档案。

## 现有demo与新目标的区别

[旧COOP_DEMO](COOP_DEMO.zh-CN.md) 的单机双进程CLI用于协议/模块模型，read-only observer用于观察。
它们不会新增第二相机、生成透明HUD或将P2输入接到原生武器路径。本轮没有改这些Rust实现。
下一步首先在一台完整Windows游戏安装上跑G0..G4；本地双视图不需要第二台机器。
实际远程P2阶段才需要另一输入/视频终端；可以同机第二进程验证传输，但仍不等同于画面/Gameplay验收。

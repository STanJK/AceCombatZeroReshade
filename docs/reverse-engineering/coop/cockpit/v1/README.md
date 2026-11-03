# V1 静态证据归档 R6–R10

目标为 ACZ x64，SHA-256 43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664，首选基址 0x140000000。本地 Ghidra 12.2 和 Temurin JDK 25.0.5+8 按初版记录的 SHA-256 恢复。所有分析均为静态。

共 13 批定点导出，113 次成功，覆盖 110 个唯一入口。其中 39 个此前未进入共享座舱 R1–R5 档案。每批保留 seeds、完整 headless 日志、汇编、伪代码和交叉引用。R6 操作数扫描仅提供候选。direct-calls.json 为本次 fresh index 的指定调用子集。旧档案的索引与符号未被替换。

[定版方案与五轮索引](../../../../mp/cockpit/v1/README.md) · [接入与运行验收](../../../../mp/cockpit/v1/INTEGRATION.md)

- 归档的每个文件有 SHA-256，函数入口有原始 PE 首 32 字节。[exports.tar.gz](exports.tar.gz) · [manifest.json](manifest.json)
- 归档与原 PE 校验结果单独保存。[verification.json](verification.json)
- 相机数值由静态恢复的投影式及 PE 常量计算，精度为模型中的 binary64。游戏内实际 pose、矩阵和画面待比对。[camera-fixtures.json](camera-fixtures.json)

在仓库根目录校验，提供自己的原始 acz.exe 可额外核对 PE 入口字节和重算相机样例。

```sh
python tools/ghidra/cockpit_v1_evidence.py
python tools/ghidra/cockpit_v1_evidence.py --binary /path/to/acz.exe
python tools/ghidra/cockpit_v1_camera_fixture.py --binary /path/to/acz.exe
```

复现导出时先按 manifest 工具版本分析原 PE。应用 ApplyKnownInputContracts.java 与 ApplyCockpitContracts.java 后，以各批 seeds.txt 为 ExportSelectedFunctions.java 的输入。R6 额外使用 ExportProgramIndex.java 和 ExportOperandCandidates.java。脚本读取 PE 与反编译结果，无需运行游戏。

# 设备输入逆向证据 R11–R15

在本地用 Ghidra 12.2 和 JDK 25.0.5 对同一 ACZ x64 目标完成五轮静态分析。9 批共 73 次成功导出，覆盖 53 个唯一函数入口。目标 SHA-256 为 `43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664`，首选基址为 `0x140000000`。

- 每批收录 seeds、headless 日志、反汇编、伪代码和函数元数据。清单保存文件 SHA-256 和原始 PE 的函数入口首 32 字节。[导出包](exports.tar.gz) · [清单](manifest.json)
- 同包收录八套默认绑定的复算数据、按钮字样例、直接调用索引子集和 R15 操作数候选。操作数匹配用于定位，机体字段结论以相应调用和反汇编为准。
- 原 PE 入口字节、映射复算及掩码样例已校验。游戏内设备分配、镜头和发射行为留待原生运行验收。[校验结果](verification.json) · [五轮计划、回写和接入契约](../../../../../mp/cockpit/v1/input/README.md)

在仓库根目录运行。提供对应的原始 `acz.exe` 可核对入口字节。

```sh
python tools/ghidra/cockpit_input_evidence.py
python tools/ghidra/cockpit_input_evidence.py --binary /path/to/acz.exe
```

复现导出时可沿用 [R6–R10 的 Ghidra 工程准备步骤](../README.md)，按批次使用包内 seeds 调用 `ExportSelectedFunctions.java`。R15 使用 `ExportOperandCandidates.java` 与 `r15-watch.txt`。调用子集来自同一 PE 的 `ExportProgramIndex.java` 索引。

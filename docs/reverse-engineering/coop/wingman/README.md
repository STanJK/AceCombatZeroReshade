# 原战役僚机接管：补充证据

日期 2026-10-31。本地 Ghidra 12.2 Headless / Temurin JDK 25.0.5+8。
目标 EXE SHA-256：`43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664`。
在用户本轮禁止 Toolhub 后没有使用任何 Toolhub 连接。

三轮由 8 次定点导出组成，合计 203 次函数导出、去重 169 个函数，包括旧集合的重叠复核，
**不等于新增 169 个已理解函数**。`exports.tar.gz` 保留全部 507 份 C、asm、JSON，
`decompiled/` 直接展示 24 个关键根。manifest 包含逐文件 SHA、工具来源和归档 SHA、
函数入口 32 字节。Ghidra prototype 是推断结果，不能据此直接调用原生函数。

阅读：[递归计划与三轮记录](../../../mp/wingman/REVERSE_PLAN.md)、
[模块实行书](../../../mp/execution/WINGMAN_LOCAL.md)、
[代码联系审计](../../../mp/execution/WINGMAN_AUDIT.md)、[用法](../../../usage/WINGMAN_LOCAL.zh-CN.md)。

| 证据 | 静态事实 | 尚不能声称 |
| --- | --- | --- |
| [0CBCC0](decompiled/1400cbcc0.asm) | helper[j] 绑定 group0/actor[j+1]；人类 player i 则绑定 group i/actor0 | 所有任务的 actor1 都是同一剧情角色 |
| [115C20](decompiled/140115c20.asm) | 人类 pose 和后处理包含 actor0 判断 | 改 +1B8 就已彻底消除僚机 AI |
| [119A30](decompiled/140119a30.c) | Actor/ObjPlane 数据转移、多段更新再写回 | 有一个可置空的独立 AI 总开关 |
| [0CE880](decompiled/1400ce880.asm) | 产生原生相机列表和 owner 索引 | 两个 viewport 就有正确的双机 HUD |
| [16F6C0](decompiled/14016f6c0.c)、[18C6C0](decompiled/14018c6c0.c) | VS 两机选择结果的读端/写端 | 菜单可脱离 ModeHolder 和资源事务直接调用 |
| [0D1780](decompiled/1400d1780.asm) | 事件表、kind、byte 子状态和世界状态共同参与处理 | phase=1 总是允许人类 P2 |

当前新增的是实际进程内取证；原生构造、AI 排他和事件接管尚未完成，没有新增游戏实测事实。

```bash
python tools/ghidra/verify_wingman_evidence.py --binary /path/to/acz.exe
mkdir -p /tmp/acz-wingman-evidence
tar -xzf docs/reverse-engineering/coop/wingman/exports.tar.gz -C /tmp/acz-wingman-evidence
```

对已有 Ghidra 项目使用 `-process acz.exe -noanalysis`，参照 ExportSelectedFunctions.java 导出
manifest 中的 VA。ExportWingmanOperands.java 可重新扫描字段候选；偏移相同不能证明结构相同。
package_wingman_evidence.py 检查 headless 完成日志和原目标 SHA 后封存结果。
补充档案不替换旧程序索引，不含 EXE 或 Ghidra 数据库。

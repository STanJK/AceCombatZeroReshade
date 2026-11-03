# 单飞机双视图：五轮递归逆向档案

共享座舱 V1 的 R6–R10 接入补证已另行归档。[V1 证据](v1/README.md) · [定版方案](../../../mp/cockpit/v1/SPEC.md)

研究日期：2026-11-02 UTC。当前目标是一份主机模拟、P1 飞行/机炮、P2 其余武器、两独立摄像机，
两人共享同一语义 HUD，显示以机头方向为基准。历史僚机接管、双游戏世界同步文档保留，当前接入顺序以本目录为准。

本次使用本地 **Ghidra 12.2 / JDK 25.0.5+8**，未连接任何 Toolhub。
目标 SHA-256：`43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664`。
没有执行 EXE，没有 Windows 游戏画面或两人操控实测；这是静态研究交付。

完成 **5 轮 / 16 次定点导出 / 124 次函数导出（101 个唯一函数）**。
每轮均有预先计划、实际定点逆向和结果回写；补追调用链包含在对应轮次内，不将补批次数当递归轮数。
Ghidra 推断类型不等于原始源码或可直接调用 ABI；本轮特别纠正 analog 查询的 float/XMM0 返回约定。

| 轮次 | 计划 | 结果 | 收敛点 |
| --- | --- | --- | --- |
| R1 | [计划](../../../mp/cockpit/ROUND_1_PLAN.md) | [回写](../../../mp/cockpit/ROUND_1_RESULT.md) | view/player count 分离，两个列表组，场景槽/所有权 |
| R2 | [计划](../../../mp/cockpit/ROUND_2_PLAN.md) | [回写](../../../mp/cockpit/ROUND_2_RESULT.md) | 1C0 Camera、矩阵和逻辑矩形；相机求解非纯函数 |
| R3 | [计划](../../../mp/cockpit/ROUND_3_PLAN.md) | [回写](../../../mp/cockpit/ROUND_3_RESULT.md) | HUD 硬编码相机、三类空间、一次生产和鼻向层 |
| R4 | [计划](../../../mp/cockpit/ROUND_4_PLAN.md) | [回写](../../../mp/cockpit/ROUND_4_RESULT.md) | held/edge/analog ABI、机炮/其他武器分权、相机/目标复用 |
| R5 | [计划](../../../mp/cockpit/ROUND_5_PLAN.md) | [回写](../../../mp/cockpit/ROUND_5_RESULT.md) | legacy register→现代裁剪；全帧提交与 epoch/fence |

阅读顺序：[总计划](../../../mp/cockpit/REVERSE_PLAN.md) →
[模块接口与验收](../../../mp/cockpit/IMPLEMENTATION_CONTRACT.md) →
[证据接点](EVIDENCE_MAP.md) → [未闭合项和最小实验](IMPLEMENTATION_GATES.md) →
[复现操作](../../../usage/DUAL_VIEW_RESEARCH.zh-CN.md)。

## 原始证据

- [manifest.json](manifest.json)：各轮根/成功函数/NO_FUNCTION、工具来源与 SHA、每成员 hash、入口32字节指纹。
- [exports.tar.gz](exports.tar.gz)：707 个成员；`passes/<name>/` 保存各批原始 C/ASM/JSON、根和批 manifest；
  `decompiled/` 是按研究轮次合并后的最新版本。看 action 查询时优先该最新目录的 r4b 注释后版本。
- [decompiled/](decompiled/)：9 个关键函数的 C/ASM/JSON 可直接浏览；其余在压缩档内。
- [headless-logs.json.gz](headless-logs.json.gz)：16 批完成日志，以及 r2b 初始化处截断的原日志。
  归档校验发现截断后已按原根列表重导出 r2b；不把截断当成功。
- [operand-candidates.json.gz](operand-candidates.json.gz)：R1 watchset 操作数命中，只是候选，不能因同常量就认定同结构。
- [d3d12-methods.json](d3d12-methods.json)：Microsoft DirectX-Headers API 槽位复核的来源/header SHA/结果。
- [verification.json](verification.json)：本地档案/原 PE 指纹检查通过记录。

主档案的 plans-and-usage 快照会同时封存本轮计划/结果与使用说明；旧 255 函数和 wingman 169 函数档案未被覆盖。
这些数字有重叠，不能相加作为唯一已研究函数数。新分析库自动识别数与旧库注释状态不同，不替换旧全局 index。

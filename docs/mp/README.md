# Multiplayer research and implementation plan

中文入口：[双人在线战役合作补丁实行书](COOP_PATCH_IMPLEMENTATION.zh-CN.md)。
运行入口：[完整 demo 操作说明](../usage/COOP_DEMO.zh-CN.md)。
本轮提交的是可追溯的静态研究、逆向任务矩阵和实施规范；运行时门槛仍需在完整游戏安装上验证。

Goal: **two people, two networked game instances, one shared campaign world,
from mission entry through the campaign's final result**.

Start with [the executed reverse-engineering plan](REVERSE_ENGINEERING_PLAN.md),
then [the patch implementation specification](COOP_PATCH_IMPLEMENTATION.md).
The authoritative static evidence is in
[`../reverse-engineering/coop/`](../reverse-engineering/coop/README.md), with a
code-usage guide in [`../usage/`](../usage/README.md).

Rust execution now lives in [`execution/`](execution/README.md) and the separate
[`coop/` workspace](../../coop/README.md): tested core modules plus a read-only
ReShade observer. Native gameplay mutation remains gated.

The branch contains research, extraction tools and an implementation contract.
It does not claim a playable multiplayer binary, a complete network serializer,
or a runtime-validated patch location. Required unresolved contracts are tracked
as explicit gates rather than hidden behind guessed function names.

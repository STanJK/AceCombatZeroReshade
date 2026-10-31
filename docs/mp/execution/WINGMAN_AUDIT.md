# 原僚机方向：实际代码联系与模块边界审计

2026-10-31；对照 [实行书](WINGMAN_LOCAL.md) 和 [三轮证据](../wingman/REVERSE_PLAN.md)。
**结论：W0–W3 及 W7 取证接入已经实现、通过本地构建/模块验证；W4–W6 的可玩接管未完成。**
下文的 PASS 均限定在所列验收层，不能替代完整功能验收。

## 逐模块审计

| 模块 / 实际文件 | 原生联系 | 验收及边界结论 |
| --- | --- | --- |
| W0 `coop/crates/wingman/src/native.rs`、`memory.rs` | 0CBCC0 的 group0/actor[j+1]、helper stride108、Actor+1C0/+360；沿已有 game 的 +228 原生 ID | 仅 MemoryReader；限界、部分读取、foreign human link、旧 epoch/错误身份拒绝通过；不把拓扑候选认定为故事角色 |
| W1 `selection.rs` | 16F6C0 读两个 profile 槽、18C6C0 写完整 DWORD | 两 profile、低 byte 混淆与颜色索引边界测试通过；无 profile/存档写入，没有假装实现菜单提交 |
| W2 `views.rs` | CE880 的 671F0/67210/67234/67230 | 0..4 视图，识别 P 内嵌双相机与外部事件相机；不创建 viewport/HUD，未越权负责渲染接管 |
| W3 `readiness.rs` | R2/R3 的原生缺口与已采集关系 | 即便合成内存有正确 P2 和两视图，也明确报告 AI/构造/事件/actor 分支等未实现；不会输出已可接管 |
| W7 `game::Observer::inspect` | 同一 mode+8、vtable、epoch 和游戏线程 | 不增加 pre_update sample；leave 后不可重新认领；线程/失效测试通过 |
| W7 `runtime/src/windows.rs` | 已验证 enter/leave/campaign update/VS update 四入口 | 原始 update(mode,holder) 保留 RCX/RDX 和原调用；新增采样只发生在 original 返回之后；默认关闭 |
| W7 `trace/src/lib.rs` | 接收只读拷贝值，不自行读 native | 有界 try-send，独立写线程；新增 JSON 序列化和真实 Rust→Python JSON 解析 smoke 通过，fixture 明确为合成数据 |

运行时组装依赖：`runtime → trace, wingman, game, contracts`；`trace → wingman, game, contracts`；
`wingman → game, contracts`。协议/复制/传输/CLI 没有依赖新原生取证数据或原始地址。
`verify_interfaces.py` 扩展为十模块白名单，unsafe、Windows API 和 Hook 仍仅归 runtime。

## 实际可执行验证

- Rust 1.99.1：Linux workspace **66 项测试通过**，fmt 和全目标 Clippy 通过。
- Windows gnullvm：release DLL/CLI 链接、全部测试程序链接和全目标 Clippy 通过；本地没有执行这些 EXE。
- PE 检查：四个 ReShade 导出、const-char-pointer 元数据及运行库依赖通过，没有新增需另带的 GNU/MSVC runtime DLL。
- 169 个去重导出、507 个成员、24 组直接展示文件、原 EXE 和入口指纹全部通过校验。
- `git diff --check` 通过。机器记录放在 [evidence/wingman](evidence/wingman/)。

交叉编译来自官方 LLVM-MinGW 20261020 msvcrt，SHA-256
`ceb8c5acc6f76e143f9c714772d2fa677027802561ce68c396e8dc990a80f0b6`，
使用 `-C target-feature=+crt-static`，不以本地链接代替 Windows 实际执行。

代码提交 `54daf0581342dfcb10018cbfa634a720d83bbe20` 的
[Linux / Windows CI](https://github.com/STanJK/AceCombatZeroReshade/actions/runs/41155025882)
均已成功，Windows 实际执行 **66 项测试通过**。
[Windows 观察器包](https://github.com/STanJK/AceCombatZeroReshade/actions/runs/41155025882/artifacts/13024058032)
ZIP SHA-256：`7ee3101d94c771aff211091211f2502eb497850179552f1333c563aa5bedc101`。
机器记录见 [ci.json](evidence/wingman/ci.json)。它仍是观察器包，不是可玩接管补丁；
后续本轮文档收尾提交不改变这些经过验证的 Rust 源码。

## 未完成及下一步所需证据

| 门槛 | 仍缺的内容 | 原生放行条件 |
| --- | --- | --- |
| 原剧情角色 | 多任务 Pixy/PJ/无僚机身份与 definition/资源对应 | 原 Actor 唯一身份，不误认其他 helper |
| W4 资源寿命 | 从 C6A50/C4660/C70E0/CBCC0/CD880 中分离第二上下文构造和匹配析构 | 原生分配/资源事务、故障回滚与重入，不触碰敌机和 VS 规则 |
| W5 AI 排他 | 12F340、119A30 子链、115C20 actor0 各分支的写入及武器 owner | 不改 +234/+235；Gameplay 无双写者，物理/命中/脚本继续工作 |
| W5 事件交接 | event kind/index/substate/flags 的逐任务语义 | 播片/关键事件撤销人类 lease、恢复无陈旧输入和资源引用 |
| W6 选择/视图 | VS UI ModeHolder 事务与资源回填、原生双 HUD 消费 | 确认/取消/换机、两相机/两 HUD、武器/锁定归属，战役规则保持 |
| HIL | 合法完整游戏资产和能运行目标的 Windows 环境 | 有/无僚机、两角色、武器、播片、死亡/重试、任务完成和重入实测 |

这些不是“还差测一下”的已实现功能；相关 native 创建、补丁和 UI/渲染接入代码尚未完成。
本版本保留显式 blocker，不提供成功占位返回，也不根据 phase=1 擅自允许玩法写入。

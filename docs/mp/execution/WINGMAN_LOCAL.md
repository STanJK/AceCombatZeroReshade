# 原战役僚机本地双人：模块实行书

2026-10-31；修订前基线 mp@4717943；研究入口：[三轮计划](../wingman/REVERSE_PLAN.md)。
这是替代“另造一个客机 Actor”的新方向。最终验收是单个战役世界、原剧情僚机、人类 P2、
原生双人选机和分屏；本轮不接网络。**三轮静态研究不等于上述功能完成。**

## 实施顺序、接口和单元验收

| 模块 | 标准输入 → 输出 | 所有权/约束 | 单元验收 | 当前放行 |
| --- | --- | --- | --- | --- |
| W0 原生对象取证 | `MemoryReader + VerifiedImage + NativeFrame → WingmanSnapshot` | 仅同一世代/同一游戏线程；有界读取；不保存可调用指针 | helper 与原 Actor 对应、敌机不可冒充、空/越界/旧世代拒绝 | 实现 |
| W1 双机选择读端 | `MemoryReader + VerifiedImage → SelectionSnapshot` | 仅拷贝两个 active-profile 结果；不写存档或改模式栈 | 两 profile、两槽位、颜色索引边界、不可读字段拒绝 | 实现 |
| W2 原生视图取证 | `MemoryReader + NativeFrame → ViewSnapshot[]` | 更新后读取两个相机列表和 owner 索引；不强制覆盖事件相机 | 0..4、外部相机标记、slot 范围、空指针拒绝 | 实现 |
| W3 就绪判定 | `WingmanSnapshot → Readiness` | 输出事实和缺口，不是原生写权限；不得用单个 world phase 推断 Gameplay | 无 helper、错误 P2 绑定、事件未知、AI/构造能力缺口显式报告 | 实现 |
| W4 第二原生上下文 | `SelectionSnapshot + CampaignWorld → GuestResources` | 游戏分配器、原生构造/释放、相机/HUD/武器资源；战役规则保持 | 故障注入逐阶段回滚、重试无悬空指针、敌机无改动 | **未放行** |
| W5 控制与 AI 交接 | `GuestResources + OriginalActor + EventGate → ControlLease` | 不改 Actor 身份；只在普通 Gameplay 独占输入和自主写者；脚本保留 | P2 松手不自主飞行/开火；关键事件恢复；同帧无双写者 | **未放行** |
| W6 选机/渲染接入 | `ControlLease + NativeModeStack → TwoLocalViews` | 复用 VS 菜单组件和相机消费；不进入 VS 世界规则 | 确认/取消/换机、两 HUD、武器 owner、分屏重入 | **未放行** |
| W7 loader/归档 | 已成功 ReShade API20 注入 → 取证 trace/构建产物 | 所有 unsafe/平台操作归 runtime；队列不阻塞游戏；退出后换 DLL | 接口白名单、Linux/Windows 构建、导出/依赖、证据完整性 | 扩展既有实现 |

W0–W3 实现为新增 `acz-coop-wingman` crate 的 `native / selection / views / readiness` 模块，
依赖 `contracts, game`。`trace` 消费其拷贝值；`runtime` 调用采样接口，不把原始地址暴露给网络/协议。
这部分是接入真实游戏内存的取证实现，不是飞行功能替身。

## W4 的原生调用事务

资源入口 0C6A50/0C4660/0C70E0/0CBCC0/0CD880 必须整理成可拆分的资源事务，
不能直接对已存在世界重跑整段初始化。count=2 会改变人类绑定、弹药/HUD 分支，
并默认把 P2 绑定到 group1/actor0。事务必须在原生分配完成后绑定原剧情 group0/actor1+，
保持原 Actor、定义、阵营和任务引用；发生失败时按原生析构顺序释放，不允许 memcpy 克隆 P1。

`GuestResources` 应仅由 native adapter 产生，包含 epoch、对象身份和资源完成标记；
不能由 UI、网络或测试凭空构造一个“已经 ready”的权限对象。现有证据尚不足以定义安全的
原生创建/释放序列，因此本版本不提供返回伪成功的构造 API。

## W5 的逐写者接管

12F340 的 follower 分配目标/操纵、119A30→121880/121EB0/1228B0 等非玩家链，
以及 115C20 的 actor0 判断都要逐段适配。不得禁用整个 Unit 更新；不得改 +234/+235 身份。
1040C0(P2, logical_index=1) 的设备逻辑可复用，但它的资源和 selectors 必须先有效。
排除 AI 不是在帧末覆盖坐标：需要保证操纵、目标选择和发射决定都只有当前控制者能够写入。

关键事件 gate 读取任务 controller 的 event kind/index/substate/flags、世界状态和原生输入禁用位。
gate 未识别、任务无僚机、死亡、暂停、离开和重试时先撤销 human lease，再走相应原生路径。
恢复时依据新 Actor/epoch 重建，不能复用上一任务地址。静态 phase==1 不足以颁发 lease。

## W6 的选择和视图事务

VS1/VS2 vtable+30 是页索引（0/1），不是“完成”接口。复用必须保留 ModeHolder 的压栈、
确认/取消、UI arena 释放、active profile 和新世界载入时点。选择结果先拷贝成值对象，
资源装载成功才提交。不得把 VS 的第二机编号直接写成 campaign 的僚机角色枚举。

最终视图沿原生 `671F0/67210/67234/67230 → 0D2580` 消费，
保留事件相机分支。每个视图需要对应有效 P、HUD、武器资源、viewport 和相机，
并验证 P2 HUD 的目标/锁定归属。只画两张场景图不通过验收。

## 禁止误报与最终验收

模型测试只证明策略/解码；交叉编译只证明 DLL 可链接；ReShade 加载只证明入口和 loader。
完整交付还要求合法完整游戏资产上的单机双手柄实测：有 Pixy/PJ 的不同任务、无僚机任务、
普通飞行/机炮/导弹/特殊武器、播片/关键事件、死亡/重试、暂停、任务完成和重新进入。
逐项记录游戏 build、模块提交、trace、两路输入动作和两机结果。

本地只有 EXE，没有完整游戏资产/可运行的 Windows 游戏环境；不使用 Toolhub。
未能取得的证据标记为 OPEN，不能以合成内存测试冒充游戏实测。

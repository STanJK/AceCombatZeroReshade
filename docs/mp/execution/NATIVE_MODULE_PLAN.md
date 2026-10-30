# 原生游戏与在线发布的后续模块实行书

这里细化 N01–N05 的施工接口与验收。**以下端口是设计提案，尚未实现或获准调用原生函数。**
当前九个 crate 的实际接口见 [API_MAP](API_MAP.md)。本文件不提供猜测的原生参数类型，
也不把模型中的 Pose、Spawn、SavePermit 当作原生函数 ABI。

上层目标与 M0–M6 见 [总实行书](../COOP_PATCH_IMPLEMENTATION.zh-CN.md)；
每个 RE 契约的入口、证据及实验见 [逆向计划](../REVERSE_ENGINEERING_PLAN.md)。
下面的函数名属于新 Rust 端口设计；地址均为当前白名单 EXE 的 RVA。

## 全模块共用边界

| 概念 | 提议契约 | 拒绝条件 / 所有权 |
| --- | --- | --- |
| `SimLease` | runtime 在已确认的模拟入口借出、仅当次调用有效；带本地世界 generation、网络 Epoch、accepted tick、原生线程身份 | 不可 Clone、不可跨线程 Send、不可跨 tick 保存；leave 在释放原生 arena 前失效 |
| `NativeHandle` | 本机表中的 `(generation, slot, incarnation)`，通过 EntityId 映射；适配器内部解析地址 | 网络中只传 EntityId；退休后 incarnation 改变；不能由收到的数字直接构造原生指针 |
| `ContentId` | 与双方资源 manifest 中的实际内容一一对应，配装/定义使用白名单 ID | 资源摘要/定义格式未确认时拒绝加载，不使用原生地址作 ID |
| `CommitReceipt` | 记录 Epoch、事件 ID、native effect 范围与已提交标记；只有适配器成功后才推进 EventCursor | 若原生调用部分成功且无法回滚，终止本世代并保留诊断，不能重试同一副作用 |
| `OwnerContext` | HostWorld、GuestReplica、LocalView、HostSave 明确区分；端口按能力接收 | 客机不能提交任务结果/AI 伤害/存档；view 不拥有游戏规则 |
| `CapabilitySet` | 基于确切构建、资源与对应 HIL 验收报告启用具体写能力 | 只读通过不放行写能力；版本变化使对应报告失效 |

Rust 所有权标记只防止补丁自身的常见误用，不能证明原生生命周期。
SimLease 的创建位置、重入和中断语义必须由 M0 跟踪确定；本轮没有实现此令牌。
有界队列在网络与模拟之间传递无指针命令，在模拟与呈现之间传递不可变投影。
队列满、缺资源、旧世代、错误线程、未知内容和不完整事务都必须有明确错误，不允许返回成功占位。

## N01：本地战役 P2、输入与视角

建议在 game 内分为 `campaign`、`input`、`view` 三个适配器；规则可移植部分保持独立，
不为每个原生函数增加一个 crate。N01 在接网络前完成 M1。

| 提议端口 | 输入 → 输出 | 与其他模块的标准联系 |
| --- | --- | --- |
| `CampaignBuilder::prepare` | VerifiedContent、MissionSelection、两份 Loadout → PreparedCampaign | 加载前扩展任务定义；输出拥有资源/定义内存的对象，生命周期覆盖整个原生世界 |
| `CampaignBuilder::attach` | SimLease、PreparedCampaign → HumanBindings | 建立两个 Player↔Actor 显式绑定；向 N02 注册两个稳定 EntityId；保留原有脚本编号 |
| `InputAdapter::apply` | SimLease、session::InputFrame、HumanBindings → InputReceipt | 使用已计算的 held/pressed/released；设备存在标志与槽映射单独审计；同 tick 不再生成边沿 |
| `ViewAdapter::project` | SimLease、LocalSlot、HumanBindings → ViewState | 主机跟 P1、客机跟 P2，各一个全屏视角/HUD；不能通过切 VS 规则取得镜头 |
| `CampaignBuilder::detach` | SimLease、HumanBindings → ReleaseReceipt | 先使句柄失效，再按原生所有权释放；异步消费者不再引用旧定义 |

实际追踪顺序：比较战役与 VS 任务资源；沿 `135B50/135CB0` 的分组容量/装载路径确认定义格式；
复核 `0C6A50` 十位置 ABI、两人配装及辅助数组；沿 `0CBCC0/0CD880/1040C0` 枚举绑定消费者。
`P+1FC0=W+240` 和 Player/Actor stride 已有静态证据，但并不涵盖定义所有权。

单元验收使用资源解析样本和纯 BindingMap：两个输入槽独立；已有任务编号不变；非法定义/缺资源拒绝；
重复 attach、半初始化失败、旧世代 detach 和错误线程拒绝；扩展容量计算无溢出。
这些测试需要真实格式样本后才能写，不能用自行假设的任务格式作为唯一夹具。

实机放行：两人独立飞行、开火、受伤；故事僚机和护航目标保持身份；进入/重试/退出多次无悬空；
只改本机视角不改变敌我/任务判定；HIL 同时记录资源分配释放、绑定、输入边沿和线程。
阻塞：当前只有 EXE，没有普通战役/VS 的完整任务、飞机、武器及关联资源，也没有 M0 运行轨迹。

## N02：实体身份、飞行与快照适配

| 提议端口 | 输入 → 输出 | 与其他模块的标准联系 |
| --- | --- | --- |
| `EntityAdapter::create/retire` | SimLease、内容定义、初始状态 / EntityId → NativeHandle / ReleaseReceipt | 主机分配 EntityId；客机仅按已认证 Host 事件创建；不得复用退休序号 |
| `EntityAdapter::resolve` | SimLease、EntityId → 当次借用的实体访问 | 仅模块内部暴露原生借用；映射表检查 generation 与 incarnation |
| `FlightAdapter::capture` | SimLease、实体集合 → FlightStateSet | 字段写入者/消费者、单位、坐标系、积分顺序均确认后，才转换到网络表示 |
| `FlightAdapter::apply_authoritative` | SimLease、完整基线或已确认 Delta → CommitReceipt | preflight 所有实体和字段后提交；不能只写位置，让其他积分状态下一步覆盖结果 |
| `FlightAdapter::predict/reconcile` | 自有输入历史、已确认基线 → 本机预测状态 | 首版可禁用预测；只有积分器闭环才启用，远端对象插值不能改变 HostWorld |

追踪 `0CE880`、`1040C0`、飞行状态写入链与 `1B9400/13D140/141200/13ACE0` 回放根。
回放仅提供字段/顺序线索；其中本机资源指针不能直接序列化。
实体创建、销毁、池复用和隐藏派生状态均要取得正常、失败与清理证据。

单元验收：create→retire→同槽新 incarnation 拒绝旧包；集合上限；unknown ContentId；
快照缺实体/非法数值/重复 ID 整体拒绝；坐标转换以原生样本 round-trip 验证；
预测重放相同输入具有明确误差上限。误差阈值先由 HIL 数据确定，不能现在填写任意“通过”值。

实机放行：保持油门/滚转等动作跨多 tick 后权威状态不被本机其他写入者覆盖；
目标实体生成/销毁/重用时没有幽灵或错误命中；双方日志能解释每一次修正。
N02 依赖 N01 的显式绑定、真实积分器字段契约和 M0 accepted tick。

## N03：武器、命中、伤害与得分

| 提议端口 | 输入 → 输出 | 与其他模块的标准联系 |
| --- | --- | --- |
| `WeaponAdapter::accept_fire` | SimLease、PilotInput、武器内容 ID → 发射结果/主机事件 | 主机执行接受判定；拒绝弹药/冷却不产生创建事件；重复输入不重复发射 |
| `WeaponAdapter::capture_lifecycle` | SimLease、原生弹体状态 → Spawn/Update/Expire 事件 | 关联发射者稳定 EntityId；N02 管理每个弹体的 generation/复用 |
| `CombatAdapter::resolve_host` | SimLease、命中/碰撞信息 → DamageOutcome | 仅主机运行递归伤害/死亡/得分；收集完整因果链，不能仅同步 HP |
| `CombatAdapter::apply_replica` | SimLease、权威事件 → CommitReceipt | 客机应用结果和表现；抑制对应本地规则副作用；EventCursor 成功后才确认 |
| `CombatAdapter::project_effects` | 已提交事件、LocalView → 表现请求 | 声音/特效独立去重，不能因为表现失败重跑伤害或保存 |

从现有三条发射根跟到池分配、碰撞、命中/消失、回收；
沿 `118040/117A10` 枚举递归、随机、归属、死亡和分数副作用。
当前协议的模型 Spawn/Damage 字段尚未证明足以表达全部原生武器；必要时升级协议与兼容摘要。

单元验收：重复/冲突事件、同 tick 双杀、攻击者已退休、弹体 ID 重用、
伤害到死亡的递归链、表现失败、事件缺口；每个事件至多一次规则提交。
故障注入必须覆盖原生“部分副作用成功”；无法回滚时整世代退出恢复，禁止简单重试。

实机放行：从实际资源枚举全部可选择武器，覆盖不同发射/命中/消失原因；
伤害、分数、死亡、特效与弹药一致；客机不会在应用结果前后额外裁决同一伤害链。
依赖 N02 的实体/内容映射，资源与伤害副作用契约闭环。

## N04：任务 VM、加载屏障、结果与存档

| 提议端口 | 输入 → 输出 | 与其他模块的标准联系 |
| --- | --- | --- |
| `MissionAdapter::prepare_transition` | Host 决策、下个内容选择 → TransitionProposal | session 升新 Epoch；两端内容校验和本机资源 ready 各自确认 |
| `MissionAdapter::commit_transition` | SimLease、双方 ready → TransitionReceipt | 仅主机开始新模拟；旧输入/事件/快照/原生句柄先失效，不沿用旧世界 |
| `MissionAdapter::capture/apply_events` | 主机任务 VM 输出 / 权威任务事件 → 有序事件 / CommitReceipt | 目标、影片、Boss 特殊逻辑与随机判定由主机拥有；客机本地推进受抑制 |
| `ResultAdapter::commit` | SimLease、主机 Verdict、世代 → 一次结算结果 | session::host_finish 与 replication Result 必须保持一致；重复结果不能重复奖励 |
| `SaveAdapter::commit_host` | 被消费的 SavePermit、结算 ID、主机存档拥有者 → SaveReceipt | 保存前备份；客机没有此能力；失败/崩溃恢复不能重复解锁和结算 |

追踪 `0D1780` 的阶段、GameEnd roots、模式切换和保存写盘根；
`16E4C0` 包含清理和配置回写，不能把整个 leave 当作可任意跳过的客机存档函数。
为每条任务规则标记 host-only、replicated、view-only 或仍未确认。

单元验收：只一方 ready、摘要不匹配、旧世代 ready、重复成功、失败后 retry、
结算与保存之间断线、保存事务错误、恢复后幂等；仅 HostSave 获得一次许可。
模拟文件存储可以测试事务编排，但原生保存实现必须额外验证真正写盘与回调边界。

实机放行：加载/成功/存档各阶段故障注入；主机备份可恢复；客机原存档字节不变；
任务目标/影片/路线切换一致。单人被击落的队友观察与双人失败必须覆盖脚本特判。
N04 依赖 N01–N03 和任务资源；完整路线以实际数据枚举，不凭任务标题推测。

## N05：在线传输、调度、诊断与发布

| 提议端口 | 输入 → 输出 | 与其他模块的标准联系 |
| --- | --- | --- |
| `OnlineSession::connect` | 私密加入凭据、兼容/内容摘要、端点策略 → 已认证连接身份 | 复用角色/协商语义；加密保密与密钥更新另行规范，不能把当前 HMAC 当作加密 |
| `Channels::send/receive` | Control、Input、Snapshot、Event 分类消息 → 完整合法消息或错误 | 输入避免可靠流阻塞；快照确认基线；控制/事件可靠有序；所有队列限长 |
| `SimDispatcher::step` | 已认证角色命令、SimLease → 当 tick 输入/事件/快照提交 | 网络线程不解析游戏地址；暂停不消耗模拟 Tick；超时仍按单调墙钟 |
| `Recovery::observe` | 心跳/ACK/缺口/断线 → 恢复或受控退大厅 | 首版无中途加入/主机迁移；断线不得让旧世界继续接受客机包 |
| `Diagnostics::export` | 两端 trace、协议与能力版本 → 可关联诊断包 | 不导出 PSK、凭据、游戏 EXE 或资源；保留 event/epoch/digest/性能因果 |

当前 TCP 原型只证明消息/认证与跨模块语义；最终传输选型依据测量决定，
先验证局域网，再测试公网直连、NAT 和中继；不依赖第三方服务固定在线来完成单元验收。
传输替换必须保留 protocol/session/replication 的角色、顺序、上限和故障契约。

单元与集成验收：确定性网络故障调度覆盖丢包、重复、乱序、基线缺失、过期认证、
输入停止/恢复、计数耗尽、队列饱和、时钟边界和暂停；错误不得半提交下一 tick。
跨机验收使用总实行书的 RTT/抖动/丢包矩阵，记录输入延迟、修正幅度、带宽、事件缺口与帧时。
只有真实双机完成全部约定战役路线并审计主机存档，才将 playable_coop_patch 改为 true。

## 顺序、回退与交付证明

M0 观察通过 → N01 本地双人通过 → N02/N03 生命周期与状态 → N04 任务/保存 → N05 公网与路线。
现有 E01–E09 为这些阶段提供基础，不替代前置原生证据。
每个模块提交同时交付：实际源码、公共接口变更、消费者迁移、单元正反例、
原生 ABI/资源/线程证据、HIL trace 与已知开放项。

若某函数的 ABI、资源所有权或清理实验未闭环，只提交观察/离线解析和明确的未支持错误。
新增代码先按模块验收，再运行全 workspace 与接口审计，最后更新反向档案的不可变快照。
移除新增 add-on 后应恢复原有启动流程；没有证明可热卸载的 detour 不在运行中释放。

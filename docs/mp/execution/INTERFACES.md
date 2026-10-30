# 模块标准接口 v0

## 依赖与所有权

`contracts` 是唯一公共类型来源。`protocol` 负责字节而不访问 socket。
`session` 负责角色和阶段；`replication` 负责状态/事件；两者不持有 OS 句柄或游戏指针。
`transport` 提供已认证的完整帧；只有连接握手确定的角色可作为发送者身份。
`game` 通过只读 MemoryReader 读取，Win32 实现在 runtime。runtime/CLI 是装配根。
不通过全局变量把核心状态传播到其他 crate，不让 transport 依赖 game/runtime。

所有可移植 crate 禁止 unsafe。原生指针只存在于 game 只读观察接口及 runtime，
不进入网络 DTO。原生的三分量 orientation-like 数据不自动解释成网络四元数。

## 字节与版本

应用头沿用 40 字节草案：magic 4、version 2、kind 2、session 16、epoch 4、sequence 4、
tick 4、length 2、flags 2。保留位必须为零，精确消费载荷，不接受尾部垃圾。
输入为 18 字节；每块快照前缀 16 字节、每姿态 52 字节，最多 20 个姿态，报文不超过 1200。
本轮只实现完整基线（baseline=0），Delta 未实现时明确拒绝，不猜测基线。
Prepare 携带 EXE SHA、补丁兼容契约 SHA、内容 SHA、任务和难度；三者均核对后才就绪。
Ack(kind=9) 为 event:u64、snapshot:u32、state_sha256:32 字节。Spawn 还携带初始 signed16 HP；
Damage.score 是绝对主机总分。
网络姿态必须有限，四元数范数平方须在 0.999..1.001 内；ID 的世代必须等于报文世代；禁止零实体序号。

## 会话与时钟

epoch=0 保留给无世界阶段，运行世代从 1 开始，重试单调增加、溢出失败。
u32 包/输入/Tick 比较使用半区规则；差值正好 2^31 视为歧义并拒绝。
事件 ID 在世代内严格递增。保留最近 64 个已提交事件：相同内容重复不再应用，
同 ID 异内容返回 Conflict，更早的事件返回 Stale；缺口要求恢复。
网络墙钟用单调时间，游戏 Tick 用已确认的模拟入口；两者不能互相替代。

只有 host 可准备、开始、暂停、确定结果和拥有存档。guest 输入固定属于 slot 1，
host 属于 slot 0。输入包所属槽与连接身份双重校验；迟到、重复和超前窗口之外的输入
不生成新边沿。超时按规则归零按住状态，避免无期限持续开火。

## 有界 IO 与故障

所有长度在分配前检查。TCP 实验通道的每次读写有总截止时间，部分交换失败后连接失效。
transport 接管 TcpStream 时显式设置阻塞模式，再使用总截止时间；不依赖不同 OS 的 accept 继承行为。
认证使用双方独立随机 nonce 与 PSK HMAC；不能复用固定 nonce、从报文自报角色，或把 PSK 写日志。
本轮 TCP 用于可验收的可靠直连基础，不声称已满足最终 Internet 低延迟或加密保密需求。
队列满返回明确错误/丢弃计数，不等待游戏线程。IO/JSON/文件写入不进入原生 Hook。
trace 写端在队列空闲 20ms 后 flush，退出/离开世界记录无需等到进程结束才可见；
该周期是调度目标，操作系统调度和文件系统延迟仍可能超过 20ms。

快照组装只在完整、无冲突、同世代/ID/Tick 时产生可应用包。
权威事件只有在适配器成功之后才能推进提交游标；无法证明原生部分失败回滚时，
该写适配器保持禁用。模型端只证明数据与接口，不能证明原生事务成立。

## 原生观察接口

模式 enter 后登记对象；update 在原始调用前只读观察；leave 在原始调用前使观察世代失效。
玩家 +1FC0 指向 W+240 子对象，不是世界基址。
观察从 mode+8 获取 W，避免使用可能滞留的 33D9D8 全局作为存活依据。
每次观察校验模式 vtable、ready、数量、选择器和 Actor→Player 链接；失败不解引用。
update ABI 为 `(mode: usize, holder: usize) -> ()`，必须保留 RDX。
观察记录的 tick 只是原生候选值，不把重复 update 误记为新的权威模拟步。

运行时默认只登记/诊断，原生观测 Hook 需显式开启。所有游戏写接口返回 Unsupported，
直到对应 RE 契约和游戏内验收完成。ReShade 回调、DllMain、网络线程不执行游戏写操作。

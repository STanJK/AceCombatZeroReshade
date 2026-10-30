# 逐模块实现与接口审计

施工前文档与原生依据审计已完成，见 SOURCE_AUDIT。
以下记录按实际执行追加；未运行的测试不能写 PASS。

| 模块 | 实现 / 验收 | 跨模块接口审计 | 状态 |
| --- | --- | --- | --- |
| E01 contracts | 4 项单元测试 | std-only；无指针/平台依赖 | 本地通过 |
| E02 protocol | 5 项单元测试 | 显式编码/精确长度；兼容 SHA、初始 HP 与 Ack 同步 | 本地通过 |
| E03 session | 6 项单元测试 | 主机权限、一次许可、输入窗口/边沿/世代 | 本地通过 |
| E04 replication | 8 项单元测试 | 完整分块与失败原子性、事件序列/去重 | 本地通过 |
| E05 transport | 8 项单元测试 | 双向认证、每帧 MAC/计数、限长、总超时、错误后失效 | 本地通过 |
| E06 game | 8 项单元测试 + 真实 EXE doctor | 指纹/ABI/偏移与实际指令核对；修正 +1FC0 | 本地静态/模型通过 |
| E07 trace | 5 项单元测试 | try-send 与独立写端、容量/丢弃/IO 错误 | 本地通过 |
| E08 runtime | 4 项单元测试 + Windows x64 链接 | API 20 导出、原始调用、4 个入口；无热释放 | 构建通过；HIL 未执行 |
| E09 cli | 3 项单元 + 2 项 CLI 集成 | 双进程/四次摘要/失败摘要/重试旧包 | 本地通过 |

游戏内 M0–M6：未执行。原生写入契约：仍受 RE05–RE17 阻塞。

## E01 contracts

实现公共角色/槽、世代与实体 ID、半区序列比较、控制样本、网络姿态及内容协商。
`cargo test -p acz-coop-contracts`：4 个测试通过（每项含多个边界断言）。
审计：std-only、禁止 unsafe，无指针/IO；非零 ID、世代耗尽和 NaN/Inf 会拒绝。
网络四元数是补丁格式，未将原生 orientation-like 数据强制解释成四元数。

## E02 protocol

实现严格的 40 字节包头、18 字节输入、完整快照分块和权威事件编码/解码。
5 个测试通过：Golden、全部消息与每个截断、错误字段/ID/NaN、容量与空世界、1500 组有界噪声。
审计：只依赖 contracts；头部/载荷精确长度；先限长再分配；无指针/unsafe/IO。
新增决定：v1 只接受 baseline=0 的完整快照，未实现的 Delta 明确拒绝。

## E03 session

6 个测试通过：双方就绪/主机权限、一次存档许可与重试、协商失败不推进、输入边沿/超时、
槽伪装与回绕/旧世代、队列满后序列不半提交。输入消费显式要求连续 accepted tick；
暂停时不消费，网络墙钟继续。审计：只依赖 contracts；旧世代保留拒绝语义，恢复到大厅不复用世代。

## E04 开工接口修订

复制端需要初始健康值，给 v1 草案 Spawn 事件补充 signed16 HP，并同步修改 protocol 编解码/测试。
Damage.score 定义为主机给出的绝对总分，避免消费者把结果误作增量。
这次草案尚未发布兼容二进制，不承诺与先前未发布的内存格式兼容。

## E04 replication

7 个复制测试以及修改后的 5 个协议测试通过。完整分块支持乱序，缺块不暴露部分状态；
冲突、旧快照、旧世代、未知实体、事件缺口与重复会拒绝，失败不推进提交游标。
审计：只依赖 contracts/protocol；活跃实体与组装容量有上限，退休序号不复用。
伤害允许源实体已退休的迟到弹体结果；不要求通过旧原生指针查找攻击者。
快照完成交付与世界成功应用为两个阶段，只有后者可确认基线。未实现 Delta。

## E05 transport

6 个实际 TCP 回环测试通过。双方随机挑战与方向分离的 PSK HMAC，逐帧另加 MAC 和 u64 计数器；
拒绝错误密钥、客机冒充主机消息、篡改 MAC、超长/截断帧；超时后连接失效。
审计：无 native/runtime 依赖；总截止时间约束整次交换，分配前限长，密钥不实现 Debug。
这是有认证/完整性的明文 TCP 原型，不声称 TLS 保密或最终 Internet 低延迟性能。

## E06 game

7 个单元测试通过：错构建/非代码地址、所有观测指纹、生命周期与双向绑定、线程、
未初始化世界禁读、读取/选择器失败不发帧、原生写入仍拒绝。
审计：game 内无 unsafe，通过 MemoryReader 隔离平台；模式/世界来源对应原生 C/asm。
从同构建 JSON 生成 4 个观测入口的指纹。enter/leave 维护本地 generation，与网络 epoch 分离。
观测保留原生 orientation-like 原值；没有伪造坐标单位或网络四元数转换。
真实 EXE 的构建校验还将在 doctor 集成执行；内存测试不等于实机生命周期通过。

## E07 trace

4 个测试通过：满队列丢弃计数、断开计数、原生记录/来源/结束摘要、IO 失败可见和容量拒绝。
审计：Hook 仅 try-send；JSONL 和文件写入由消费者完成。std 通道未宣传为 lock-free；
没有等待容量的 send。停止时最多排空一个容量，避免有错误生产者时无限停不下来。
本地 generation 与原生 tick 候选分别记录，未把渲染帧号当作模拟时钟。

## E08 runtime

4 个安装/配置单元测试通过。固定 ReShade v6.8.0 官方源码核实 AddonInit/AddonUninit；
新运行时通过 AddonInit 注册 API 20，在 DllMain 之外初始化。默认不启用原生 Hook。
本地 LLVM-MinGW 交叉链接 Windows x64 DLL 成功（gnullvm release）；不等于游戏实测。
审计：4 个 Detour 保留正确 RCX/RDX，leave 前失效；回调只读 + try-lock/try-send；
MinHook 负责指令重定位。模块 pin、trampoline 进程期保留，卸载仅停采样，不做不安全的热释放。

## E09 开工接口修订

增加补丁兼容契约 SHA（来自 compatibility-v1.json）到双方协商，避免只核对 EXE；
新增 Ack(kind=9)：最后事件、快照 ID、规范化世界状态 SHA-256。
网络演练必须比较两端摘要，不能把收到一条心跳当作状态一致。
这些变更同步更新 contracts/protocol/replication 和消费者测试。

## E09 cli / 集成

CLI 的单元与命令行测试通过；独立进程 model demo 和真实 EXE doctor 已实际运行。
两端经认证 TCP 完成协商/就绪、输入去重、逆序分块、伤害去重、主机唯一存档许可、
结果与重试；4 次状态 SHA/事件/快照游标比较一致，旧世代事件和快照均拒绝。
新增负向验收：经过认证但摘要不一致的 Ack 必须拒绝。模型没有调用任何游戏写函数。
审计：CLI 只依赖可移植核心与构建检查，不链接 runtime 注入层；runtime→game/trace 为另一装配路径。
最终全量测试、Windows 构建/导出和文档校验见 VALIDATION。

## 最终跨模块审计补充

- 全量本地测试：53/0；fmt、Linux 和 Windows gnullvm 全目标 clippy（-D warnings）通过。
- GNU 产物依赖检查发现初版引用 libunwind.dll；启用 crt-static 重新链接后，DLL/CLI 只导入系统 DLL，未附带另一个加载代理。构建脚本同步设置并恢复目标环境变量。
- P+1FC0 的同源夹具错误已由实际初始/重置指令纠正，额外回归测试通过。
- 两个 ModeHolder 额外导出核实 update 的调用参数和返回值，不将 holder 的 AL 返回值误加给 mode update。
- 源码中没有 todo!/unimplemented!；未闭环的原生写入以明确 Unsupported 阻塞，而非成功占位。

- 最后审计收紧网络四元数范数；已提交事件增加 64 项有界内容缓存，同 ID 不同结果返回 Conflict，更早报文返回 Stale。兼容清单 SHA 和相关断言同步更新。

## 发布后跨平台字节复核

Git core.autocrlf=true 的真实过滤器会改变兼容 JSON 的 SHA，也会使逐文件归档哈希失效。
新增 .gitattributes 固定文本 LF、压缩包/二进制不转换；再次用同一过滤器检查字节完全相同。
这是工作树字节兼容修复，不改变线协议、原生代码或 51 项测试的逻辑。

## 遥测退出事件的可见性

空闲 20ms 后由写入线程 flush 缓冲，避免返回菜单后最后的 world_left 记录一直留在缓冲。
真实线程 + BufWriter 测试确认在停止写端之前已能读到该记录；游戏线程仍不执行 IO。

## Windows 运行验收：连接状态继承

`0ef78f1` 的 Windows job 已通过接口校验和完整编译；双进程 model demo 暴露传输接管契约缺口。
原诊断在 host 失败后杀掉 guest，又以 guest 的空 stderr 覆盖主错误。现保留主错误与子进程退出状态。
参考 [Microsoft accept 文档](https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-accept)，
Windows accepted socket 具有监听端的属性。transport 两个构造入口现在显式 `set_nonblocking(false)`，
再使用原有总截止时间，不让上层 listener 的轮询策略进入传输内部。
新增双向非阻塞 socket 接管测试；全量本地 53/0，跨编译检查与链接通过。
公开方法、依赖边界和线协议未变化；CI 再验 Windows 原生双进程及 release CLI，结果见 VALIDATION。

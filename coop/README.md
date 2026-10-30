# ACZ Co-op Rust foundation and read-only observer

实现与验收说明：[docs/mp/execution](../docs/mp/execution/README.md)。
这是已实现的协议/会话/复制/传输基础与原生只读观测器，**尚不具备可玩的战役合作**。
模型演练、DLL 编译、游戏内 HIL 分开验收。

| Crate | 边界 |
| --- | --- |
| contracts | 角色、ID、世代、输入、有限网络姿态、补丁兼容契约 |
| protocol | 有界、显式小端编码；完整快照和权威事件、摘要 Ack |
| session | 主机权限、就绪/暂停/结果/重试、输入窗口/边沿、一次存档许可 |
| replication | 分块完整提交、实体身份与事件去重、规范化状态摘要 |
| transport | 双向随机挑战 PSK HMAC、逐帧完整性和计数器、有总截止时间的 TCP |
| game | SHA/PE/指纹与只读 MemoryReader、生命周期/线程/Actor 绑定 |
| trace | 有界 try-send、丢弃计数、独立 JSONL 写端 |
| runtime | ReShade API 20 AddonInit、可选原生观测 Hook、Win64 FFI |
| cli | doctor、双进程模型演练、直连模型端、密钥文件生成 |

依赖有两个装配根：CLI → 可移植核心；runtime → game/trace → contracts。
网络 DTO 不包含原生指针，原生 orientation-like 数据不等同于网络四元数。

## 本地运行

Rust 工具链版本见 rust-toolchain.toml；本轮使用 rustc/cargo 1.99.1。
从仓库根目录执行：

```bash
cargo test --manifest-path coop/Cargo.toml --workspace --locked
cargo run --manifest-path coop/Cargo.toml -p acz-coop-cli --locked -- demo
cargo run --manifest-path coop/Cargo.toml -p acz-coop-cli --locked -- doctor /path/to/acz.exe
python3 coop/tools/verify_interfaces.py
```

`demo` 启动独立客机子进程，通过系统 TCP loopback 完成模型流程，并比较 4 次世界摘要。
它使用临时随机密钥文件，结束后删除。输出固定标记 `scope=model, native_gameplay=false`。

也可在两台机器/终端上运行模型端（不是游戏联机）：

```text
acz-coop keygen session.key
acz-coop host-model 0.0.0.0:48123 session.key
acz-coop guest-model HOST_IP:48123 session.key
```

双方通过私密渠道取得同一个密钥文件，不把内容贴到日志或仓库。
此 TCP 原型具备认证/完整性，载荷不加密；最终 Internet 传输仍需完成上层实行书的验收。

## Windows 观察器构建/暂存

```powershell
.\coop\scripts\Build-Coop.ps1
```

脚本在 `coop/dist/ACZCoop-observer` 暂存 CLI、`ACZCoop.addon64`、默认配置及清单，
不修改游戏目录。需要 Windows MSVC x64 工具链；GNU/gnullvm 交叉工具链可用于另外的构建检查，构建脚本为这些目标启用 crt-static，
避免留下未随包提供的 libunwind.dll 依赖。

游戏内实验沿用现有 ReShade 6.8.0 full add-on 的 `dxgi.dll` 承载方式。
退出游戏后，将新增的 `ACZCoop.addon64` 和 `ACZCoop.ini` 放到已有 ReShade add-on 搜索目录；
可以与 `ACZRenderBridge.addon64` 并存，但并行游戏表现还需实测。
默认 `observer_hooks=false`：只校验构建、写诊断，不修改游戏代码。
显式改为 true 后才启用 4 个实验性原生只读观察入口，记录模式/世界代、线程、准备状态、
原生 Tick 候选、玩家绑定、姿态和 HP。所有游戏状态写入仍禁用。这里的只读指玩法状态；启用观测 Hook 会由 MinHook 修改入口指令。

每次启动产生 `ACZCoop-<PID>-<timestamp>.trace.jsonl`，包含本机构建与数据来源。
`adopted_at_update` 表示插件加载时错过了 enter，需要重新进入任务补齐生命周期验收。
状态 detail 错误类别：1 参数/布局，2 范围，3 阶段，4 权限，5 世代，6 重复，7 过期，
8 缺口，9 耗尽，10 关系冲突，11 线程，12 构建，13 不可读/不可用，14 尚不支持。

不支持运行中替换或热卸载。启用过的模块/trampoline 保持进程期有效；AddonUninit
停止采样，剩余 Detour 只转发原始函数，不释放可能仍被调用的代码。替换/卸载前退出游戏。
移走新增 add-on/配置后，下次启动恢复原有加载流程。

## 范围

原生 P2 资源/任务定义、实体释放复用、积分器、完整武器/脚本/存档写入均尚未闭环。
`require_capability` 对这些写操作明确拒绝；本轮没有偷偷改人数或复用剧情 NPC。
游戏内加载、M0 生命周期和 M1–M6 联机/通关测试均不因本地验收而自动通过。

# 模块与集成验收规范

每个模块的单元门槛见 MODULE_PLAN；执行结果逐个写 AUDIT_LOG。
测试必须包含正向和拒绝路径，并检验失败后的状态没有半提交。

统一命令（仓库根目录）：

```bash
cargo test --manifest-path coop/Cargo.toml --workspace --locked
cargo fmt --manifest-path coop/Cargo.toml --all -- --check
cargo clippy --manifest-path coop/Cargo.toml --workspace --all-targets --locked -- -D warnings
cargo run --manifest-path coop/Cargo.toml -p acz-coop-cli --locked -- demo
cargo run --manifest-path coop/Cargo.toml -p acz-coop-cli --locked -- doctor /path/to/acz.exe
```

Windows 编译和打包使用 `coop/scripts/Build-Coop.ps1`；Linux 能验证的目标检查与
实际 Windows DLL 链接分开记录，不声称 Linux native 测试覆盖 Win32 FFI。

## 跨模块验收

实际使用系统 loopback TCP；协商双方 EXE/内容/角色，双方就绪后接受 guest 输入。
分块快照须完整才提交，伤害去重，主机唯一结算，重试清空旧世代输入/事件/实体。
错误密钥、旧包、超前输入、篡改长度、快照缺块、重复/冲突事件均需要可观察拒绝。
模型世界只用于验证这些接口，不报告“游戏已双人通关”。

## 游戏内 M0（未执行即保留未执行）

验证 ReShade 同时加载原桥接和 ACZCoop；匹配哈希、4 个观测 Hook 安装、游戏仍硬件 D3D12。
至少记录菜单→战役加载→飞行→暂停→回放→结算→重试→返回；核对线程、世界世代、
ready、玩家数、Actor 绑定、坐标/HP 和原生 Tick 候选。离开后不得继续读取旧世界。
对比未安装观察器的帧耗时，不通过则关闭 Hook 并保留日志。

M1–M6 原生/网络/通关验收继续服从上层实行书，不会因本轮模块测试而自动通过。

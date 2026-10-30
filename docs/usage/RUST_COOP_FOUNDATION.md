# Rust 合作基础层的运行与阅读

这是九个已实现 crate 与只读观察器的用法。**它还不能让两位玩家进入战役合作。**
实际边界见 [验收记录](../mp/execution/VALIDATION.md)，公共入口和测试索引见
[API_MAP](../mp/execution/API_MAP.md)，完整配置/暂存说明见 [coop README](../../coop/README.md)。

## 只在 CLI 运行的部分

在仓库根目录执行；显式指定工具链，因为 `--manifest-path` 不会切换当前工作目录：

```bash
rustup toolchain install 1.99.1 --profile minimal --component rustfmt --component clippy
cargo +1.99.1 test --manifest-path coop/Cargo.toml --workspace --locked
cargo +1.99.1 run --manifest-path coop/Cargo.toml -p acz-coop-cli --locked -- demo
cargo +1.99.1 run --manifest-path coop/Cargo.toml -p acz-coop-cli --locked -- doctor /path/to/acz.exe
python coop/tools/verify_interfaces.py
python tools/ghidra/verify_coop_archive.py
```

`demo` 启动一个独立 guest 子进程，通过真实回环 TCP 完成：协商、双方 ready、输入、
21 个模型实体、乱序快照分块、伤害去重、结果、重试和旧世代拒绝。
两端四次检查状态摘要。成功输出必须保留 `scope=model`、`native_gameplay=false`，
以及重试后的 `epoch=2`、`entities_after_retry=0`、主机一次/客机零次存档许可。
存档许可只是模型权限对象，演练没有访问游戏存档。

`doctor` 核对完整 EXE SHA、PE/映像范围及四个候选入口的文件字节。
只有当前白名单构建可通过；成功不证明该构建已在游戏中接受 Hook。
没有游戏资源时，仍能完整运行协议、会话、复制、认证传输、模型演练及静态校验。

要试两个终端或两台机器，先按 coop README 生成私密密钥，再使用 `host-model/guest-model`。
这些命令同样只操作模型。认证 HMAC 不提供载荷保密，不能称为 TLS 或已完成公网方案。

## Windows 观察器

`coop/scripts/Build-Coop.ps1` 在 coop 目录中选择固定 Rust 工具链，运行 fmt、测试、clippy，
以静态 CRT 构建并暂存 add-on、CLI、默认配置、许可、锁文件和哈希清单。
它不修改游戏目录。CI 还执行 release CLI 的双进程演练，并检查真实 PE 导出/导入。

观察器继续使用已有成功的 ReShade 6.8.0 full add-on 加载机制。
默认 `observer_hooks=false` 只写构建诊断；显式开启后才安装四个实验性原生观察 Hook。
“只读”指不修改玩法状态，Hook 本身会修改机器入口指令。
原生写入、网络驱动游戏、P2 构造和任务/保存适配均未启用。

第一次游戏内验收先完成 [M0 清单](../mp/execution/ACCEPTANCE.md)：
核对来源、加载/退出、线程、模式/世界 generation、ready、玩家/Actor 绑定和原生 Tick 候选。
`adopted_at_update` 说明错过 enter，必须重新进入任务补齐证据。
本地 generation、网络 Epoch、原生 Tick 与 trace sample 是不同概念，不能互相代用。
trace 丢弃/IO 错误会使取证不完整，应保留该状态并重新取得足够样本。
模块与 trampoline 不支持热卸载，替换前先退出游戏。

## 本轮代码阅读与实施的具体教训

- 内存夹具和文档可能同源出错。实际初始化和重置指令共同证明 P+1FC0=W+240，
  因此观察器和旧文档一起修正；只让模型测试通过无法发现这个错误。
- `16E880/16F550` 读取第二参数 RDX，必须完整传回原始函数。
  ModeHolder 覆盖 AL 的指令又说明不能把外层返回值强加给 mode update。
- 传输模块必须自己确定 socket 工作方式，不能依赖不同 OS 的 accept 继承行为。
  Windows 原生双进程验收发现的问题，需要在 Linux 显式构造非阻塞 socket 才能回归覆盖。
- 文本换行、默认编码和编译器运行库都会影响发布。固定 LF/UTF-8，
  检查实际 PE 导入，再运行 Windows release CLI，比“链接成功”多验证了一层真实产物行为。
- 档案每次变更后重新冻结和校验；反编译、模型、Windows CLI、游戏 HIL 分别记录。
  构建与回环网络通过，仍不足以放行任何原生玩法写入。

# 最终验收记录

机器可读结果：[validation-summary.json](evidence/validation-summary.json)，
接口与 PE 记录：[interface-checks.json](evidence/interface-checks.json)。
本地记录与远端 Windows/Linux 结果分开保存：[remote-ci.json](evidence/remote-ci.json)。
这些记录属于基础实现验收，不是游戏内测试。

| 检查 | 实际结果 | 范围 |
| --- | --- | --- |
| Rust workspace 单元/集成 | **53 passed / 0 failed** | 包括真实双进程 TCP；不启动游戏 |
| fmt | PASS | 全 workspace |
| Windows checkout 字节 | PASS | core.autocrlf=true 下兼容 JSON 与归档文本保持 LF |
| clippy `-D warnings` | PASS | Linux / Windows gnullvm，均含 all-targets |
| 模块依赖与 unsafe 边界 | PASS | 9 个 crate，内部/外部依赖白名单，平台/裸指针不进入核心 |
| 协议与兼容清单 | PASS | Golden/截断/容量/噪声，兼容 SHA 与清单一致 |
| 模型会话与复制 | PASS | 就绪、输入、快照、伤害、结果、重试，4 次两端摘要一致 |
| 拒绝路径 | PASS | 错误密钥/MAC/帧、摘要差异、重复/旧世代、客机权限、队列溢出/超时 |
| 真实 EXE doctor | PASS | 3,803,248 字节，SizeOfImage=59,101,184；SHA/PE/4 个入口文件指纹 |
| 原生代码关联 | PASS（限定事实） | P+1FC0=W+240，选择器/stride，update RDX 与调用者覆盖 AL |
| Windows x64 DLL / CLI | **本地交叉链接通过** | gnullvm release，crt-static；未执行 Windows 产物 |
| ReShade DLL 导出/数据 | PASS | AddonInit、AddonUninit、NAME、DESCRIPTION，元数据为薄字符指针 |
| 产物依赖 | PASS | DLL 无 libunwind/libgcc/winpthread 额外运行库依赖；仅系统导入 |
| Windows MSVC / GitHub CI | **PASS：53/0** | 原生 fmt/test/clippy、静态 CRT release 构建、PE 检查、release CLI 双进程演练 |
| 原有 oracle / ReShade C++ 构建 | PASS | 独立既有 Windows workflow；没有改动其实现 |
| 游戏内注入/时序/性能 | **未执行** | 新 Rust add-on 仍需 M0 HIL |
| P2 战役/在线通关 | **未执行、未实现闭环** | N01–N05 / RE05–RE17 仍有资源与原生契约阻塞 |

## 与真实代码的联系

本轮没有只依赖自己编写的模型：

- 用真实 EXE 的完整 SHA、PE section 和候选指纹约束运行时。
- 对照原始机器指令复核 P+1FC0、玩家/Actor 选择器和生命周期参数。
- 另外导出 ModeHolder 的两个函数，确认 update 不能丢掉 RDX，返回值来自 holder。
- 在 Windows PE 内检查实际导出以及 NAME/DESCRIPTION 指针，不仅检查文件存在。
- 发现并消除了 GNU 构建的 libunwind.dll 外部依赖，避免产物到目标机缺 DLL。
- 实际 Windows MSVC 发布包也通过静态 CRT 和 PE 检查，未导入 VCRUNTIME/MSVCP/CONCRT。

模拟内存和模型世界仍然无法证明真实分配器、线程生命周期、积分器或任务脚本正确。
M0 必须记录真实菜单/加载/飞行/暂停/回放/结算/重试/退出；只有它通过后，才继续原生写入。

## 当前实现的明确缺口

尚未把资源不完整的第二玩家强行接到战役，也未提供原生武器/伤害/任务/保存修改。
原生写能力检查明确返回 Unsupported。TCP 原型未完成最终低延迟通道、保密传输、
Internet 穿透/中继或通关覆盖。它们是下个施工阶段，不以本轮 53 个测试替代。

## 复现

最终代码验收提交 `d27ce7f15c0673907468433b528ef837b4d751e7`：
[Linux / Windows CI](https://github.com/STanJK/AceCombatZeroReshade/actions/runs/41080932953)。
[Windows 观察器包](https://github.com/STanJK/AceCombatZeroReshade/actions/runs/41080932953/artifacts/12988768489)
为同一提交构建，ZIP SHA-256 为
`66b7ea2bcfb4637dbdc0d4915e327f6d2bf3253deb48192b18dd6bd8e437bce6`。
它是实验性观察器及模型 CLI，仍不是可玩的战役合作补丁；Actions 制品有保留期限，可用源码重建。
本节之后的文档收尾提交只增加验收/用法记录和归档，不改变经过上述 CI 的实现。

标准命令见 [ACCEPTANCE.md](ACCEPTANCE.md)。
交叉构建使用 Rust 1.99.1 / `x86_64-pc-windows-gnullvm`，LLVM-MinGW 20261020 msvcrt，
目标编译选项 `-C target-feature=+crt-static`。
第三方工具链来自其[官方发布](https://github.com/mstorsjo/llvm-mingw/releases/tag/20261020)，
下载包 SHA 在机器记录中保存并已核对。具体编译产物 SHA 随构建工具链/路径变化，
不应误当作游戏 EXE 白名单或跨编译器兼容标识。

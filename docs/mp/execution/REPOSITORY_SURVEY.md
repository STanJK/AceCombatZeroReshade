# 项目模块划分扫描

2026-10-30 通过当前 STanJK GitHub 连接列出 19 个拥有者为 STanJK 的可访问仓库，
按与本任务的相关性选择下列项目深入读取。没有将目录不存在解释成项目缺少模块。
没有复制其他项目的业务实现。私有项目仅提炼通用依赖方向，不包含其业务代码。

| 项目 | 读取内容（文件 blob SHA） | 可借鉴的边界 |
| --- | --- | --- |
| [Vibefactory](https://github.com/STanJK/Vibefactory) | `MODULE_MAP.md` `05a03ae65c216e8b68b56be778fa111eca3b2068`；AppHost `lib.rs` `99e8359ec6cd647a008a34e8e5ef0b070ea852d2` | 主进程装配、核心规则、投影和呈现分离；一份事实来源；版本契约显式管理 |
| [HalluCine](https://github.com/STanJK/HalluCine) | workspace `40c56eb278e3d26d69db79ce59cfd97fb7e367ed`；AppHost `app_host.rs` `d4862db94ef451404886e97794bbad1bd4eb22b4` | 可复用核心与 AppHost、GUI 为不同 crate；错误与 DTO 在边界处转换 |
| [rust-boundary-tool-box](https://github.com/STanJK/rust-boundary-tool-box) | manifest `62847933d227c3ef72967ed40eed3e8d336b7523`；入口 `b86b73e9be77862376f11f41570813690780788a` | app、core、平台适配分工，入口只启动；工作线程经消息通道连接 UI |
| [RA3MCP](https://github.com/STanJK/RA3MCP) | workspace `2cc6f941c9c7a156b24dad908ad73ea366c4315a`；controller `lib.rs` `0025a6cb7c57153014c0ac35f5e4fda70e2d45e4` | 原生采样与外部控制器分离；固定包编码、序列校验、故障后会话失效；Golden 与拒绝路径测试 |
| [ProjectRebound](https://github.com/STanJK/ProjectRebound) | README `b9db58b1e70567e1c73f6223c71dfb7a4417b21d` | 启动、配置、Hook 基础设施、Tick 逻辑、事件、复制、外部 API 分离；不把 DLL 入口写成业务中心 |

HalluCine/VF 的 GUI、ProjectRebound 的 UE 网络、RA3 的 WinMM/32 位 ASI 均不移植到 ACZ。
本项目提炼出的具体规则：纯类型/协议在底层，状态决策在 session/replication，
IO 在 transport/trace，内存与 Win32 在最外层，CLI/runtime 负责装配。
每个模块都提供不启动游戏即可运行的单元验收；游戏事实引用已有同构建证据。

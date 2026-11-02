# 新目标证据接点与代码联系

S=确切指令/读写事实，H=语义推断，D=拟定设计，O=缺少运行/语义证据。
全部地址为同 SHA EXE 的 RVA；ASLR 下加实际模块基址。完整函数在 exports.tar.gz 最新 decompiled 目录。

| 模块 | 静态证据与消费链 | 实施含义及限制 |
| --- | --- | --- |
| 场景/对象 | 0C6A50 初始化；0C80E0 分配场景槽；0CD880 绑定；16E4C0 arena freeMark | W/P 指针必须限定场景代次，不新建第二玩家 |
| 两视图 | W+67230 count；671F0/67210 camera；67234 owner；0D2580 按 owner 取 stride27A0 的 P | S：视图和玩家索引分离；D：两个 view owner=0；O：单玩家战役双视图实测 |
| 列表容量 | 201840 分配5个30字节组；0D2580 固定1/2/3/4，view及view+2 | 两个完整视图的结构证据；不证明四个完整 scene view |
| 相机数据 | 16E0B0 alloc1C0→004E80；1FBEC0→202C00/202C90/矩阵组合 | 数据路径可隔离；position+30、rotation input+40、view+50、projection+90/D0、组合+110/150 |
| 相机生产 | 106F30→107320→111D40；111D40 query+RNG | 禁止为第二视图重跑 native 玩家相机求解 |
| HUD 来源 | 108620 的108959/108967/108976将P+10B0、P+1868传给0AE510 | S：HUD不自动跟随传入scene Camera；需显式鼻向引用相机 |
| HUD 更新 | 1040C0→0B7B40；0B7B40 角度归一化/状态/RNG | 一份原生HUD推进；H浅拷贝不足以隔离其子资源 |
| HUD 显示 | 0AE510、0B05E0、0B30F0、0B3560；202ED0 齐次裁剪 | 状态共用；世界点/机体锚/二维布局分层理解；以nose层一次生产为候选 |
| 角色输入 | 201DC0→188A80/188180→187390；187A40 held、187C80 edge、187EC0 analog | analog return XMM0 float；网络帧冻结后按消费作用域查询 |
| 飞行 | 10F600 action11..18差值→flight+220..22C→12AA30 | P1；各轴方向和单位要校准，不直接按 action ID 猜滚转/俯仰 |
| 机炮 | 104646 action0D held；13ACE0；P+208E弹量递减 | P1；保持native冷却/接受判定 |
| 其他武器 | action0C 在1040C0/1031B0；141200路径 | P2；不通过远程线程直接调用发射/投射物构造 |
| 目标/相机复用 | action0E同时被111D40和1040C0消费；22写P+2094 | 单纯掩码不够；P2私有look与shared target分开，绝不共写CameraMode |
| HUD 包封口 | 0AE510返回末端→2011A0封口/链接 | 通用封口器非HUD专属；标记真实包及引用子段 |
| 包解释 | 18F920→19D160→196530→1961A0→193240 | 高层标签、packed register、GPU API三个层次不能混用 |
| 转换/裁剪 | 194840→1936B0→193CC0→20EEB0；20A000绑定target/viewport | 旧矩形有512/640/448特殊分支，输出x/y/w/h优先在合成层实现 |
| GPU/呈现 | 194840→20F8E0→20F680；20B9C0/20C280全帧 | 共享状态/延迟flush；每view不另present，资源fence后退役 |

## 与仓库现有实现的关系

`addon/ACZRenderBridge.cpp` 是项目已有可用 ReShade 接入参考；其 SceneClean 模式抓取 pre-HUD 场景。
它没有提供双 Camera 更新、双 scene pass、透明 HUD surface 或 P2 输入。不能将本轮计划描述成该文件已经实现的能力。
历史 deferred/TLS scope 失败记录位于 [RENDERER](../../RENDERER.md)，本轮按包/批次标签设计以避免重复该问题。

`coop/` 现有核心模块和 native read-only observer 保留。新目标可复用身份/包序列/角色权限/时钟等基础设施，
但已有 CLI 双进程模型不验证原生双视图，旧 wingman takeover 开关也不是本方案入口。
本轮未改 gameplay Rust 源码，也未伪造 native ABI 接口或宣称旧66个测试验证了新渲染目标。

新模块接口由 [IMPLEMENTATION_CONTRACT](../../../mp/cockpit/IMPLEMENTATION_CONTRACT.md) 定义，
每项仍须先取得对应 [运行验收](IMPLEMENTATION_GATES.md) 证据，再升级为可调用 native adapter。

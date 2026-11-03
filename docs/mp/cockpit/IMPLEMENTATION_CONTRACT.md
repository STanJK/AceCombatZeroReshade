# 新目标实施接点：单飞机、双视图、共享机头 HUD

V1 已按本合同定版，并完成 R6–R10 补证。最新接入条件以 [V1 定版与验收](v1/README.md) 为准。

这是五轮递归后的研究交付，替代“第二人类僚机”作为当前开发方向。历史方案继续保留供查证。
范围：主机一份游戏模拟；P1 飞行/机炮，P2 其他武器及独立观察；先本地双输入/双视图，再远程输入+视频。
当前 Rust read-only observer 不会因此变成可玩 patch。以下接口是 D（拟定），地址事实见各轮结果及逆向归档。

## 不变量与坐标约定

唯一 SimulationTick 生成 `(scene_epoch,tick_id,aircraft_id)`；所有 view/HUD 使用同一标识，杜绝混帧。
一个共享 WeaponState/TargetState/HudSemanticSnapshot；两台 ViewCamera 和一台 HudReferenceCamera。
HudReferenceCamera 姿态以机体/机头为基准，P1/P2 转头只更新各自 view。
首次样机将两 view 与 HUD reference 原点保持一致，只做独立旋转；这是旋转重投影成立的前提。
若沿用会移动位置的原生第三人称相机，或增加座位偏移，必须另做世界标记重投影，不能用单平面冒充准确视差。

HUD 的文字/弹药/锁定语义完全共用，显示坐标独立计算。机头图元随机体参考方向，视图转开后自然移出视野，
不在每个屏幕中央强制贴一份 HUD。世界目标标记仍属于世界点，二维面板属于布局层，不能混淆。
用户要求二者视觉统一时，可先用同原点 nose layer 的射线重投影；之后是否保留固定屏幕仪表需明确列为单独策略。
矩阵乘法约定、轴向、角度单位必须由 native 数值校准，网络协议不直接序列化推断为 quaternion 的 native+80 数据。

## 标准模块边界与单元验收

| 顺序/模块 | 输入 → 输出 | 原生接点/职责 | 单元/集成验收 |
| --- | --- | --- | --- |
| M0 SessionGuard | lifecycle observation → SceneLease/FrameKey | 原 SHA/ASLR、16E4C0 场景失效、设备代次；所有写入前验证 | 换关/重置后旧 lease 拒绝；禁用恢复原生，零悬空引用 |
| M1 RoleInput | 两角色序列帧 → TickInputSnapshot | 201DC0 后适当时点冻结；187A40/187C80/187EC0 作用域路由，0E 按消费者隔离 | 重复/乱序不多发；同 tick 多次 query 一致；超时中性；P2 不能飞行/开机炮 |
| M2 CameraRig | pose+两份 look+layout → ViewCamera[2],HudReference | 004E80/1FBEC0 数据路径；不重跑111D40/106F30 | 转 P2 不改 P1/P+2094；不增加 RNG 调用；投影/逆变换与 native 零偏移一致 |
| M3 ViewPass | FrameKey+Camera+target lease → SceneSurface[2] | 合法两个列表组；owner同P0；0D2580共享 scratch 串行 | 仅一世界更新；两个不同角度 scene；P1/P2无串 target/clear/depth |
| M4 HudLayer | 共享HUD+HudReference+packet tags → HudSurface/geometry | 一次0B7B40/0AE510生产；包/批次标签贯穿194840/20F8E0 flush | 弹药/锁定状态一致；独立相机下机头锚定；HUD生产计数不翻倍；不丢透明/世界标记 |
| M5 Compositor | 两scene+HUD+OutputLayout → LocalOutput | 最终像素布局可配置 x/y/w/h；隔离旧逻辑矩形单位；fence管理 | 调整第二视图不改FOV/模拟；resize安全；裁剪不越界；每帧一次native present |
| M6 RemoteIO（后续） | P2 command/video surfaces ↔ remote terminal | 输入入队、主机接受；视频编码和独立窗口/虚拟屏输出 | 延迟/断线可恢复；epoch隔离；无第二世界；远端仅得到授权输入权限 |

接口字段应使用显式值类型：`FrameKey { scene_epoch, device_epoch, tick_id }`、
`ViewId { Pilot, Wso }`、`PixelRect { x,y,width,height }`、`CameraPose { origin, orientation_convention }`、
`SurfaceLease { device_epoch, resource, state, ready_fence }`、`HudReference { frame_key, pose, projection, coverage }`。
原生 W/P 指针不越过 native adapter；其他模块只持不透明 lease/值快照。跨线程不得传借用的 Camera/HUD 指针。
InputFrame 中 tick/sequence 与游戏帧号不同，必须有接受/重采样策略，不能通过网络帧数推进模拟。

## 审计原则与接入次序

先 M0/M2 的只读相机数值实验，再 M3 双 scene，再 M4 HUD，之后 M1 实际分权和 M5 布局，最后 M6。
编号表示模块职责，接入顺序以风险依赖为准。每次只开放一个新模块并保存原生基线对照。

每接入一模块，核对：是否新增第二次 update/RNG、是否写越权状态、是否有 epoch 和 fence、
是否把 native单位误当屏幕像素、接口是否泄露裸指针、关闭功能后能否完全回到原生路径。
M3/M4 未实测前不开放武器写入，避免把画面和操控故障混成一个问题。

HUD RGBA 捕获、包语义传播、原生分支替换都仍需要实现与 Windows HIL；本合同不授予未知 ABI 直接调用资格。
完整放行条件见 [IMPLEMENTATION_GATES](../../reverse-engineering/coop/cockpit/IMPLEMENTATION_GATES.md)。

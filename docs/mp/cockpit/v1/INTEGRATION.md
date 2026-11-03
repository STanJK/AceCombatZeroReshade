# V1 接入与运行验收

本页在 R6–R10 结束后冻结原生接入的验收顺序。定版方案的本地双人、同眼点、单飞机和角色权限为交付范围。地址均按原始 SHA 加实际模块基址解释。

| 步骤 | 最小接入 | 通过所需证据 |
| --- | --- | --- |
| M0 只读活动跟踪 | 从 Holder 更新/绘制两个槽记录活动路径。观察 0CF865、0CF038、0CFF20 和 1FE9C0 的 parser/提交路径。场景 lease 在 leave 前撤销 | 固定任务正常/暂停/继续/重试/退出都能分辨。证实逻辑步、采样、render_frame_id、Present 的关系，resize 触发独立 device_epoch |
| M2 私有相机比对 | 只读采样原生 Camera，构建私有数据块。按行向量、V·P90/PD0 校验偏移与正前方。记录眼点、C50/C90/CD0/C110/C150 和实际矩形 | 对零偏移、机体运动、正负 yaw/pitch 的基线给出数值误差。用机体基准和活动相机独立对照，证明 P2 转头不影响 P1 |
| M3 双 scene | 使用 1/3、2/4 两组列表及独立 Camera/RT/DS。预留 0x4100 固定组开销和动态包预算，保证同一 arena 无嵌套写入。两份视图的延迟引用分别登记 | 按序解析两份 view，第二视图角度正确，P1 基线一致。一次原生模拟/Present，每项引用、目标与清屏可核查 |
| M4 HUD | 在已接纳的槽 0B 采集单次 0AE510 语义包，传递 traversal→primitive batch→draw 标签。输出有序 HudReferenceBatches，验证合成等价时可输出 HudReferenceSurface | 对照两种背景、深度状态和实际 blend。保持弹药/目标/HUD 状态一致。验证同眼点转头、机体转动、标记靠近边界、超出覆盖、临时目标及重建 |
| M1 角色输入 | 先开放动作 0D、0C，接入 02，再分批放行目标相关动作。冻结输入使用设备与角色代次，依照 R10 消费者白名单 | 交叉权限、短按、多次查询、长按、断开、失焦、暂停、重连、模式切换均通过。0E/26 的取消不能触发正常释放副作用 |
| M5 布局合成 | 合成阶段接收 PixelRect，SurfaceLease 由 device_epoch、queue、fence、resource_state 保护 | 可调 P2 位置/大小，resize 后无旧资源复用。两个视图和参考层同键，原生每帧 Present 一次 |

每步保存同任务原生对照与逐帧日志，包含 scene_epoch、device_epoch、tick_id、render_frame_id、input_sample_id、role_epoch、view_id、producer_callsite、arena_generation、batch_generation、target、fence。出现未知状态时停在该步骤，输出具体调用点和恢复过程。

第一批代码可先做 M0 只读诊断与 M2 数值适配，等完整游戏验证后再启用原生写入。M3/M4 的主要运行门槛分别是动态包上界和引用存活期、批次拆分及实际 HUD blend。M1 的主要运行门槛是 0E/26 的取消收尾。用户可用同一台机器完成这组本地验收。游戏画面与输入路径当前待验证。

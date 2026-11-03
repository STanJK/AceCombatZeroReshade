# R9 回写：HUD 包来源、批次边界和混合

本地导出 r9/r9b/r9c。固定原始 HUD 状态生产与渲染采集的职责。包、primitive batch 与 draw 使用同一帧键。

## 生产和引用

1040C0 内 105B8D 调 0B7B40。后者写 HUD+54/+58 等字段并有条件调用随机数。继续沿用原生状态生产次数。0D2580 的 0D35B7、0D3709 都可能进入 108620，原生 108620 还发座舱/覆盖层等其他包。采集范围选择具体 HUD 调用点：

- 1088C1 起检查 P+1BE4、33BD60、全局状态，打开组内槽 0x0B。108935 读取开始 cursor，108946 注册引用。108976 调 0AE510，RCX=P+1868、RDX=cursor、R8=P+10B0、R9=[P+2040]，保留栈上第 5 参数。10897B 取得 RAX=end，108981 调 2011A0。
- 0AE510 写入状态位、从 HUD+54/+58 生成带 ±0x300 限幅的偏移，并根据 C198/C19C 写 HUD 比例。它先经 203B30 发资源引用，再由 1FC350 写相机包，0BF810 发后续头部。若替换 R8 成机头参考相机，仍需审计原生偏移是否已包括自由观察，避免两次变换。
- M4 记录 `FrameKey, producer_callsite, arena_generation, pointer_table_generation, [begin,end), reference_pose`。使用引用边在 traversal 实例中继承语义，同时区分几何和资源/状态命令。不同父节点共享同一资源时，只在该 traversal 继承标签。重放输出使用一次生成的包/批次快照，保持原始生产者计数。

## 延迟批次的传递

18F920 的 jump/call/return 通过索引表解析子包。19D160 的 0x50/51 进入 196530，分流到 1961A0 或 191A00；0x14/17 进入 19CBF0。193240 调 192920，后者向 state+6F8 关联的顶点区域和 +700 索引区追加数据。state+708/+70C 记录累积数量。

193369、1933A5、1934B3 在状态变化时调用 194840 并重置批次。1964C4 是包终止位 0x8000 且有待提交顶点时的另一 flush。19CBF0 也会检查同一计数（相对外层对象 +720），再做 flush/重置。解析线程进入或离开 HUD 区间时，pending batch 可能仍然存在。标签要跟随追加的顶点/索引范围，flush 时读取对应的所有者。检测到混合所有者，须在合法 primitive/状态边界分批或判定本帧无法隔离。

194840 的 195464、195B4B，以及 195DC0 的转调，都可能送 20F8E0。前者含临时目标路径。20F8E0 内部又可多次进 20F680，后者在 20F89A/A8 走 command-list vtable +68/+60。单个 parse packet 或 194840 调用无法直接当作一个 draw。日志需同时保留 parser 节点、batch 代次、目标、draw 序号和资源引用。ReShade PSO 仅用来对齐观察结果。

## 透明层的实际前提

1936B0 消费 state+2D8/+2E0 等混合状态，经 193CC0 参与目标选择，再调 20EF50。20EF50 在 20F2D9–20F2FC 读取 16 字节表项，写 31E198（enable）、31E1A0（src）、31E1A4（dst）、31E1A8（op），20F3xx 另写 alpha 与写掩码。209D40 走 209BC0 选取或创建 PSO。以下是静态表的前三项，当前未证明它们全部出现在 HUD。

| 索引 | RGB src/dst/op | 对背景颜色 D 的效果 |
| --- | --- | --- |
| 0 | 5 / 6 / 1 | S·As + D·(1−As) |
| 1 | 5 / 2 / 1 | S·As + D |
| 2 | 9 / 1 / 1 | S·D |

数值按 Microsoft D3D12 的 [Blend](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_blend) 和 [BlendOp](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_blend_op) 解释。若实际 HUD draw 含第 2 类按通道乘背景，普通一张 RGBA 的标量 alpha 无法表示任意 S。写掩码、深度/模板、采样数、颜色空间和临时目标也要保持。已有 SceneClean 记录只能定位背景及 GPU 边界。

M4 的权威中间表示采用 `HudReferenceBatches`，包含一次产包后按序保留的几何、投影、引用、混合和深度状态。HIL 先以两种背景和同视角做像素对照，确认 batch 覆盖和混合一致。证明可等价压成预乘透明层时可输出 `HudReferenceSurface`；否则保留按视图投影和合成有序批次的路径。若某 draw 不能在相同资源语义下隔离，M4 阶段停止并记录该 draw，不推断透明层完成。此决定保留 V1 的一次 HUD 生产、两路显示语义。

R10 按相同 FrameKey 和 R6 的活动消费者作用域，收口操控分权。G3/G4 仍需完整游戏的视觉和 draw 轨迹验证。

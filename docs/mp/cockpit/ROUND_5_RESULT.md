# R5 结果与最终回写：包解释器、裁剪与提交边界

完成 r5 与 r5b..r5g 定点追踪；每批日志、根列表和导出均留档。r5b 额外候选 196D00 位于其他函数体内，
导出器明确报 NO_FUNCTION，没有据此建立或命名新函数；其余有效根全部反编译成功。未运行游戏。

## Camera 包不是现代 viewport API（S）

1FC350 发出 C0 字节，含 40/41（矩形端点）、18/19（以 16 为单位的中心偏移）、47/48、4C..4F 等 legacy register 写入。
18F920 遍历带长度/跳转/调用/返回标签的列表；19D160 对 50/51 段调 196530。
196530→1961A0 解包 packed register 数据，1961A0→193240 写寄存器状态。
193240 先应用 `state+3E0+reg*8` 掩码，再写 `state+C8+reg*8`；遇到某些状态改变会先 flush 194840。
**这些 40/41 不是 19D160 顶层 opcode，也不是 D3D12 RSSetViewports 调用。**

1936B0/193CC0 读取对应两套寄存器状态并形成绘制派生数据。193CC0 从 state+2C8/+2D0
取矩形（对应 reg40/41），从 +328/+330 等取缓冲描述，处理 native 512/640/448 及现代目标尺寸的特殊缩放，
写 33BC60 开始的两组转换值、state+73C/740/744 等；末尾调 20EEB0。
这说明变更 legacy Camera 矩形仍会受转换规则影响，不能将它直接填成桌面像素。

20EEB0 是已闭合的实际 scissor setter：缓存四个端点，前两项非负时调 commandList vtable+B0。
20A000 绑定目标并用该目标尺寸设置 vtable+A8 viewport、+B0 scissor；-1 分支使用 swapchain 全局尺寸。
20ABE0 的一次性目标转换/全屏三角形分支也会覆盖 viewport/scissor，不是每视图通用 setter。
按 Microsoft DirectX-Headers 的 ID3D12GraphicsCommandListVtbl 顺序复核：A8=RSSetViewports、
B0=RSSetScissorRects、170=OMSetRenderTargets。来源 URL、header SHA 与抽取结果见归档 d3d12-methods.json。
API 参数参考：[RSSetViewports](https://learn.microsoft.com/en-us/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-rssetviewports)。

**D：首个样机保留合法 native 双列表/逻辑矩形路径，画面分别进入有明确所有权的 scene targets；
用户配置的位置/宽高先由最终合成层实现。**任意原生分屏比例可另行扩展，但须同时校准寄存器转换、裁剪和投影。
目标创建/转换函数的副作用很多，20E000/20E490 是目标栈相关路径，不作为稳定公共接口直接暴露给 Rust。

## HUD 区域必须随包传播（S + 旧运行记录）

0D2580 的 108620→0AE510 生成 HUD 包，2011A0 接收返回指针并封口链接，写 20000000 标签。
2011A0 是通用列表封口器，**不是 HUD 独有 GPU pass 结束点**。应在 0AE510 调用处记录 begin/end、frame/view/epoch，
而不是给每次 2011A0 都贴 HUD 标签。18F920 的链接/跳转还要求追踪引用子段，不能假定整段内存连续覆盖所有子调用。

194840 会因状态改变提交已有 primitive batch；20F8E0 构造上传和实际绘制路径；20F680 绑定 root 参数后 draw。
几何/状态可能先缓存再消费，当前 CPU 返回地址不等于 GPU draw 的语义范围。
项目已有 [RENDERER 历史记录](../../reverse-engineering/RENDERER.md) 的 TLS scope 校准失败，
本轮静态链路与该历史相符；没有重跑并重新宣称验证过该实验。
已有 SceneClean 在首 HUD PSO 前抓场景，不提供透明 HUD 层；SceneClean 与最终画面的差不能唯一还原正确 alpha。

D：在命令包/primitive batch 数据上携带 HudReference 标签，在 flush/上传时维持批次归属与边界；
隔离出正确 RGBA pass 后再做两视图显示变换。若混合语义 batch 无法拆分，不能仅靠 PSO hash 识别就宣布 HUD 完整分离。
中间透明层还须处理混合模式、MSAA resolve、深度、色彩空间及视场外 HUD；窄 FOV 生成后再旋转会缺边，必须留角度余量。

## 单帧和生命周期契约（S/D）

- native 一次输入/任务/玩家/武器/AI 更新；Hud producer 0B7B40 和原生相机求解 111D40 各最多一次。
- 在既定渲染时点读共享 pose/HUD；私有 Camera 以 1C0 对齐布局生成并重算矩阵；不得并行调用共享 scratch 的 0D2580 分支。
- 两个 scene view 和一个 nose HUD reference 是渲染资源，不额外创建 native player/Actor。
  若临时替换相机指针，作用域必须完整覆盖对应包生产并无异常残留；此做法仍未 runtime 放行。
- 20B9C0/20C280 为全帧 begin/end 路径，后者提交列表、present、更新缓冲索引并等待 fence；不能每视图执行一次。
  20E000 还可能清屏，不能直接在两视图之间重放而不检查清屏范围。
- 16E4C0 按 arena mark 释放场景内存；外部持有的 W/P/Camera/HUD 指针必须以 scene_epoch 失效。
  GPU 资源按 device_epoch 与 fence 退役；CPU 场景释放并不等于 GPU 已消费完包。
- 播片、菜单、关键事件、加载、设备重建时关闭双视图替换和远程 held/edge，恢复原生路径。
  “关键事件”全部判据尚未枚举，不可仅凭 in_mission 布尔值放行。

## 五轮结论回写

静态研究足以设计一个按阶段验收的双视图样机：P0 单飞机、两私有相机、一份语义 HUD、按消费者分权输入。
没有证明“改 view_count=2 就可玩”，也没有完成透明 HUD layer、显示窗口、编码或网络输入 hook。
必须先通过 [最小实验及未闭合项](../../reverse-engineering/coop/cockpit/IMPLEMENTATION_GATES.md)，
再将调用点升级为运行时接口。最新模块契约见 [IMPLEMENTATION_CONTRACT](IMPLEMENTATION_CONTRACT.md)。

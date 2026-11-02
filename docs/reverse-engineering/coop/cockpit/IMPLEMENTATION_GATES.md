# 静态已闭合项、运行未知项和最小验证

五轮已找到足以开始分模块样机的主要接点。以下是具体未闭合项，不把“静态能连通”写成实际画面成功。

| 门槛 | 当前结论 | 最小闭合方法 |
| --- | --- | --- |
| G0 两个视图/一个玩家 | S：count/owner/list分离；D：view_count2、两个owner0 | 在完整游戏同关卡记录player_count1、Actor/飞行积分/武器更新计数均未增加；两合法列表组均有效 |
| G1 每view共享scratch | S：0D2580读写共享场景区；不是纯函数 | 单线程逐view产包；记录scratch/target绑定、粒子/环境/座舱有无第二次更新；违规立即恢复原路径 |
| G2 姿态/矩阵数值 | S：字段/矩阵生产链；O：轴向、单位、乘法约定完整数值契约 | 原生零偏移画面/投影基线，分别只改一个角度；对同世界点比较裁剪和屏幕坐标，不能凭“看起来对”通过 |
| G3 HUD参考空间 | S：硬编码P+10B0、图元混合空间；D：nose reference一次生产 | 固定机体姿态只转P2；HUD机头锚不跟屏幕中央，弹药/锁定完全一致；同原点时世界标记仍在目标射线上 |
| G4 HUD透明层与完整性 | O：未实现RGBA pass/批次语义传播，PSO只是历史锚点 | 真实包标签覆盖所有子段，明确flush边界；记录无场景/座舱混入、无漏widget、正确alpha/MSAA/色彩空间；转头视场边缘不缺内容 |
| G5 输入语义/时点 | S：held/edge/analog ABI、0D/0C；O：完整用户动作名称、0E复用拆分 | 帧级原生query日志与实体状态对应；P1/P2权限反向输入各10次；一次按下只发一次，持续机炮不被edge替代 |
| G6 生命周期/事件 | S：arena清理、GPU fence；O：所有关键事件判据 | 加载、重试、任务结束、播片、暂停、设备resize各测试；旧epoch拒绝、资源退役、安全恢复原生路径 |
| G7 布局/输出 | S：legacy转现代矩形路径；D：合成层PixelRect | 同屏双画面任意矩形不串clear/depth；改变布局不影响投影/飞行；独立窗口、虚拟屏/视频各是后续独立输出适配 |

## 实验顺序与记录格式

1. 只读基线：同一存档/任务/飞机，记原SHA、构建、窗口尺寸、native camera mode、tick/帧计数和原生调用数。
2. 相机数值：私有Camera与native同姿态，生成一致矩阵；不增加任何native输入、HUD/RNG生产调用。
3. 双scene：保持player_count1，两view都owner0；P1静止look，P2逐轴转；同一tick只有一份飞机/弹药/任务结果。
4. HUD：先nose零偏移，再独立转头；机头锚随机体而不随观察方向，世界目标投影按数学验证；记录语义HUD更新次数。
5. 输入：P1飞行/机炮、P2其余武器；交叉越权必须无效；重复/乱序/断线包不重复发射、不留下held。
6. 布局与退出：改变第二视图x/y/w/h，resize/换关/重试/播片；native present每帧一次；关闭功能可恢复基线。
7. 本地全部通过后，再接P2远程输入和独立视频输出；不引入第二份战役模拟。

每条记录至少包含 `build_sha, exe_sha256, scene_epoch, device_epoch, tick_id, view_id, native_update_counts,
input_sequence, camera_pose, hud_reference, target/fence_id, result`，附关键帧和日志。
避免只交一张分屏截图：它不能证明HUD锚定、单次模拟或武器权限正确。

这里的 Windows/完整资产 HIL 是运行验收条件，不是要求现在连接 Toolhub；当前仍禁止 Toolhub，已完成部分全部来自本地静态工具。

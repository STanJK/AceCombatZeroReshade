# 原战役僚机本地双人：当前代码与取证操作

2026-10-31，`mp` 分支。**当前仍不能用 P2 驾驶战役僚机，也没有开启战役分屏。**
新增模块在真实游戏进程内核验原 Actor/helper、双机选择结果、事件和相机列表；本流程未接网络。
研究与差距见 [三轮记录](../mp/wingman/REVERSE_PLAN.md)、
[模块实行书](../mp/execution/WINGMAN_LOCAL.md)、[审计](../mp/execution/WINGMAN_AUDIT.md)。

## 构建和配置

Windows 安装 Rust 1.99.1、Visual Studio C++ Build Tools、Python 后，在仓库根目录运行：

```powershell
.\coop\scripts\Build-Coop.ps1
```

产物在 `coop/dist/ACZCoop-observer/`，或从本分支对应提交的 GitHub Actions 下载
`ACZCoop-read-only-observer-Windows-x64`。旧提交的包不支持新选项。
沿用已成功的 ReShade API20 add-on 注入链：full add-on ReShade 的 `dxgi.dll` 加载
`ACZCoop.addon64`。安装/回退细节见 [demo 第 7–8 节](COOP_DEMO.zh-CN.md)。

退出游戏后复制新 add-on，编辑 **add-on 同目录**的 `ACZCoop.ini`：

```ini
observer_hooks=true
wingman_probe=true
```

默认均为 false。单独设 wingman_probe=true 会被拒绝，不隐式启用 Hook。
只读指不写玩法状态；启用 observer 仍由 MinHook 修改四个原生入口。
不支持热卸载，换 DLL 前退出游戏。

## 一台机器的取证步骤

只需一个游戏进程；当前没有双人控制可操作，也不需要第二个 EXE 或模型网络端。

1. 进入有原僚机的战役任务，记录任务、角色、机型和开始时间。
2. 普通 Gameplay 持续数秒，依次转向、开火、切换目标，记录动作时间。
3. 经过可复现的播片/关键事件，暂停/恢复、重试，退出任务再重新进入。
4. 分别保存无僚机任务、Pixy/PJ 不同阶段和原生 VS 的记录。VS 仅作绑定/视图对照。
5. 退出游戏，收集 add-on 同目录 `ACZCoop-<PID>-<timestamp>.trace.jsonl`。

队列拥堵时会丢记录，不阻塞游戏；关注 trace_end 的 dropped。
丢帧数据能提供对象线索，不能证明每帧 AI 排他和完整事件时序。

## 新记录怎么读

既有 pre_update 保留。新增 `wingman_post_update` 在原生 update 返回后读取，
与同次 pre_update 共用 generation/sample，不增加 pre_update 计数。
如果 update 内已经 leave，post 端不会自动重认旧指针。

| 字段 | 含义 |
| --- | --- |
| campaign / player_count / player_selectors | 模式、现有原生玩家数和 group/actor 选择器 |
| helper_count / candidates | group0 后续 Actor 与 helper 的候选对应，不自动认定剧情角色 |
| helper_bound / model_bound | +1C0 与 helper、+360 与 helper+18 所存对象是否对应 |
| human_slot / foreign_human_link | +1B8 是否指向现有玩家槽，或是陌生地址 |
| event | controller、flags、索引、byte 子状态及间接 kind；缺失不伪造 Gameplay |
| selection | active profile 两槽完整 DWORD 机型/配装/选项和限界后的颜色 |
| views | owner、两组相机地址、是否匹配对应玩家内嵌相机 |
| native_takeover_ready / blockers | 当前实现的缺口；本版本 ready 保持 false |

PowerShell 查看最近记录：

```powershell
$trace = Get-ChildItem .\ACZCoop-*.trace.jsonl | Sort-Object LastWriteTime -Descending | Select-Object -First 1
Get-Content $trace.FullName | ForEach-Object { $_ | ConvertFrom-Json } |
  Where-Object type -eq 'wingman_post_update' | Select-Object -First 3 |
  ConvertTo-Json -Depth 12
```

未修改战役预期为一个玩家、候选 Actor 有 helper 而 human_slot=null、一个视图；
原生 VS 预期 P2 在 group1/actor0，区别于目标中的原剧情 group0 僚机。
这是待核对的预期，不是本环境新增的实机结论。

`wingman_probe_rejected` 的 detail 沿用旧错误编号：2 边界、5 世代变化、10 关系冲突、13 不可读。
取证主动限界 8 个 helper、255 个 Actor、4 个视图，不是游戏容量结论。
不应为了消除拒绝而关闭校验。

仍需完成第二玩家原生资源事务、actor1 人类路径和自主写者适配、关键事件交接，
以及 VS 选择→战役资源→两视图/HUD 的接入。单元测试和交叉编译不能替代这些工作，
当前没有可直接开启合作的启动命令。

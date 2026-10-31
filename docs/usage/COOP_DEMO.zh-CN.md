# ACZ 合作原型 demo：当前能力、单机双进程、双机与游戏观察

更新日期：2026-10-31。面向 Windows / PowerShell，另附 Linux CLI 命令。
适用分支：`mp`。本文对应现有命令，没有假设尚未实现的游戏联机入口。

最新新增原僚机取证与 wingman_probe，见 [本地僚机方向操作](WINGMAN_LOCAL.zh-CN.md)。
尚未开启 P2 控制或战役分屏；本文的双进程模型操作继续有效。

首次建议按第 2→3→4 节运行；需要跨机器再看第 5 节；有完整游戏安装后按第 7→8 节做 M0。

## 1. 先回答三个问题

**现在可以在一台电脑上跑两个独立 CLI 进程，验证模型状态同步。不需要先准备第二台电脑。**
`demo` 自动启动 guest；`host-model` / `guest-model` 可以分别放在两个终端运行。

**游戏接入目前是实验性只读观察器。** 它与模型 CLI 是两条独立路径；CLI 不会自动附加到
正在运行的 `acz.exe`，也不会把收到的网络状态写进游戏。

**两个真正的游戏实例联机、战役 P2、合作通关尚未实现。** 同一台电脑启动两个 `acz.exe`
的兼容性也没有验证；目前没有可照抄后就得到双人战役的启动命令。

| 场景 | 机器 / 进程 | 当前状态 | 能证明什么 |
| --- | --- | --- | --- |
| 自动模型 demo | 1 台，2 个 CLI 进程 | 已实现；Linux / Windows CI 通过 | 真实 TCP、认证、消息/状态契约与重试 |
| 手动模型 demo | 1 台，两个终端各 1 个 CLI | 已实现；按第 4 节运行 | host / guest 独立启动、固定端口、共享密钥 |
| 局域网模型 demo | 2 台，各 1 个 CLI | 已有直连命令；实体双机验收待实际运行 | 跨主机地址、网络路径和防火墙；仍是模型 |
| EXE doctor | 1 台，1 个 CLI | 已对原始白名单 EXE 运行通过 | 文件 SHA、PE、四个候选入口文件字节 |
| 游戏只读观察 M0 | 1 台，1 个游戏实例加载 add-on | DLL / 配置已实现；游戏内验收未执行 | 生命周期、线程、玩家绑定和原生 Tick 候选 |
| 单进程战役双玩家 M1 | 1 台，1 个游戏实例、两个玩家 | 尚未实现 | 需要先闭环战役资源、构造、输入和清理 |
| 双游戏进程在线合作 | 同机 2 个或双机各 1 个游戏实例 | 尚未接通；同机双开也未验证 | 不能以当前模型 PASS 代替 |

原版分屏 VS 的两个玩家共用一个游戏世界。它提供双玩家机制的研究对照，不能证明存在原生跨机同步。
本项目的 protocol / session / replication / transport 是新增补丁基础。

## 2. 准备可执行文件

下面 A、B 任选一种。只跑模型不用安装游戏、ReShade，也不用手柄或第二张显卡。
CLI 无 GUI；输入和任务是内置的固定验收脚本，不接收实时飞行操作。

### A. 下载已经通过 Windows CI 的包

打开 [通过验收的 Actions run](https://github.com/STanJK/AceCombatZeroReshade/actions/runs/41080932953)，
在 Artifacts 下载 `ACZCoop-read-only-observer-Windows-x64`，也可使用
[直接制品入口](https://github.com/STanJK/AceCombatZeroReshade/actions/runs/41080932953/artifacts/12988768489)。
GitHub 可能要求登录；制品有保留期限，到期后按 B 从源码构建。

该包来源提交：`d27ce7f15c0673907468433b528ef837b4d751e7`。下载的原始 ZIP SHA-256：

```text
66b7ea2bcfb4637dbdc0d4915e327f6d2bf3253deb48192b18dd6bd8e437bce6
```

PowerShell 核对下载文件（如文件被浏览器改名，替换实际名称）：

```powershell
$Archive = Join-Path $env:USERPROFILE 'Downloads\ACZCoop-read-only-observer-Windows-x64.zip'
Get-FileHash -LiteralPath $Archive -Algorithm SHA256
```

核对后，将其中这些文件解压到自己的 demo 目录，例如 `C:\STanJK\Development\ACZCoopDemo`：

```text
acz-coop.exe
ACZCoop.addon64
ACZCoop.ini
README.md
THIRD_PARTY_NOTICES.txt
Cargo.lock
manifest.json
```

`manifest.json` 保存包内文件哈希。此包使用静态 CRT，PE 验收未发现包外 VC/GNU 编译器运行库依赖。
运行模型只需调用 `acz-coop.exe`，不需要将 add-on 放进游戏。

### B. 从 mp 分支构建

需要 Git、Rustup，以及 Windows x64 MSVC / C++ Build Tools 和 Windows SDK。
已有开发环境可以继续使用；安装说明见 [Rust 官方入口](https://rust-lang.org/learn/get-started/)
和 [MSVC 前置工具说明](https://rust-lang.github.io/rustup/devel/installation/windows-msvc.html)。

新建 checkout：

```powershell
git clone --branch mp https://github.com/STanJK/AceCombatZeroReshade.git
Set-Location .\AceCombatZeroReshade
```

已有 checkout 则在仓库内执行 `git fetch origin`、`git switch mp`、`git pull --ff-only origin mp`。
若存在未提交改动或分支分叉，先按自己的开发流程处理，勿为运行 demo 丢弃改动。

完整 Windows 暂存包：

```powershell
rustup toolchain install 1.99.1 --profile minimal --component rustfmt --component clippy
.\coop\scripts\Build-Coop.ps1
```

脚本实际执行 fmt、workspace 测试、clippy、静态 CRT release 构建，然后暂存到：

```text
<仓库>\coop\dist\ACZCoop-observer\
```

它不安装到游戏目录。只要 CLI 时，也可在仓库根目录单独编译：

```powershell
cargo +1.99.1 build --manifest-path coop/Cargo.toml -p acz-coop-cli --release --locked
```

这条命令的输出通常是 `<仓库>\coop\target\release\acz-coop.exe`，不是上述暂存目录。
若自行配置了 `CARGO_TARGET_DIR` 或编译 target，按 Cargo 实际输出位置取文件。

后续命令都在包含 `acz-coop.exe` 的目录执行，例如：

```powershell
Set-Location 'C:\STanJK\Development\ACZCoopDemo'
.\acz-coop.exe --help
```

## 3. 最短路径：自动单机双进程

```powershell
.\acz-coop.exe demo
$LASTEXITCODE
```

正常会很快完成并自动退出，退出码为 `0`。核心输出如下（字段顺序不是验收条件）：

```json
{"result":"PASS","scope":"model","transport":"authenticated_tcp","native_gameplay":false,"epoch":2,"entities_after_retry":0,"host_save_permits":1,"guest_save_permits":0,"digest_checks":4,"input_duplicate_rejected":true,"damage_duplicate_rejected":true,"old_epoch_rejected":true}
```

它实际做了这些事：

1. 当前进程作为 host，在 `127.0.0.1` 的系统分配端口监听。
2. 创建临时随机密钥文件，启动同一个 EXE 的独立 `guest-model` 子进程。
3. 双向认证并协商模型中的构建/补丁/内容标识；双方 ready 后开始。
4. guest 发送固定输入及其重复样本，验证只生成一次按下边沿。
5. host 创建 21 个模型实体，逆序发送两个完整快照分块，guest 收齐才应用。
6. 发送一次伤害及重复事件；结果维持 HP=75、主机总分=100。
7. 发送成功结果；主机取得一次保存许可，客机被拒绝。没有写入任何游戏存档。
8. 重试到 Epoch 2，清空实体和输入，拒绝旧世代事件/快照。
9. 四次比较两端世界 SHA、事件游标与快照游标；进程退出并清理临时密钥。

这是两个 OS 进程通过实际系统 TCP 交换数据，不是仅在一个进程里模拟收发。
内容 SHA、任务和难度是模型常量；没有加载真实任务资源，也没有运行飞行积分器。
该 demo 没有持续飞行画面、交互大厅、玩家移动窗口或实时网络仪表。

保存输出（Windows PowerShell / PowerShell 7 均可）：

```powershell
.\acz-coop.exe demo 2>&1 | Tee-Object -FilePath .\auto-demo.log
$DemoExit = $LASTEXITCODE
"exit=$DemoExit"
if ($DemoExit -ne 0) { throw 'Model demo failed; inspect auto-demo.log' }
```

自动 demo 使用 loopback 和临时端口，不需要专门为它增加局域网入站规则。

## 4. 手动单机双进程：两个终端

### 4.1 生成一次共享密钥

在 demo 目录运行一次：

```powershell
.\acz-coop.exe keygen .\session.key
$LASTEXITCODE
```

成功返回 `0`。`create_new` 不覆盖已有密钥；若 `session.key` 已存在，继续使用该文件，
或明确换一个新文件名，并让两端都引用同一个文件。不要把密钥提交进 Git 或贴进日志。

### 4.2 终端 A：启动 host

```powershell
Set-Location 'C:\STanJK\Development\ACZCoopDemo'
.\acz-coop.exe host-model 127.0.0.1:48123 .\session.key
$LASTEXITCODE
```

先看到 `MODEL host listening on 127.0.0.1:48123`，然后等待连接，这是正常状态。
host 在 accept 前可等待；连接建立后，握手和每次交换有 5 秒总截止时间。

### 4.3 终端 B：启动 guest

```powershell
Set-Location 'C:\STanJK\Development\ACZCoopDemo'
.\acz-coop.exe guest-model 127.0.0.1:48123 .\session.key
$LASTEXITCODE
```

guest 成功输出：

```json
{"result":"PASS","scope":"guest-model","native_gameplay":false}
```

host 输出第 3 节完整模型报告，两端退出码均为 `0`。
双方连接后脚本自动执行到结束，不需要在两个终端手动发送输入，也不要在运行中暂停进程。

每次 host 只服务这一次连接/场景，然后退出。再试一次，先重新启动 host，再运行 guest。
`Ctrl+C` 可中止正在等待的手动 host；它不属于正常 PASS 结果。
各终端可按第 3 节方式分别用 `Tee-Object` 保存输出并立即记录 `$LASTEXITCODE`。

**不要在 host 等待时先用 `Test-NetConnection -Port 48123`、`nc -z` 等做 TCP 探测，
再直接连接 guest。** 探测也会占用它唯一一次 accept，导致认证失败并退出。
若已经探测过，重新启动 host。只读查看本机监听可用：

```powershell
Get-NetTCPConnection -LocalPort 48123 -State Listen
```

## 5. 双机局域网模型 demo

此节需要两台电脑，目的是追加验证真实 LAN 路径；完成前四节不需要它。
现有 Windows / Linux CI 验证的是 loopback，不把本节步骤写成已经完成的实体双机实验。

1. 两端使用同一制品或同一源码提交构建的 CLI。
2. 通过私密渠道把同一个 `session.key` 文件复制到两端；不要各生成一份不同的密钥。
3. 查看 host 的局域网 IPv4（例如运行 `ipconfig`）。以下假设它为 `192.168.1.50`，实际操作必须替换。
4. guest 先准备好命令；host 启动后再连接。

host A：

```powershell
Set-Location 'C:\STanJK\Development\ACZCoopDemo'
.\acz-coop.exe host-model 0.0.0.0:48123 .\session.key
$LASTEXITCODE
```

guest B：

```powershell
Set-Location 'C:\STanJK\Development\ACZCoopDemo'
.\acz-coop.exe guest-model 192.168.1.50:48123 .\session.key
$LASTEXITCODE
```

guest 使用 host 的真实地址，不使用 `0.0.0.0` 或 `127.0.0.1`。
当前参数由 `SocketAddr` 解析，示例应填写数字 IP 加端口，不要填 HTTP URL 或主机名。
两端结果和第 4 节一致；LAN PASS 仍然只证明模型，不证明两个游戏在同步。

### 需要时添加一条临时 host 入站规则

若防火墙阻止连接，在 host 的管理员 PowerShell 中，针对可信的 Private 局域网添加：

```powershell
$CliPath = (Resolve-Path 'C:\STanJK\Development\ACZCoopDemo\acz-coop.exe').Path
New-NetFirewallRule -Name 'ACZCoop-ModelDemo-TCP-48123' `
  -DisplayName 'ACZCoop model demo TCP 48123' `
  -Direction Inbound -Action Allow -Program $CliPath `
  -Protocol TCP -LocalPort 48123 -Profile Private -RemoteAddress LocalSubnet
```

规则路径必须与实际 EXE 一致。用 `Get-NetConnectionProfile` 确认当前网络类别；Private 规则不会
匹配 Public / Domain 网络。按实际可信网络及现有管理策略设置，不必关闭整个防火墙。
该 demo 使用 TCP，不需要额外开放 UDP。规则依据见
[Microsoft New-NetFirewallRule 文档](https://learn.microsoft.com/en-us/powershell/module/netsecurity/new-netfirewallrule)。

试验结束后删除本次规则：

```powershell
Remove-NetFirewallRule -Name 'ACZCoop-ModelDemo-TCP-48123'
```

公网穿透、中继、丢包/抖动容忍和保密传输尚未完成。当前 HMAC 提供认证/完整性，载荷没有加密。

## 6. 两个可复现的拒绝实验

### 错误密钥

host 用原 `session.key` 重新启动；在 guest 终端生成不同密钥并连接：

```powershell
.\acz-coop.exe keygen .\wrong-session.key
.\acz-coop.exe guest-model 127.0.0.1:48123 .\wrong-session.key
$LASTEXITCODE
```

预期认证失败，两端非零退出，不得出现完整模型 PASS。具体 OS 错误文字可能不同。
若 `wrong-session.key` 已存在，复用它并跳过 keygen；它必须不同于 host 的 `session.key`。
恢复时两端重新启动并使用正确共享密钥，失效的连接不能继续使用。

### 错误版本 / 错误 EXE

先对自己要观察的游戏文件运行第 7 节 doctor。完整 SHA 不匹配即拒绝。
不要通过更改白名单或关闭指纹校验让它“通过”；需要为新构建重新取得地址和原生证据。
这项检查不需要启动游戏，也不会写入 EXE。

## 7. 单机检查真实 EXE

将示例游戏目录替换成实际目录：

```powershell
$GameDir = 'D:\Games\ACZero'
Get-FileHash -LiteralPath (Join-Path $GameDir 'acz.exe') -Algorithm SHA256
.\acz-coop.exe doctor (Join-Path $GameDir 'acz.exe')
$LASTEXITCODE
```

当前唯一白名单 SHA-256：

```text
43814d4b3292efd0a07fd71bef2f1670c0e5ac7cf2595c9e136d78451380a664
```

该文件为 3,803,248 字节；doctor 成功输出：

```json
{"result":"PASS","scope":"static-build-check","bytes":3803248,"image_size":59101184,"observer_candidates":4,"native_writes":false,"gameplay_executed":false}
```

`scope=static-build-check` 仅说明文件/布局/候选指纹通过；不说明 DLL 已加载到游戏，
也不说明四个入口在运行中满足线程与生命周期契约。

## 8. 游戏内只读观察 M0：一台电脑、一个游戏进程

这部分是尚未完成的实机取证步骤。先完成上面的模型 demo 与 doctor，再开始实验。
无需运行 host-model / guest-model；目前 runtime 没有连接网络模块。

### 8.1 准备和默认关闭 Hook 的加载检查

先确认既有 ReShade 6.8.0 full add-on / API 20 加载流程正常，保留原来的 `dxgi.dll`、
`ACZRenderBridge.addon64` 和效果配置。下例按仓库既有 `D:\Games\ACZero` 根目录搜索 add-on；
若你的 ReShade 配置指定了别的 add-on 搜索目录，以实际目录为准。

完全退出游戏，然后在含暂存包的目录执行：

```powershell
$GameDir = 'D:\Games\ACZero'
$AddonDir = $GameDir
$NewAddon = Join-Path $AddonDir 'ACZCoop.addon64'
$NewConfig = Join-Path $AddonDir 'ACZCoop.ini'
if ((Test-Path -LiteralPath $NewAddon) -or (Test-Path -LiteralPath $NewConfig)) {
    throw 'ACZCoop files already exist; inspect and back them up before replacement.'
}
Copy-Item -LiteralPath .\ACZCoop.addon64 -Destination $NewAddon
Set-Content -LiteralPath $NewConfig -Value 'observer_hooks=false' -Encoding ascii
```

按原来的方式启动游戏。ReShade add-on 名称应为 `ACZ Coop`；新插件与现有桥接并行行为尚待实测。
插件成功校验 host 时，会在 **ACZCoop.addon64 所在目录**创建：

```text
ACZCoop-<PID>-<timestamp>.trace.jsonl
```

配置 false 的正常记录包括 provenance、`boot`、`observer_disabled`、`trace_end`。
它只证明注册/文件校验/日志路径，不会出现 `hooks_ready` 或 `pre_update`。
构建不匹配可能只有 ReShade 日志中的拒绝信息，不保证创建 trace 文件。

### 8.2 启用实验性只读 Hook

先退出游戏，再改配置：

```powershell
Set-Content -LiteralPath $NewConfig -Value 'observer_hooks=true' -Encoding ascii
```

该命令生成解析器可读取的 ASCII 配置；不依赖 PowerShell 的默认文本编码。
重新启动游戏。这里的“只读”指不修改玩法状态；MinHook 仍会修改四个机器入口指令。
不支持运行中替换或热卸载 add-on，配置变化也要重启才生效。

按顺序操作并记录动作时间：

1. 主菜单进入一场普通战役，完成加载。
2. 正常飞行，做几次明确操纵；若方便则开火、受伤，观察数据变化。
3. 暂停/恢复；在游戏提供回放时观察回放。
4. 正常任务结算或返回菜单，再重新进入 / 重试任务。
5. 退出游戏，保存本次 trace 和 ReShade 日志。

这些是待观察场景，不要求所有菜单必然产生同一套事件顺序。
退出/清理之前应出现可解释的世界失效记录；后台线程在进程终止时的尾部落盘仍需实测，
不能只用有没有 `trace_end` 判断完整生命周期是否通过。

### 8.3 如何看 trace

退出游戏后选择最新文件：

```powershell
$Trace = Get-ChildItem -LiteralPath $AddonDir -Filter 'ACZCoop-*.trace.jsonl' |
  Sort-Object LastWriteTime -Descending | Select-Object -First 1
if ($null -eq $Trace) { throw 'No ACZCoop trace found; inspect the ReShade log.' }
$Trace.FullName
$Records = Get-Content -LiteralPath $Trace.FullName |
  Where-Object { -not [string]::IsNullOrWhiteSpace($_) } |
  ForEach-Object { $_ | ConvertFrom-Json }
$Records | Where-Object { $_.type -eq 'status' } | Format-Table code, detail
$Records | Where-Object { $_.type -eq 'pre_update' } |
  Select-Object -First 12 generation, sample, thread, ready, native_tick,
    @{Name='player_count'; Expression={ @($_.players).Count }}
```

| 记录 / 字段 | 意义与判读 |
| --- | --- |
| provenance | EXE build、日志 schema、插件版本、read_only 来源标记 |
| `hooks_ready`, detail=4 | 四个观察入口安装成功；还需要后续实机状态证明 |
| `world_entered` / `world_left` | 世界登记 / 原生清理前失效；核对返回、重试和再进入 |
| `adopted_at_update` | add-on 错过 enter，在 update 处收养对象；重新进入任务补齐 enter/leave 证据 |
| `pre_update` | 原生 update 之前的样本；包含本地 generation、线程、ready、绑定、坐标和 HP |
| ready=false | 可能仍在初始化；此时玩家列表为空、native_tick 为空是预期保护行为 |
| generation / sample / native_tick | 世界代、观察样本序号、原生 Tick 候选；均不等于网络 Epoch 或渲染帧率 |
| `*_rejected`, detail | 契约拒绝；保留日志，不能把拒绝改成强行解引用 |
| trace_end | accepted / dropped / closed 统计；dropped>0 或日志截断表示证据有缺口 |

detail 错误类别：1 参数/布局，2 范围，3 阶段，4 权限，5 世代，6 重复，7 过期，
8 缺口，9 耗尽，10 关系冲突，11 线程，12 构建，13 不可读/不可用，14 尚不支持。
若 JSON 最后一行因异常退出不完整，保留原文件并单独注明，不把解析错误当作全部日志不存在。

### 8.4 结束观察实验

完全退出游戏，保留日志后移走本次新增的 `ACZCoop.addon64`、`ACZCoop.ini` 即可恢复原有加载内容。
观察模块 / trampoline 按进程期保留，运行中不能靠删除文件安全卸载。

## 9. 常见现象与处理

| 现象 | 优先检查 |
| --- | --- |
| host 一直停在 listening | 它正在等待唯一连接；启动 guest，并核对地址与端口 |
| guest connection refused | host 未运行、地址/端口错误，或 host 已被前一次探测消费并退出 |
| timeout / exchange deadline | LAN 路径、防火墙、进程是否被暂停；失败后重启两端 |
| authentication failed | 两端是否为同一份密钥；错误密钥实验预期失败 |
| address parse / invalid arguments | 使用 `IP:port`；当前没有 `--join`、`--coop`、HTTP 地址或主机名解析入口 |
| key file already exists | keygen 不覆盖；复用现有文件或生成新的独立文件名 |
| 端口占用 | 查看监听进程或两端一致更换端口；只需调整手动 demo，自动 demo 端口由系统分配 |
| 模型 PASS，但游戏没变化 | 当前预期；模型 CLI 不附加游戏，原生游戏写能力未接通 |
| doctor BuildMismatch | 文件不在当前白名单；不要跳过校验 |
| false 配置没有 pre_update | 预期：只写默认诊断；开启实验 Hook 并重启后再观察 |
| 没有 trace / 初始化失败 | ReShade 是否为 full add-on 版本、add-on 搜索目录、EXE SHA、配置、目录写权限及 ReShade 日志 |
| loaded code 指纹被拒绝 | 保留完整 ReShade/插件与补丁清单；其他补丁可能修改同一入口，不自动绕过 |

## 10. 应保存的 demo 结果

每次记录场景（自动 / 同机手动 / LAN / 原生 M0）、来源提交或制品 manifest、OS、双方输出和退出码。
LAN 追加双方地址/端口与连接方式；M0 追加实际 EXE SHA、动作顺序、trace 和 ReShade 日志。
日志中不用附带密钥；保存许可字段不表示真的写盘。

验收分层：

- 模型通过：两端 PASS/退出码 0，四次摘要一致，重复/旧世代拒绝，重试后清空。
- LAN 通过：同样场景在两台真实机器间完成；不扩大为公网或游戏通过。
- M0 通过：真实运行的生命周期、线程、绑定、离开后禁读、行为/性能均有证据。
- 可玩合作通过：还需要本地战役 P2、原生复制、武器/任务/存档、跨机和路线验收；当前未完成。

本次文档复核（2026-10-31）在 Linux release CLI 实际复跑了自动双进程、手动双进程、
重复 keygen 拒绝、错误密钥拒绝，以及 TCP 探测消费唯一 accept；结果均符合上文，见
[demo-guide-checks.json](../mp/execution/evidence/demo-guide-checks.json)。
本次未执行实体双机、Windows PowerShell 安装命令或游戏 M0；此前 Windows CI 的构建、
测试和 release 自动 demo 证据单独保留，不能扩写为这些场景已通过。

既有结果：[VALIDATION](../mp/execution/VALIDATION.md)、[Windows/Linux CI 原始记录](../mp/execution/evidence/remote-ci.json)。
后续模块与放行标准：[NATIVE_MODULE_PLAN](../mp/execution/NATIVE_MODULE_PLAN.md)。

## 11. Linux CLI 对照

在仓库根目录：

```bash
cargo +1.99.1 build --manifest-path coop/Cargo.toml -p acz-coop-cli --release --locked
./coop/target/release/acz-coop demo
./coop/target/release/acz-coop keygen /tmp/acz-demo-session.key
```

两个终端分别运行：

```bash
./coop/target/release/acz-coop host-model 127.0.0.1:48123 /tmp/acz-demo-session.key
```

```bash
./coop/target/release/acz-coop guest-model 127.0.0.1:48123 /tmp/acz-demo-session.key
```

运行后用 `echo $?` 查看对应退出码，结束后移除自己创建的临时密钥。
以上仍是模型，Linux CLI 不加载 Windows ReShade DLL。

## 12. 源码对应位置

| 文档操作 | 实现 |
| --- | --- |
| 命令、地址解析、5 秒交换期限 | [cli main.rs](../../coop/crates/cli/src/main.rs) |
| 自动子进程、21 个实体、四次摘要、重试场景 | [cli lib.rs](../../coop/crates/cli/src/lib.rs) |
| 私密密钥文件、认证、TCP framing、失效连接 | [transport](../../coop/crates/transport/src/lib.rs) |
| Win64 加载、配置所在目录、日志路径、四个 Hook | [runtime Win64](../../coop/crates/runtime/src/windows.rs) |
| JSONL 字段与状态枚举 | [trace](../../coop/crates/trace/src/lib.rs) |
| Windows 暂存、静态 CRT、包内 manifest | [Build-Coop.ps1](../../coop/scripts/Build-Coop.ps1) |

本文是操作文档，不增加新的 CLI 参数、原生写能力或游戏双开功能。

# 施工前：规范与实际代码关联审计

基线 `7507e5f`；依据为本仓库历史、原生导出和生产桥接，不把上下文中的推断直接升级为事实。

| 设计契约 | 实际依据 | 审计结论 |
| --- | --- | --- |
| 使用 ReShade add-on 加载 | `addon/ACZRenderBridge.cpp` 的 register_addon / DllMain；根 README 的生产布局 | 已有游戏内成功历史；新 Rust add-on 本身仍需验收 |
| 不复用 WinMM/XInput 作为合作入口 | `docs/reverse-engineering/HISTORY.md` §3；`src/lib.rs` 仅转发两项 XInput 导出并有校准线程 | 历史性能/输入问题明确；保留其 SHA 校验思路，不复用业务钩子 |
| 核心不依赖 GPU Tick | HISTORY §5 的 CPU scope/GPU draw 错位；`on_present` 仅渲染时钟 | 渲染加载成功不证明模拟边界 |
| update 必须保留第二参数 | `14016e880.asm` 入口 `MOV RDI,RDX`，退出路径经 holder vfunc+20 tail jump；VS `16F550` 同类 | Rust 类型必须是二参数，不能按单 this 指针写 trampoline |
| 生命周期对象源 | `16E0B0` 分配 mode+8 world；`16E4C0` 清理；mode+18 初始化 ready | observer 从 enter/leave 跟踪，而非轮询可能悬空的世界全局 |
| 玩家/Actor 是不同结构 | `0C6A50`、`0CBCC0`、`PLAYER_STATE.md` | 玩家 stride 27A0，Actor stride 520；通过选择器和反向链接验证 |
| 快照不能直接抄内存 | `1B9400`、`13D140/141200/13ACE0`；回放记录含资源指针 | 无指针网络 DTO；原生 orientation 未证明前不转换成四元数 |
| 不允许复制即重复伤害 | `118040`、`117A10` | 伤害有归属、分数、随机、递归副作用；guest 不自行裁决 |
| 任务/存档不伪实现 | `0D1780`、`16E4C0`、GameEnd roots，RE12/RE17 尚未闭环 | 模型测试只验证协议/权限；原生写适配保留阻塞 |

## 对新代码的逐模块复核

实现后每行关联到实际 crate、公开函数、测试名与提交，记入 AUDIT_LOG。
所有观测 Hook 候选先从 `docs/mp/HOOK_CANDIDATES.json` 生成构建清单，运行时比较
确切文件 SHA、PE 架构、映像范围和入口指纹。32 字节指纹不作为覆盖长度。

## 历史上下文的证据层级

查到的旧上下文提过 version.dll 中间尝试；当前仓库没有把它记录为最终生产路径，
所以本轮不以它为加载依据。ACZ 的最终成功证据是 ReShade/ACZRenderBridge。
RA3 的 WinMM 双目录记录属于另一游戏，不适用于 ACZ。

## 施工中发现并修正：P+1FC0

`0CBCC0.asm` 的 `1400CBE0D LEA R12,[RBP+240]` 与
`1400CC77D MOV [RSI+1FC0],R12` 证明该字段为 W+240。
`0CD880.asm` 的 `1400CE067/1400CE30D` 再次给出独立重置写入。
原 PLAYER_STATE 的 World pointer 行已修正；观察器与测试夹具同时修正，
新增拒绝旧错误布局的回归验收。模拟测试通过本身无法发现夹具同源错误，
因此每个原生校验都必须回看实际指令。

## update 调用者和返回值复核

补充 [ModeHolder 2010D0 指令](evidence/native-dispatch/1402010d0.asm)：
入口复制 RDX=RCX(holder)，加载当前 mode，调用 mode vfunc+20，然后写 AL=1。
因此 frame driver 的 AL 判定来自 holder 返回值；模式 update 本身无需返回布尔值。
两个原始参数仍必须完整保留。补充导出单独归档，不修改先前 255 函数语料的统计口径。

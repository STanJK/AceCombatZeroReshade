# 共享座舱 V1 定版与补充逆向

定版方案先冻结了单机、单飞机、双观察者的范围及验收，随后在同一份 ACZ PE 上补做 R6–R10。每轮先写计划，再执行本地 Ghidra 12.2 / JDK 25.0.5 导出，依据结果写回下一轮及原生接口。[定版方案](SPEC.md) · [初版索引](../../../reverse-engineering/coop/cockpit/README.md)

| 轮次 | 计划 | 回写 | 给 V1 的结论 |
| --- | --- | --- | --- |
| R6 | [计划](ROUND_6_PLAN.md) | [结果](ROUND_6_RESULT.md) | mode 重读、活动/暂停分支、输入/模拟/呈现各自计数 |
| R7 | [计划](ROUND_7_PLAN.md) | [结果](ROUND_7_RESULT.md) | 相机存储、乘法、角度、裁剪以及同眼点重投影 |
| R8 | [计划](ROUND_8_PLAN.md) | [结果](ROUND_8_RESULT.md) | 两视图共用命令 arena，容量预留与链接租约 |
| R9 | [计划](ROUND_9_PLAN.md) | [结果](ROUND_9_RESULT.md) | 一次 HUD 生产、带来源批次和透明合成适用范围 |
| R10 | [计划](ROUND_10_PLAN.md) | [结果](ROUND_10_RESULT.md) | 按消费者分权，区分取消与短按释放 |

原生接口、放行条件及运行检查按模块收录。证据归档包含各批导出、日志、矩阵样例、入口字节与校验命令。[接入与运行验收](INTEGRATION.md) · [本次证据归档](../../../reverse-engineering/coop/cockpit/v1/README.md)

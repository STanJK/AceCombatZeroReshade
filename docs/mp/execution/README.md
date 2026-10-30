# Rust 模块化施工入口

基线：`mp@7507e5f`。本轮按“先规范 → 对照真实代码 → 单模块实现/验收 → 跨模块审计”执行。
总目标仍为 [双人在线战役合作](../COOP_PATCH_IMPLEMENTATION.zh-CN.md)。

阅读顺序：

1. [项目结构扫描](REPOSITORY_SURVEY.md)
2. [注入与加载决策](INJECTION.md)
3. [模块执行书](MODULE_PLAN.md)
4. [标准接口](INTERFACES.md)
5. [实际代码关联审计](SOURCE_AUDIT.md)
6. [验收规范](ACCEPTANCE.md)
7. [逐模块审计日志](AUDIT_LOG.md)

实现放在独立 `coop/` Cargo workspace。现有根目录的 XInput oracle 保留为研究工具。
所有结果按“本地单元/集成验收”“Windows 编译”“游戏实测”分别记录。
内存模型、回环网络测试都不能替代游戏战役验收。

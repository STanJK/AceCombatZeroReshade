# 注入与加载决策

已核对个人上下文以及仓库 HISTORY/README/ACZRenderBridge.cpp。
ACZ 最终验证路径为游戏目录 `dxgi.dll`（ReShade 6.8.0 full add-on）加载 `.addon64`。
生产 SceneClean 使用纯 GPU 识别；本轮另建 `ACZCoop.addon64`，继续通过 ReShade 加载，
避免引入另一个系统 DLL 代理。

旧 WinMM oracle 有严重性能/WARP-like 回退，XInput oracle 会干扰手柄。
这些是历史失败/研究路径，不能因为都能加载 DLL 就当作等价方案。

## Rust add-on 的边界

ReShade v6.8.0 `include/reshade.hpp` 明确提供 API 20 的 `ReShadeRegisterAddon`，
并允许在 AddonInit 或 DllMain 注册。`source/addon_manager.cpp` 在 LoadLibraryEx 返回后调用 AddonInit，卸载时调用 AddonUninit。
本轮用这对入口初始化/停采样，避免把重初始化放进 DllMain。
以固定版本官方头/loader 源码核对导出 ABI，
Rust 仅绑定需要的少数函数；不把 C++ SDK 对象布局搬入网络核心。

加载与游戏观察是两个验收点：

1. ReShade 成功登记 Rust add-on、构建诊断可读。
2. 可选原生观测启用后，校验版本/指纹、安装本模块拥有的 Hook，保留全部原始参数和原始调用。
3. enter/update/leave 事件只能只读采样并投递有界遥测。不得在网络线程调原生函数。
4. 不安装任何图形 vtable Hook；不覆盖旧 SceneClean 桥接。
5. 不支持运行中替换 DLL。观测模块和 trampoline 保持进程期有效，替换前退出游戏。

## 尚未验证

此设计沿用已验证的承载机制，但新的 Rust DLL、回调/Hook、退出和并行 add-on 行为
仍需 Windows 游戏内日志。Linux 的编译、PE 导出检查或模拟内存测试不算游戏注入成功。
安装包只暂存到构建输出，不自动修改用户游戏目录。

官方依据：[API 20 头文件](https://github.com/crosire/reshade/blob/v6.8.0/include/reshade.hpp)、
[加载器](https://github.com/crosire/reshade/blob/v6.8.0/source/addon_manager.cpp)。

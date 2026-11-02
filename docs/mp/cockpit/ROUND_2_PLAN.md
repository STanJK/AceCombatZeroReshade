# R2 计划：相机对象、机头姿态与投影

依据 R1，第二视图拟共享 owner=0，使用独立 1C0 Camera 数据块；保持一个 PlayerContext。
本轮验证其字段、调用存储和空间转换，尚不启用 native 写入。

根：004E80、005090、005380、1FBEC0、1FC350、202C00、202C90、005940、
106F30、107320、1580C0、0C4660。

问题：

- Camera 的 pose、view/projection/组合矩阵、viewport/scissor 字段分别在哪里？
- 机体朝向和自由观察朝向由哪些函数产生；是否能在 Camera 更新前独立组合？
- viewport 的原生整数单位与缩放/偏移字段如何关联，是否存在 angle-limit 与 FOV 混用？
- HUD 后续投影应使用哪套矩阵；机头参考方向与世界目标方向怎样分别投影？

输出字段表与 exact instruction 证据；避免直接调用推断参数很多的 202C90，
优先评估已确认单 Camera 指针的初始化/更新包装。根据 HUD 投影消费者新增 R3 根。

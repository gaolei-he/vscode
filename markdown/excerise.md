Bresenham算法中的误差判别项（也称为决策参数）是一个整数值，用于确定在扫描线上选择哪个像素来绘制。该值可以通过将理论扫描线位置与当前像素位置进行比较来计算。

具体而言，假设当前像素位于坐标 $(x, y)$，直线的下一个预期像素位于 $(x+1, y)$。则用斜率 $k$ 表示直线的方向，则直线与扫描线交点的理论 $y$ 坐标为 $y+k$。误差判别项 $d$ 可以通过计算实际像素 $P(x, y)$ 与理论交点 $(x+1, y+k)$ 的距离来确定。如果距离小于 0.5，则选择当前像素，否则选择下一个像素。

具体计算方式如下：

计算斜率 $k=(y_1-y_0)/(x_1-x_0)$。

初始化误差判别项 $d=2\Delta y-\Delta x$，其中 $\Delta x=x_1-x_0$，$\Delta y=y_1-y_0$。

从左往右沿直线绘制像素。在处理每个像素时，将其绘制并根据误差判别项确定下一个像素的位置：

如果 $d<0$，则选择当前像素并将误差判别项加上 $2\Delta y$。
否则，选择下一个像素并将误差判别项加上 $2(\Delta y-\Delta x)$。
重复上述步骤直到达到直线终点。
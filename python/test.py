import matplotlib.pyplot as plt
import numpy as np

def draw_regular_polygon(num_sides, k):
    # 生成角度
    angles = np.linspace(0, 2 * np.pi, num_sides + 1)

    # 生成顶点坐标
    x = np.cos(angles)
    y = np.sin(angles)

    # 绘制多边形
    plt.figure()
    plt.plot(x, y, 'bo-')  # 'bo-'表示蓝色圆点和线条
    for i in range(num_sides):
        tx, ty = [], []
        tx.append(x[i])
        tx.append(x[(i + k) % num_sides])
        ty.append(y[i])
        ty.append(y[(i + k) % num_sides])
        plt.plot(tx, ty, 'r-')
    plt.fill(x, y, alpha=0.2)  # 填充多边形，透明度为0.2
    plt.gca().set_aspect('equal')  # 确保x和y轴的比例相同
    plt.title(f'Regular Polygon with {num_sides} Sides')
    plt.show()

# 调用函数绘制一个正五边形
draw_regular_polygon(20, 9)

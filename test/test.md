背景介绍：[雪花曲线](https://zh.wikipedia.org/wiki/%E7%A7%91%E8%B5%AB%E6%9B%B2%E7%B7%9A)

代码实现：[何高磊](https://github.com/gaolei-he)

```python
# 用Python在本地跑
import turtle


def snow(n, size):
    if n == 0:
        turtle.fd(size)
        return
    for angle in [0, 60, -120, 60]:
        turtle.left(angle)
        snow(n - 1, size / 3)


# 输入n表示雪花曲线级数
# 设为[1,4]即可，数值太大效果不好
n = 3

turtle.setup(1920, 1080)
turtle.speed(1000)
turtle.penup()
turtle.goto(-300, 300)
turtle.pendown()
turtle.pensize(1)

for angle in [0, 120, 120]:
    turtle.right(angle)
    snow(n, 600)

turtle.done()
```

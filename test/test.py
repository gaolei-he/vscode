class Circle:
    def __init__(self, x, y, r):
        self.x = x
        self.y = y
        self.r = r

def create_circles(n, r):
    circles = []
    side = int(n**0.5)
    for i in range(side):
        for j in range(side):
            x = 2 * r * i + r
            y = 2 * r * j + r
            circle = Circle(x, y, r)
            circles.append(circle)
    return circles

n = 4  # 奇数个圆，且为完全平方数
r = 1  # 半径为整数
circles = create_circles(n, r)
for circle in circles:
    print(circle.x, circle.y, circle.r)
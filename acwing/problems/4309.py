from sys import stderr
from math import gcd
n, x0, y0 = map(int, input().split())
ans1, ans2 = set(), set()
for _ in range(n):
    x, y = map(int, input().split())
    x -= x0
    y -= y0
    if x < 0 and y < 0:
        x = -x
        y = -y
        t = gcd(x, y)
        ans1.add((x // t, y // t))
    elif x > 0 and y > 0:
        t = gcd(x, y)
        ans1.add((x // t, y // t))
    elif x > 0 and y < 0:
        y = -y
        t = gcd(x,y)
        ans2.add((x//t, y//t))
    elif x < 0 and y > 0:
        x = -x
        t = gcd(x, y)
        ans2.add((x//t, y//t))
    elif x == 0:
        ans1.add((0, 1))
    elif y == 0:
        ans2.add((1, 0))
# print(ans1, file=stderr)
# print(ans2, file=stderr)
print(len(ans1)+len(ans2))
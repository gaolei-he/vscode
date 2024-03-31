from math import sqrt, ceil, floor
def f(xa, ya,xb, yb,xc, yc, x):
    return sqrt(ya * ya + (xa - x) * (xa - x)) + sqrt(yb * yb + (xb - x) * (xb - x)) + sqrt(yc * yc + (xc - x) * (xc - x))

for _ in range(int(input())):
    l, r = map(int, input().split())
    xa, ya, xb, yb, xc, yc = map(int, input().split())
    def check(x):
        return f(xa, ya, xb, yb, xc, yc, x) > f(xa, ya, xb, yb, xc, yc, x + 1)
    while l < r:
        mid = (l + r) // 2
        if check(mid):
            l = mid + 1
        else:
            r = mid
    print(round(f(xa, ya, xb, yb, xc, yc, l), 1))
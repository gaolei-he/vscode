from math import log2
from math import fabs
x, y = map(int, input().split())
if x > y:
    x, y = y, x
eps = 1e-4
if y * log2(x) - x * log2(y) > eps:
    print(x)
elif fabs(y * log2(x) - x * log2(y)) < eps:
    print(x)
else:
    print(y)
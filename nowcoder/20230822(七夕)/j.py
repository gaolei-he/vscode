from math import ceil
f1, f2, f3 = map(int, input().split())
if f2 >= f1:
    print(1)
elif f2 <= f3:
    print(-1)
else:
    f1 -= f2
    print(ceil(f1 / (f2 - f3)))
from math import gcd
for _ in range(int(input())):
    x, y, z = map(int, input().split())
    if z % gcd(x, y) == 0 and z != 0:
        print('YES')
    elif z == 0 and (x == 0 or y == 0):
        print('YES')
    else:
        print('NO')
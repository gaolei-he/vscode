from math import sin
for _ in range(int(input())):
    n, R = map(int, input().split())
    ans = n * R * R * sin(2 * 3.1415926535 / n) / 2
    print(ans)

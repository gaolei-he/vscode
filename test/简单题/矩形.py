n, d = map(int, input().split())
k = int(input())
k1, k2 = -1, -1
k3 = -1 / k1
k4 = k3
b1 = d
b2 = 2*n-d
b3 = d
b4 = -d * k4

for _ in range(k):
    x, y = map(int, input().split())
    if y >= x * k1 + b1 and y <= x * k2 + b2 and y >= x * k4 + b4 and y <= x * k3 + b3:
        print('YES')
    else:
        print('NO')

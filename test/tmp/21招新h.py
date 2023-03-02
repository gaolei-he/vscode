from cmath import sqrt
from math import ceil

p = [i for i in range(1010)]

def find(x):
    if p[x] != x:
        p[x] = find(p[x])
    return p[x]

n = int(input())
point = []
for i in range(n):
    x, y, v = map(int, input().split())
    point.append([x, y, v])
seq = []
for i in range(n - 1):
    for j in range(i+1, n):
        dis = 0
        if (point[i][2] + point[j][2]) == 0:
            dis = 1e9
        else:
            dis = sqrt(pow(point[i][0] - point[j][0], 2) + pow(point[i][1] - point[j][1], 2)).real / (point[i][2] + point[j][2])
        seq.append([i, j, dis])

seq.sort(key=lambda x:x[2])
cnt = 0
ans = [0 for i in range(1010)]
for i in seq:
    if find(i[0]) == find(i[1]):
        continue
    p[find(i[0])] = find(i[1])
    tmp = ceil(i[2])
    for j in range(cnt, min(tmp, 1005)):
        ans[j] = n
    n -= 1
    cnt = tmp
for i in range(cnt, 1005):
    ans[i] = 1
q = int(input())
for i in range(q):
    t = int(input())
    print(ans[t])

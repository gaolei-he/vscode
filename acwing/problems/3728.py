# TLE
n = int(input())
a = [tuple(map(int, input().split())) for _ in range(n)]
c = list(map(int, input().split()))
k = list(map(int, input().split()))
pq = []
for i in range(len(a)):
    for j in range(i+1, len(a)):
        dis = abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1])
        pq.append((dis * (k[i] + k[j]), i+1, j+1))
        # pq.append((dis * (k[i] + k[j]), j+1, i+1))
for i, v in enumerate(c):
    pq.append((c[i], 0, i+1))
    # pq.append((c[i], i+1, 0))
pq.sort()
p = [i for i in range(n+1)]
def find(x:int)->int:
    if x != p[x]:
        p[x] = find(p[x])
    return p[x]
ans = 0
g = [[] for _ in range(n+1)]
for t in pq:
    x, y = t[1], t[2]
    a, b = find(x), find(y)
    if a != b:
        p[a] = b
        ans += t[0]
        g[x].append(y)
print(ans)
print(len(g[0]))
for i, v in enumerate(g[0]):
    print(v, end=' ' if i != len(g[0]) - 1 else '\n')
print(sum(len(i) for i in g) - len(g[0]))
for i, v in enumerate(g):
    if i == 0:
        continue
    for j in v:
        print(i, j)

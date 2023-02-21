n, m = map(int, input().split())
p = [i for i in range(n+1)]
def find(x:int)->int:
    if p[x] != x:
        p[x] = find(p[x])
    return p[x]
for i in range(m):
    a, b = map(int, input().split())
    p[find(a)] = find(b)
q = int(input())
for i in range(q):
    a, b = map(int, input().split())
    if find(a) != find(b):
        print('No')
    else:
        print('Yes')
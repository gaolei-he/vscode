n, m = map(int, input().split())
g = [[] for _ in range(max(n, m)+1)]
for i in range(n):
    g[i+1] = list(map(int, input().split()))[1:]
ans = 0
match = [0 for i in range(m + 1)]
sta = [False for i in range(m + 1)]
def find(x:int)->bool:
    for v in g[x]:
        if not sta[v]:
            sta[v] = True
            if match[v] == 0 or find(match[v]):
                match[v] = x
                return True
    return False
for i in range(n):
    sta = [False for i in range(m + 1)]
    if find(i + 1):
        ans += 1
print(ans)
n, m = map(int, input().split())
g = [[] for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    g[a].append(b)
    g[b].append(a)
st = [False for _ in range(n+1)]
a, ans1, ans2 = 0, 0, 0
def dfs(e, cnt, op):
    global a, ans1, ans2
    for v in g[e]:
        if len(g[v]) == 1:
            if op == 0 and ans1 < cnt:
                ans1, a = cnt, v
            elif op == 1 and ans2 < cnt:
                ans2 = cnt
        elif len(g[v]) > 1 and st[v] == False :
            st[v] = True
            dfs(v, cnt+1, op)
            st[v] = False

st[1] = True
dfs(1, 1, 0)
st[1], st[a] = False, True
dfs(a, 1, 1)
print(ans2)
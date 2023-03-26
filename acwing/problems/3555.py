for _ in range(int(input())):
    n, m = map(int, input().split())
    g = [[] for i in range(n+1)]
    for i in range(1, n+1):
        a, b = map(int, input().split())
        if a != -1:
            g[i].append(a)
            g[a].append(i)
        if b != -1:
            g[i].append(b)
            g[b].append(i)
    x, y = 0, 0
    ans = -1
    sta = [False for i in range(n+1)]
    def dfs(ver, dis):
        global ans
        if ver == y:
            ans = dis
            return
        for v in g[ver]:
            if sta[v] == False:
                sta[v] = True
                dfs(v, dis+1)
    for __ in range(m):
        x, y = map(int, input().split())
        for i in range(n+1):
            sta[i] = False
        sta[x] = True
        dfs(x, 0)
        if(ans != -1):
            print(ans)
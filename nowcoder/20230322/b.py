n, k, s = map(int, input().split())
ans = [[] for i in range(n)]
for _ in range(s):
    ni, ki = map(int, input().split())
    ans[ni-1].append(ki)
res = n
for a in ans:
    if sum(a) >= k:
        res -= 1
print(res)
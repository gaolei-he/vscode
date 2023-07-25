n, k = map(int, input().split())
a = list(map(int, input().split()))
sm = sum(a)
ans = [0]
res = 0
for _ in range(k):
    op, x = map(int, input().split())
    if op == 1:
        res += x
        sm += x * n
    else:
        res -= x
        sm -= x * n
    if res < 0:
        ans.append(-res)
s = [0 for i in range(len(ans))]
print(ans)
for i in range(1, len(ans)):
    s[i] = s[i - 1] + ans[i]
for v in a:
    l, r = 1, len(ans) - 1
    while l < r:
        mid = l + r >> 1
        if ans[mid] <= v:
            l = mid + 1
        else:
            r = mid
    if ans[l] <= v:
        continue
    sm += s[len(ans)-1] - s[l - 1] - (len(ans) - l) * v
print(sm)
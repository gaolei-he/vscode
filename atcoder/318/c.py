n, d, p = map(int, input().split())
f = list(map(int, input().split()))
f.sort(reverse=True)
ans, tmp = 0, 0
for idx, val in enumerate(f):
    if idx % d == 0:
        ans += min(tmp, p)
        tmp = 0
    tmp += val
print(ans + min(tmp, p))
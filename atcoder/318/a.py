n, m, p = map(int, input().split())
ans = 1
if m > n:
    ans = 0
while m <= n:
    m += p
    if m <= n:
        ans += 1
print(ans)
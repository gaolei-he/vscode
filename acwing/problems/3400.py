n, k = map(int, input().split())
ans = 0
for i in range(1, n+1):
    t = i
    while t != 0:
        if t % 10 == k:
            ans += 1
        t //= 10
print(ans)

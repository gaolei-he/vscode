n = int(input())
a = []
mod = 998244353
for _ in range(n):
    a.append(tuple(map(int, input().split())))
dp = [[0 for i in range(2)] for j in range(n)]
dp[0][0] = dp[0][1] = 1
for i in range(1, n):
    for j in range(2):
        if a[i-1][0] != a[i][j]:
            dp[i][j] += dp[i-1][0]
        if a[i-1][1] != a[i][j]:
            dp[i][j] += dp[i-1][1]
    dp[i][0] %= mod
    dp[i][1] %= mod
print((dp[n-1][0] + dp[n-1][1]) % mod)
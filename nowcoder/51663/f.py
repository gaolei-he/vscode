n, mod = int(input()), 10**9+7
dp = [[[0 for i in range(n+1)]for i in range(n+1)] for i in range(n+1)]
for i in range(1, n+1):
    dp[1][0][i] = 1
for i in range(2, n+1):
    for j in range(n):
        for k in range(1, n+1):
            for l in range(1, n+1):
                dp[i][max(j, abs(l-k))][k] += dp[i-1][j][l]
                dp[i][max(j, abs(l-k))][k] %= mod
ans = [0 for i in range(n)]
for i in range(n):
    for j in range(1, n+1):
        ans[i] += dp[n][i][j]
        ans[i] %= mod 
for i in ans:
    print(i)
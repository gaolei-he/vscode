s = " " + input()
dp = [[0, 0] for _ in range(len(s))]
dp[1][1] = ord(s[1]) - ord('a') + 1
for i in range(2, len(s)):
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1])
    dp[i][1] = dp[i - 1][0] + ord(s[i]) - ord('a') + 1
print(max(dp[-1][0], dp[-1][1]))
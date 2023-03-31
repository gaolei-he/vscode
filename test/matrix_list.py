n = int(input())
a = list(map(int, input().split()))
dp = [[10**20 for i in range (n + 1)] for i in range(n + 1)]
for i in range(n + 1):
    dp[i][i] = 0
dic = dict()
for k in range(1, n + 1):
    for i in range(1, n + 1 - k):
        j = k + i
        tmp = i
        for l in range(i, j):
            if dp[i][j] > dp[i][l] + dp[l+1][j] + a[i-1] * a[l] * a[j]:
                dp[i][j] = dp[i][l] + dp[l+1][j] + a[i-1] * a[l] * a[j]
                tmp = l
        dic[(i, j)] = tmp
print(dp[1][n])
ans = []
def output(l:int, r:int):
    mid = dic.get((l, r))
    if l + 1 == r:
        ans.append("A" + str(l) + "A" + str(r))
    else:
        if mid == l:
            ans.append("A" + str(l))
        else:
            ans.append("(")
            output(l, mid)
            ans.append(")")
        if r == mid + 1:
            ans.append("A" + str(r))
        else:
            ans.append("(")
            output(mid + 1, r)
            ans.append(")")
output(1, n)
for x in ans:
    print(x, end='')
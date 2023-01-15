n = int(input())
ans = [[0 for i in range(50)] for i in range(50)]
for i in range(1, 40):
    ans[i][1] = 1
for i in range(2, 40):
    for j in range(2, i+1):
        ans[i][j] = ans[i-1][j-1]
        if i - j > 0:
            ans[i][j] += ans[i-j][j]
print(sum(ans[n]))
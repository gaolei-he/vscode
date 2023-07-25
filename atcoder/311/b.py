n, d = map(int, input().split())
arr = [input() for _ in range(n)]
ans, res = 0, 0
for j in range(d):
    flag = True
    for i in range(n):
        if arr[i][j] == 'x':
            flag = False
            break
    if flag:
        ans += 1
    else:
        res = max(res, ans)
        ans = 0
print(max(res, ans))
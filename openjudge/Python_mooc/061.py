import copy


n, m = map(int, input().split())
ans = []

for i in range(n):
    ans.append(list(map(int, input().split())))
res = copy.deepcopy(ans)
for i in range(1, len(ans)-1):
    for j in range(1, len(ans[i])-1):
        res[i][j] = round((ans[i][j]+ans[i][j-1]+ans[i][j+1]+ans[i-1][j]+ans[i+1][j]) / 5)
for i in res:
    for j in i:
        print(j, end=' ')
    print()
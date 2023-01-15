n, m = map(int, input().split())
ans = []
for i in range(n):
    ans.append(input().split())
for i in range(m):
    for j in range(n):
        print(ans[j][i], end=' ')
    print()
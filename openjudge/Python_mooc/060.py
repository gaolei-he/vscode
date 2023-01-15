n = int(input())
ans = []
for i in range(n):
    ans.append(input().split())
    ans[i][1] = int(ans[i][1])
    ans[i][2] = int(ans[i][2])
ans.sort(key = lambda x:[-x[2], -x[1], x[0]])
for i in ans:
    print(i[0],i[1],i[2])
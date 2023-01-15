n = int(input())
ans = []
for i in range(n):
    ans.append(input().split())
    ans[i][1] = int(ans[i][1])
ans.sort(key=lambda x:-x[1] if x[1] >= 60 else 0)
for i in ans:
    print(i[0])
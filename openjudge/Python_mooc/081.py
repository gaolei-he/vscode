from imp import init_builtin


n, m = map(int, input().split())
dic = {}
for i in range(m):
    tmp = input().split()
    dic[tmp[0]] = [int(tmp[1]), int(tmp[2])]
ans = 0
for i in range(n):
    tmp = input().split()
    for j in tmp:
        if dic[j][1] > 0:
            ans += dic[j][0]
            dic[j][1] -= 1
print(ans)
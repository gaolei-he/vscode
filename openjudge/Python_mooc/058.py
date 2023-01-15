l, m = input().split()[::1]
ans = []
for i in range(int(l)+1):
    ans.append(i)
for i in range(int(m)):
    l, r = input().split()[::1]
    for i in range(int(l), int(r)+1):
        ans[i] = -1
res = 0
for i in ans:
    if i != -1:
        res += 1
print(res)
n = input()
ans = {}
for i in n:
    ans[i] = ans.get(i, 0) + 1
res = 'no'
for i in ans:
    if ans[i] == 1:
        res = i
        break
print(res)
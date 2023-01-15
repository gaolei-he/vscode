ans = [0, 1, 1]
for i in range(3, 47):
    ans.append(ans[i-1]+ans[i-2])
k = int(input())
print(ans[k])
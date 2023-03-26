a = list(map(int, input().split()))
index = [0 for i in range(2010)]
ans = 0
for i, v in enumerate(a):
    for j in range(v+1, 2010):
        ans += index[j]
    if i != 0:
        index[v] += 1
print(ans)
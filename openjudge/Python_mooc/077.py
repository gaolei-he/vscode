n, m, k = map(int, input().split())
ans = [[0 for i in range(k)] for j in range(n)]
m1, m2 = [], []
for i in range(n):
    m1.append(list(map(int, input().split())))
for i in range(m):
    m2.append(list(map(int, input().split())))

for i in range(n):
    for j in range(k):
        sum = 0
        for t in range(m):
            sum += m1[i][t] * m2[t][j]
        ans[i][j] = sum
for i in range(n):
    for j in range(k):
        print(ans[i][j], end=' ')
    print()

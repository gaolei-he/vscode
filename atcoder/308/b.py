n, m = map(int, input().split())
C = list(input().split())
D = list(input().split())
P = list(map(int, input().split()))
dic = dict()
for i in range(m):
    dic[D[i]] = P[i+1]
ans = 0
for s in C:
    ans += dic.get(s, P[0])
print(ans)
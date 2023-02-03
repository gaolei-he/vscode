n, b = map(int, input().split())
a = [0] + list(map(int, input().split()))
s = [0 for i in range(a.__len__())]
cnt = 0
for i in range(1, n+1):
    if a[i] > b:
        a[i] = 1
    elif a[i] < b:
        a[i] = -1
    else:
        cnt = i
        a[i] = 0

for i in range(1, n+1):
    s[i] = s[i-1] + a[i]
dic = {}
for i in range(cnt, n+1):
    dic[s[i]] = dic.get(s[i], 0) + 1
ans = 0
for i in range(1, cnt+1):
    ans += dic.get(s[i-1], 0)

print(ans)

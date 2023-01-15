n = int(input())
ans = 0
res = 0
for i in range(1, n+1):
    s = input().split()
    if (140 >= int(s[0]) >=90 and 60 <= int(s[1]) <= 90):
        ans += 1
    else:
        res = max(res, ans)
        ans = 0
print(max(res, ans))
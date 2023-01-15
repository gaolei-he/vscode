s = input().split()
m, n = int(s[0]), int(s[1])
x, y = 1, 2
ans = 3
for i in range(3, n-m):
    tmp = ans
    x, y = y, tmp
    ans = x + y
print(ans)
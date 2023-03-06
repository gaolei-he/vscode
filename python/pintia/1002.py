n, s = input().split()
n = int(n)
l, r = 0, 1000
while l < r:
    mid = (l + r + 1) // 2
    if mid * (4 + mid * 2) > n - 1:
        r = mid - 1
    else:
        l = mid
space = 0
for i in range(l):
    print(' ' * space + s * ((l - i) * 2 + 1))
    space += 1
print(' ' * space + s)
for i in range(l-1, -1, -1):
    space -= 1
    print(' ' * space + s * ((l - i) * 2 + 1))
print((n - 1) - (4 + l * 2) * l)
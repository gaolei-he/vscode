n = int(input())
a = 0
x = 10**20
while a ** 3 <= x:
    l, r = 0, a
    while l < r:
        mid = (l + r) >> 1
        if (a + mid) * (a**2 + mid**2) < n:
            l = mid + 1
        else:
            r = mid
    if (a + l) * (a ** 2 + l ** 2) >= n:
        x = min(x, (a + l) * (a ** 2 + l ** 2))
    a += 1
print(x)

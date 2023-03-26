from math import gcd
n, a, b = map(int, input().split())
ans = (1 + n) * n // 2
l, r = 0, n
while l < r:
    mid = (l + r + 1) >> 1
    if a * mid > n:
        r = mid - 1
    else:
        l = mid
ans -= (a + l * a) * l // 2

l, r = 0, n
while l < r:
    mid = (l + r + 1) >> 1
    if b * mid > n:
        r = mid - 1
    else:
        l = mid
ans -= (b + l * b) * l // 2
t = gcd(a, b)
a *= b
a //= t
l, r = 0, n
while l < r:
    mid = (l + r + 1) >> 1
    if a * mid > n:
        r = mid - 1
    else:
        l = mid
ans += (a + l * a) * l // 2
print(ans)
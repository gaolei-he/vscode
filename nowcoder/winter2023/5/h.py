x, y, k, n, T = map(int, input().split())
l, r = 1, n + 10
def check(mid):
    if mid > n:
        mid = n
    sold, price, ans = 0, x, 0
    for i in range(n, n - mid, -1):
        sold += i
        ans += price * i
        price = x + sold // k * y
    if ans >= T:
        return True
    return False
while l < r:
    mid = l + r >> 1
    if check(mid):
        r = mid
    else:
        l = mid + 1
if l > n:
    l = -1
print(l)
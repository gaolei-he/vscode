mod = 998244353
n, x = map(int, input().split())
ans = []
for val in range(46):
    res = 1
    for i in range(val + 1):
        res = res * (1 + pow(x, (1 << i), mod)) % mod
    ans.append(res)
if x == 1:
    print(pow(2, n + 1, mod))
    exit(0)
if n < 22:
    print(ans[n])
else:
    print(ans[(n - 22) % 24 + 22])
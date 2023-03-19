p = 998244353
n, k, m = map(int, input().split())
y = pow(k, n, p - 1)
if m % p == 0:
    print(0)
else:
    print(pow(m, y, p))
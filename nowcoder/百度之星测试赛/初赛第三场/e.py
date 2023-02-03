def f(n):
    if n == 2:
        return 3
    return (1 << n) - f(n - 1)
mod = 998244353

for i in range(2, 200):
    x = f(i) % mod
    # print(x)
    for j in range(32):
        print(((x>>j) & 1), end=' ')
    print()
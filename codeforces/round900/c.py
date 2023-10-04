for _ in range(int(input())):
    n, k, x = map(int, input().split())
    l = (1 + k) * k // 2
    r = (n + n - k + 1) * k // 2
    if x >= l and x <= r:
        print('YES')
    else:
        print('NO')
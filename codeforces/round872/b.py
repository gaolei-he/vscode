for _ in range(int(input())):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    v1 = a[-1] - a[0]
    v2 = max(a[-2] - a[0], a[-1] - a[1])
    print(v2 * min(n, m) - v2 + v1 * m * n - v1 * min(n, m))
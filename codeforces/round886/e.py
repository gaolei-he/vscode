for _ in range(int(input())):
    n, c = map(int, input().split())
    a = list(map(int, input().split()))
    l, r = 0, 10**10
    while l < r:
        mid = l + r + 1 >> 1
        sm = 0
        for v in a:
            sm += (v + 2 * mid) * (v + 2 * mid)
        if sm > c:
            r = mid - 1
        else:
            l = mid
    print(l)
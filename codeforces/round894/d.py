for _ in range(int(input())):
    n = int(input())
    l, r = 2, n
    while l < r:
        mid = l + r >> 1
        if mid * (mid - 1) // 2 < n:
            l = mid + 1
        else:
            r = mid
    if l * (l - 1) // 2 == n:
        print(l)
    else:
        print(l - 1 + (n - (l - 1) * (l - 2) // 2))
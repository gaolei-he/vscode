for _ in range(int(input())):
    n, w = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort(reverse=True)
    ans = 0
    for v in a:
        w -= v
        ans += 1
        if w <= 0:
            break
    print(ans)
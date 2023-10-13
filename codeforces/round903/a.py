for _ in range(int(input())):
    m, n = map(int, input().split())
    x, s = input().strip(), input().strip()
    ans = 0
    while s not in x:
        ans += 1
        x = x + x
        if len(x) > len(s) * len(s) and s not in x:
            ans = -1
            break
    print(ans)

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans = 1
    a.sort()
    if len(a) > 1 and a[0] == a[1] and a[0] == 0:
        print(0)
        continue
    elif a[0] == 0:
        for v in a:
            if v != 0:
                ans *= v
        print(ans)
        continue
    for v in a:
        ans *= v
    tmp = ans
    for v in a:
        ans = max(ans, tmp // v * (v + 1))
    print(ans)

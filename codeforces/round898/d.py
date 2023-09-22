for _ in range(int(input())):
    n, k = map(int, input().split())
    s = input()
    val, ans = 0, 0
    for c in s:
        if c == 'B':
            val += 1
        elif c == 'W' and val != 0:
            val += 1
        if val == k:
            val = 0
            ans += 1
    if val != 0:
        ans += 1
    print(ans)
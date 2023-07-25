for _ in range(int(input())):
    n = int(input())
    s = input()
    stk = []
    ans = 0
    for c in s:
        if len(stk) == 0:
            stk.append(c)
        elif stk[-1] == c:
            stk.append(c)
        else:
            stk.clear()
            stk.append(c)
        ans = max(ans, len(stk) + 1)
    print(ans)
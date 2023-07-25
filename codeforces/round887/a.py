for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans, lst = 10**9, -10**9
    for v in a:
        ans = min(ans, (v - lst + 2) // 2)
        lst = v
    print(max(ans, 0))
for _ in range(int(input())):
    n = int(input())
    lst = []
    for i in range(n):
        lst.append(tuple(map(int, input().split())))
    lst.sort()
    ans = 10**10
    for d, s in lst:
        ans = min(ans, d + (s - 1) // 2)
    print(ans)
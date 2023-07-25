for _ in range(int(input())):
    n = int(input())
    ans, mx = -1, -1
    for i in range(n):
        a, b = map(int, input().split())
        if a <= 10 and mx < b:
            mx, ans = b, i + 1
    print(ans)
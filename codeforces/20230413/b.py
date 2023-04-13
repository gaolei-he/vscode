import sys
input = lambda: sys.stdin.readline().strip()
for _ in range(int(input())):
    a, b, n = map(int, input().split())
    if b >= a:
        print(b * n)
    elif b < a:
        ans = (a + b) * (n // 2)
        if n % 2 == 1:
            ans += b
        else:
            ans -= a - b
        print(ans)

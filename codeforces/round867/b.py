def solve():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    print(max(a[0] * a[1], a[-1] * a[-2]))
for _ in range(int(input())):
    solve()
def solve():
    n, t = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    ans, idx = 0, -1
    for i, v in enumerate(a):
        if t >= v and b[i] > ans:
            ans = b[i]
            idx = i
        t -= 1
    if idx != -1:
        idx += 1
    print(idx)

for _ in range(int(input())):
    solve()

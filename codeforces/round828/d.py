from sys import stderr
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    res = []
    for i, v in enumerate(a):
        lowbit = v & -v
        n -= lowbit.bit_length() - 1
        print(n, file=stderr)
        i += 1
        res.append((i & -i).bit_length() - 1)
    res.sort(reverse=True)
    ans = 0
    for v in res:
        if n <= 0:
            break
        n -= v
        ans += 1
    if n <= 0:
        print(ans)
    else:
        print(-1)
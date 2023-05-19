def main():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = []
    n1, n2 = 0, 0
    for v in a:
        if v > 0:
            b.append(v)
        elif v == -1:
            n1 += 1
        elif v == -2:
            n2 += 1

    b = list(set(b))
    b.sort()
    ans = 0
    for i, v in enumerate(b):
        ans = max(ans, min(v - i - 1, n1) + min(m - v - (len(b) - i - 1), n2) + len(b))
    if len(b) > 0 and b[0] != 1:
        ans = max(ans, len(b) + min(n2, m - len(b)))
    if len(b) > 0 and b[-1] != m:
        ans = max(ans, len(b) + min(n1, m - len(b)))
    if len(b) == 0:
        ans = max(ans, min(max(n1, n2), m))
    print(ans)


for _ in range(int(input())):
    main()

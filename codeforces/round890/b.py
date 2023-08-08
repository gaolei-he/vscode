for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    if n == 1:
        print('NO')
        continue
    sm = sum(a)
    for v in a:
        if v == 1:
            sm -= 2
            n -= 1
    if sm >= n:
        print('YES')
    else:
        print('NO')
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    sm = sum(a)
    ans = 'NO'
    for v in a:
        if (sm - v) % 2 == v % 2:
            ans = 'YES'
            break
    print(ans)
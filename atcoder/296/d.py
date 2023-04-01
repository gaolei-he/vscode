n, m = map(int, input().split())
if n * n < m:
    print(-1)
elif n >= m:
    print(m)
else:
    ans = 10**20
    for i in range(1, 10**6+1):
        t = m // i
        if m % i != 0:
            t += 1
        if i > n:
            break
        elif t > n:
            continue
        ans = min(ans, t * i)
    print(ans)
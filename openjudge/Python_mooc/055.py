def f(m, n, s):
    m, n, s = int(m), int(n), int(s)

    if m == 1:
        if n == 1 and s == 1 or n == 0 and s == 0:
            return 1
        else:
            return 0
    if n == 1:
        if s <= m and s >= 1:
            return 1
        else:
            return 0
    
    
    if n > m:
        return 0
    else:
        return f(m-1, n, s) + f(m-1, n-1, s-m)


t = int(input())
for i in range(t):
    m, n, s = input().split()[::1]
    print(f(m, n, s))
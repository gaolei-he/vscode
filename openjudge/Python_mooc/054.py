def f(n):
    if n < 3:
        return n
    return n + f(n-1) + f(n-2)

m = int(input())
for i in range(m):
    n = int(input())
    print(f(n))
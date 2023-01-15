def f(n):
    if n==1: return 1
    if n==2: return 2
    return f(n-1)+f(n-2)
n = int(input())
print(f(n))
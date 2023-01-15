n = int(input())
def f(t):
    if t == 1:
        return 1
    elif t == 2:
        return 2
    else:
        return f(t-1) + f(t-2)
print(f(n))
def f(n:int):
    if n == 1:
        return '1'
    res = f(n - 1)
    return res + ' ' + str(n) + ' ' + res
n = int(input())
print(f(n))
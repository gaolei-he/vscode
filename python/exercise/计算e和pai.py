from math import factorial


def e(n):
    ans = 1
    for i in range(1, n+1):
        ans += 1/factorial(i)
    return ans
def pai(n):
    ans = 0
    flag = 1
    for i in range(1, 4*n, 2):
        ans += 1 / i * flag
        flag *= -1
    return ans * 4
try:
    while True:
        n = int(input())
        print(pai(n))
        print(e(n))
except:
    pass
from math import factorial
def solve(n:int)->int:
    def f(n:int)->int:
        res = 1
        while n > 0:
            res *= n
            n -= 2
        return res
    sm = 1
    for i in range(1, n + 1):
        sm *= f(i)
    ans = 0
    while sm % 10 == 0:
        sm //= 10
        ans += 1
    return ans
def solve1(n:int)->int:
    ans = 0
    sm = factorial(n)
    while sm % 10 == 0:
        ans += 1
        sm //= 10
    return ans
cnt = 0
for i in range(0, 300):
    cnt += 1
    if cnt % 5 == 0:
        print(solve1(i), end=',')
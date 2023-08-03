
def solve1(n:int, p:int)->int:
    return pow(2, pow(2, n), p)
def phi(n:int)->int:
    res = n
    i = 2
    while i * i <= n:
        if n % i == 0:
            res = res // i * (i - 1)
            while n % i == 0:
                n //= i
        i += 1
    if n > 1:
        res = res // n * (n - 1)
    return res

def solve2(n:int, p:int)->int:
    return pow(2, pow(2, n, phi(p)), p)
n, p = map(int, input().split())
for n1 in range(1, n+1):
    for p1 in range(1, p+1):
        if(solve1(n1, p1) != solve2(n1, p1)):
            print(n1, p1)
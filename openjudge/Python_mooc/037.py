from cmath import sqrt
from tokenize import Double


p = int(input())
def isPrime(n):
    if n < 1:
        return False
    r = int(sqrt(n).real)
    for i in range(2, r + 1):
        if n % i == 0:
            return False
    return True

print(2, end='')
for i in range(3, p+1):
    if isPrime(i):
        print(" "+str(i), end='')

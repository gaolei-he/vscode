from math import gcd
def mygcd(a, b):
    if b == 0:
        return a
    return mygcd(b, a%b)

n = input().split()
a, b, c = int(n[0]), int(n[1]), int(n[2])
b = b * c // mygcd(b, c)
a = a * b // mygcd(a, b)
print(a)
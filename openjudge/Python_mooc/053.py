from math import gcd

def mygcd(a, b):
    if b == 0:
        return a
    return mygcd(b, a%b)
s = input().split()
print(mygcd(int(s[0]), int(s[1])))
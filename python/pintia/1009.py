from math import gcd
n = int(input())
a = []
for p in input().split():
    p = list(map(int, p.split('/')))
    a.append(p)
s1, s2 = 0, 1
for p in a:
    s2 *= p[1]
for p in a:
    s1 += s2 // p[1] * p[0]

k = gcd(s1, s2)
s1 //= k
s2 //= k
if abs(s1) < s2:
    print(f'{s1}/{s2}')
elif s1 % s2 == 0:
    print(s1//s2)
else:
    print(f'{s1//s2} {s1%s2}/{s2}')
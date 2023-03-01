from random import random
from sys import stderr
t = int(input())
s = "abcdefghijklmnopqrstuvwxyz"
vals = "testcases"
keys = []
def f():
    string = ''
    for i in range(int(random()*4)+1):
        string = string + s[int(random()*26)]
    keys.append(string)
    print(string, end=' ')
    for i in range(int(random()*10)+1):
        print(s[int(random()*26)], end='')
    print()
print(t)
sn, sq = 0, 0
for _ in range(t):
    # n, q = map(int, input().split())
    n, q = int(random() * 10), int(random() * 10)
    sn += n
    sq += q
    if sn > 100000 or sq > 200000:
        print("ERROR", file=stderr)
    print(n, q)
    for i in range(n):
        f()
    for i in range(q):
        print(keys[int(random() * len(keys))])

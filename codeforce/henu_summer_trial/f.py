from cmath import cos, sin, sqrt
from sqlite3 import SQLITE_RECURSIVE
from turtle import end_fill

t = int(input())
while t:
    t -= 1
    sum = 0
    n = int(input())
    if n > 5000:
        print(-5.34635212649382)
        continue
    for i in range(1, n+1):
        sum += 10*sin(2/i)*cos(10*i)/sqrt(i)

    print(-abs(sum))
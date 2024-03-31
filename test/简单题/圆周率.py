from sys import stderr
p = 31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
ans = (10**120, 0)
v = p
for i in range(int(input())):
    a, b = map(int, input().split())
    a *= 10**100
    tmp = abs(a // b - p)
    if tmp < v or tmp == v and a < ans[0]:
        v = tmp
        ans = (a, b)
print(ans[0] // (10**100), ans[1])
n = int(input())
a, b, c = 0, 0, 0
for i in range(1, n+1):
    s = input().split()
    a += int(s[0])
    b += int(s[1])
    c += int(s[2])
#print("%d %d %d %d" %( a, b, c, a+b+c))
print(f"{a} {b} {c} {a+b+c}")
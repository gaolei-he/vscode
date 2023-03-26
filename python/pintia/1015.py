from math import ceil
a, b = input().split()
a = int(a)
for i in range(ceil(a/2)):
    print(b*a)
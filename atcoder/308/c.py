from functools import cmp_to_key
n = int(input())
a = []
for i in range(n):
    a.append(list(map(int, input().split())))
    a[-1].append(i+1)
def f(a:list, b:list)->int:
    val = a[0] * (b[0] + b[1]) - b[0] * (a[0] + a[1])
    if val == 0:
        return a[2] - b[2]
    return -val


for x, y, z in sorted(a, key=cmp_to_key(f)):
    print(z, end=' ')
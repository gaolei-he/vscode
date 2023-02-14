n = int(input())
a = list(map(int, input().split()))
a.sort()
a = a[n//2:]
a.reverse()
def f(v:int, t:int)->int:
    while v > 0 and t != 0:
        v //= 2
        t -= 1
    return v
for i in range(1, len(a) + 1):
    a[i-1] = f(a[i-1], i)
print(sum(a))
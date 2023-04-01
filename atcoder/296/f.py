n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
ans = 0
lib = set()
for i in range(n):
    if a[i] != b[i]:
        t = (min(a[i], b[i]), max(a[i], b[i]))
        if t in lib:
            print("No")
            exit(0)
        lib.add(t)
a.sort()
b.sort()
for v1, v2 in zip(a, b):
    if v1 != v2:
        print("No")
        exit(0)
print("Yes")
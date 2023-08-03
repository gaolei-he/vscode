n = int(input())
a = list(map(int, input().split()))
b = []
for v in a:
    if v % 2 != 0:
        b.append(v)
print(max(b))
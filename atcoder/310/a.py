n, p, q = map(int, input().split())
for v in list(map(int, input().split())):
    p = min(q + v, p)
print(p)

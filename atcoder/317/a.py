n, h, x = map(int, input().split())
p = list(map(int, input().split()))
p.sort()
for idx, val in enumerate(p):
    if val + h >= x:
        print(idx + 1)
        exit(0)

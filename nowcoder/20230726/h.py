n = int(input())
a = list(map(int, input().split()))
a.sort()
sm = 0
for v in a:
    if v > sm + 1:
        print(sm + 1)
        exit(0)
    sm += v
print(sm + 1)
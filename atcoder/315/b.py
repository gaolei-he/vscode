m = int(input())
d = list(map(int, input().split()))
sm, tmp = sum(d), 0
for idx, val in enumerate(d):
    tmp += val
    if tmp > sm // 2:
        print(idx + 1, sm // 2 + 1 - tmp + val)
        break
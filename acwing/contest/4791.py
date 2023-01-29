n = int(input())
ans = [0 for i in range(4)]
for i in range(n):
    t, x, y = map(int, input().split())
    if t == 1:
        ans[0] += x
        ans[1] += y
    else:
        ans[2] += x
        ans[3] += y
if ans[0] >= ans[1]:
    print('LIVE')
else:
    print("DEAD")
if ans[2] >= ans[3]:
    print('LIVE')
else:
    print("DEAD")
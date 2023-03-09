from sys import stderr
h, w = map(int, input().split())
a = []
for _ in range(h):
    a.append(input())
ans = []
for i, b in enumerate(a):
    for j, v in enumerate(b):
        if v == 'o':
            ans.append([i, j])
print(abs(ans[0][0] - ans[1][0]) + abs(ans[0][1] - ans[1][1]))
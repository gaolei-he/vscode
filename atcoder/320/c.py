m = int(input())
s1, s2, s3 = input(), input(), input()
ans = 10**9
for i, c1 in enumerate(s1 + s1 + s1):
    for j, c2 in enumerate(s2 + s2 + s2):
        for k, c3 in enumerate(s3 + s3 + s3):
            if i == j or i == k or j == k:
                continue
            if c1 == c2 == c3:
                ans = min(ans, max(i, j, k))
if ans == 10**9:
    print(-1)
else:
    print(ans)
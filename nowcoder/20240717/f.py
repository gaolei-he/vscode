n = int(input())
arr = list(map(int, input().split()))
sm, ans = 0, 0
for v in arr:
    sm ^= v

for i in range(n):
    sm ^= arr[i]
    for j in range(1, n // (i + 1) + 1):
        val = arr[i] + j
        if (sm ^ val) > ans:
            ans = sm ^ val
        val = arr[i] * j
        if (sm ^ val) > ans:
            ans = sm ^ val
    sm ^= arr[i]
print(ans)


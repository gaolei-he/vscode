n, t = map(int, input().split())
arr = list(map(int, input().split()))
ans, val = 0, 0
for i in range(n, n - min(t, n-1) - 1, -1):
    if val < arr[i % n]:
        ans = n - i
        val = arr[i % n]
print(ans)
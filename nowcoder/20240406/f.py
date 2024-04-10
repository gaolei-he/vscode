arr = list(map(int, input().split()))
ans = 0
for v in arr:
    if v > 0 and ans == 0:
        ans += v
    elif v > 0:
        ans += v - 1
print(ans)
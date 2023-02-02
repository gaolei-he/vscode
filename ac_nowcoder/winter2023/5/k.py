n = int(input())
ans = 0
while n > 2:
    if n & 1:
        n -= n >> 1
    else:
        n -= (n >> 1) - 1
    ans += 1
print(ans)
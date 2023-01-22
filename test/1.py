a = list(map(int, input().split()))
i = 1
ans = 0
for i in range(1, 18):
    ans = ans + (1 << (18-i)) * a[i-1] % 11
    ans %= 11
print((12 - ans) % 11)
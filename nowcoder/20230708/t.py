ans = 0
n = int(input())
n -= 1
a, b = 26, 1
for i in range(n):
    ans += a * b
    if i & 1:
        b += 1
    else:
        a *= 26
print(ans * 25)
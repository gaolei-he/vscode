n = int(input())
s = input()
zero, one = 0, 0
ans = 0
for c in s:
    if c == '0':
        one, zero = zero + one, 1
    else:
        zero, one = one, zero + 1
    ans += one
print(ans)
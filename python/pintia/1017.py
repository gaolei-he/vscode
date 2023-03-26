s = input()
ans = 0
n2, nl = 0, 0
for c in s:
    if c == '2':
        n2 += 1
    if c != '-':
        nl += 1
ans = n2 / nl
if s[0] == '-':
    ans += 0.5 * ans
if int(s[-1]) % 2 == 0:
    ans += ans
print((100*ans).__format__('.2f') + '%')
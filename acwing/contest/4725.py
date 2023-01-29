s = input()
ans = 'aeiouyAEIOUY'
op = ''
i = -2
while s[i] == ' ':
    i -= 1
if s[i] in ans:
    print("YES")
else:
    print("NO")
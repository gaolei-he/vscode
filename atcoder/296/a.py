n, s = input(), input()
ans = "Yes"
for c in s:
    if c == n:
        ans = "No"
        break
    n = c
print(ans)
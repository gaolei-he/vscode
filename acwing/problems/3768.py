n, cnt, ans = int(input()), 0, 0
s = input()
for i in s:
    if i == 'x':
        cnt += 1
    else:
        ans += max(cnt - 2, 0)
        cnt = 0
else:
    ans += max(cnt-2, 0)
print(ans)
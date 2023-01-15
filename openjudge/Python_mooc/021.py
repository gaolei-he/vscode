n = input().split()
ans = 8
#ans += 
if int(n[0]) > 1000:
    ans += ((int(n[0]) - 1000) // 500) * 4
    if int(n[0]) % 500:
        ans += 4
if n[1] == 'y':
    ans += 5
print(ans)

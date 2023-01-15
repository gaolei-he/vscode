n = int(input())
s = input().split()
ans = 0
for i in s:
    if(int(i) >= 30):
        ans += 1
print(ans)
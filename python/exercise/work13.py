from datetime import *
start = date(2003,3,26)
end = date(2021,10,24)
temp = timedelta(days = 1)
ans = 0
while start != end:
    ans += 1
    start += temp

print(ans)
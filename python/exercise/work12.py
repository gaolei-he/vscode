from datetime import *
start = (2003,3,18)#date
end = (2021,10,24)
temp = timedelta(days = 1)
ans = 0
while start != end:
    ans += 1
    start += temp 

print(ans)
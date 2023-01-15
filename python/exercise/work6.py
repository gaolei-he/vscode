from datetime import *
start = date(2000,1,1)
end = date(2020,10,2)
tmp = timedelta(days = 1)
ans = 0
while start != end:
    if start.year == 2016:
        ans += 5643564
    else:
        ans += 1
    start = start + tmp
print(ans)
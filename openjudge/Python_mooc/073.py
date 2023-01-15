from calendar import week, weekday
import datetime
from math import ceil, floor
import time
n = int(input())
months = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
for i in range(n):
    weekdays = "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
    y, m, d = map(int, input().split())
    days = 0
    if y <= 0:
        y += ceil(abs(y) / 400) * 400 + 1600
    elif y > 2000:
        y -= floor(y / 400) * 400 + 1600
    try:
        dt = datetime.date(y, m, d)
    except:
        print('Illegal')
        continue
    print(weekdays[dt.weekday()])

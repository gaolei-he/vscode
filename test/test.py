#!/usr/bin/env python3

from datetime import datetime, timedelta
from random import randint
year = randint(1, 9000)
a = datetime(year, 1, 1)
b = datetime(year + 4, 1, 1)
dlt = timedelta(days=1)
for i in range(160000):
    a += dlt
    b += dlt
    if a.month != b.month or a.day != b.day:
        print(a, b)
        break
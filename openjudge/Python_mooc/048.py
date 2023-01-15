from itertools import count
import re


n = int(input())
for i in range(1, n+1):
    c = input().lower()
    s = input().lower()
    s = re.split('  *', s)

    for i in s:
        print(i.count(c),end=' ')
    print()
from operator import index
from textwrap import indent


n = [True]
n = n * 10
del n[3]

try:
    n.index(False)
except Exception as e:
    print(e) 

s, n, m = map(int, input().split())
print(s, n, m)
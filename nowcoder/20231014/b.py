import sys
import os
n, q = map(int, input().split())
for _ in range(q):
    s = input().strip()
    ans = 1
    for c in s:
        if c == 'R':
            ans *= 2
        else:
            ans = ans * 2 - 1
    print(ans)
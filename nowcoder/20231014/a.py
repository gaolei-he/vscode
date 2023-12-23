import os
import sys
for _ in range(int(input())):
    st = input().strip()
    s = []
    for c in st:
        s.append(c)
    s.sort()
    
    if s[0] == s[1] == s[2] and s[2] != s[3] or s[1] == s[2] == s[3] and s[0] != s[1]:
        print('Yes')
    else:
        print('No')
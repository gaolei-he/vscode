import sys
input = sys.stdin.readline
n = int(input())
s1, s2 = input().strip(), input().strip()
ans = 0
last = 0
for c1, c2 in zip(s1, s2):
    v1, v2 = ord(c1) - ord('a') + 1, ord(c2) - ord('a') + 1
    if v1 > v2:
        t1 = v1 - v2
        t2 = v2 - v1 + 10 + last
        if t1 < t2:
            ans += t1
            last = 1
        else:
            ans += t2
            last = -1
    elif v2 > v1:
        t1 = v1 - v2 + 10 - last
        t2 = v2 - v1
        if t1 < t2:
            ans += t1
            last = 1
        else:
            ans += t2
            last = -1
    else:
        last = 0
print(ans)
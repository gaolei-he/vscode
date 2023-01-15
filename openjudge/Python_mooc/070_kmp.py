n = int(input())
for i in range(n):
    s, p = input().split()
    ne = [0] * 10000
    j = 0
    p = ' ' + p
    s = ' ' + s
    for k in range(2, len(p)):
        while j != 0 and p[k] != p[j+1]:
            j = ne[j]
        if p[k] == p[j+1]:
            j += 1
        ne[j] = j
    j = 0
    for k in range(1, len(s)):
        while j != 0 and p[j+1] != s[k]:
            j = ne[j]
        if s[k] == p[j+1]:
            j += 1
        if j == len(p) - 1:
            print(k-len(p)+1, end=' ')
            j = 0
    if p[1::1] not in s[1::1]:
        print('no')
    else:
        print()
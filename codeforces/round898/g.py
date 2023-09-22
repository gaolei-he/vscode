for _ in range(int(input())):
    s = input()
    a = []
    cnt = 0
    for c in s:
        if c == 'A':
            cnt += 1
        elif c == 'B' and cnt != 0:
            a.append(cnt)
            cnt = 0
    if cnt != 0:
        a.append(cnt)
    a.sort()
    if len(a) == 0:
        print(0)
        continue
    if s[0] == s[-1] and s[0] == 'A' and s.count('B') < len(a):
        print(sum(a) - a[0])
    else:
        print(sum(a))
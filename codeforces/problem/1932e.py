for _ in range(int(input())):
    n = int(input())
    s = input().strip()
    a = [0 for i in range(n + 1)]
    r = 1
    for c in reversed(s):
        a[0] += ord(c) - ord('0')
        a[r] -= ord(c) - ord('0')
        r += 1
    for i in range(n):
        a[i + 1] += a[i]
    lst, idx = 0, 0
    while lst != 0 or idx < n:
        if idx == n and lst != 0:
            a.append(0)
        a[idx] += lst
        lst = a[idx] // 10
        a[idx] %= 10
        idx += 1
    while a[-1] == 0:
        a.pop()
    print(*a[::-1], sep='')
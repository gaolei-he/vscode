n = int(input())
a = [tuple(input().strip().split()) for _ in range(n)]
a.sort()
q = int(input())
for _ in range(q):
    s = input().strip()
    l, r = 0, n - 1
    while l < r:
        mid = (l + r) // 2
        if a[mid] >= (s, ''):
            r = mid
        else:
            l = mid + 1
    if a[l] < (s, ''):
        print("-1 -1")
    else:
        print(a[l][0], a[l][1])
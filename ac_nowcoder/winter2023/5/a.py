n, q = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
a = [0] + a
s = [0 for i in range(len(a))]
for i in range(1, n+1):
    s[i] = a[i] + s[i-1]
for _ in range(q):
    k, x = map(int, input().split())
    l, r = 0, n
    while l < r:
        mid = l + r + 1 >> 1
        if(a[mid] > x):
            r = mid - 1
        else:
            l = mid
    print(s[l] - s[max(l-k, 0)])

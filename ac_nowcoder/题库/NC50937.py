n = int(input())
a = list(map(int, input().split()))
a.sort()
s = [0 for i in range(len(a)+1)]
for i in range(len(a)):
    s[i] = a[i] + s[i-1]
ans = int(1e14)
def f(val):
    l, r = 0, len(a) - 1
    while l < r:
        mid = (l + r) // 2
        if a[mid] >= val:
            r = mid
        else:
            l = mid + 1
    l1 = l
    l, r = 0, len(a) - 1
    while l < r:
        mid = (l + r + 1) // 2
        if a[mid] <= val:
            l = mid
        else:
            r = mid - 1
    r1 = l
    res = 0
    if l1 == r1:
        res += s[-2] - s[l1] - a[l1] * (len(a) - l1 - 1)
        res += a[l1] * (l1 + 1) - s[l1]
    elif l1 < r1:
        res += s[-2] - s[r1] - a[r1] * (len(a) - r1 - 1)
        res += a[l1] * (l1 + 1) - s[l1]
    else:
        res += s[-2] - s[r1] - val * (len(a) - l1)
        res += val * l1 - s[r1]
    return res

for i in range(a[0], a[-1]+1):
    
    ans = min(ans, f(i))
print(ans)
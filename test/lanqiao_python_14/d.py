import sys
input = sys.stdin.readline
n, len = map(int, input().split())
lst = []
for _ in range(n):
    lst.append(tuple(map(int, input().split())))
def check(mid:int)->bool:
    a = []
    for x, y in lst:
        if y > mid:
            continue
        l, r = max(1, x - (mid - y)), min(len, x + (mid - y))
        a.append((l, r))
    a.sort()
    l, r = 0, 0
    for x, y in a:
        if l == 0 and r == 0:
            l, r = x, y
        elif x <= r + 1:
            r = max(r, y)
    # print(l, r, mid)
    if l == 1 and r == len:
        return True

    return False
l, r = 0, 10**10
while l < r:
    mid = l + r >> 1
    if check(mid):
        r = mid
    else:
        l = mid + 1
print(l)
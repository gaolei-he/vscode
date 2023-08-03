import sys
input = sys.stdin.readline
n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
l, r = 0, max(a + b) + 1
def check(mid : int) -> bool:
    c1, c2 = 0, 0
    for v in a:
        if v <= mid:
            c1 += 1
    for v in b:
        if mid <= v:
            c2 += 1
    if c1 >= c2:
        return True
    else:
        return False
while l < r:
    mid = l + r >> 1
    if check(mid):
        r = mid
    else:
        l = mid + 1
print(l)
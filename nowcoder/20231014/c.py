import os
import sys

n, k = map(int, input().split())
lst = list(map(int, input().split()))
lst.sort()
l, r = 0, lst[-1] - lst[0]
def check(mid:int)->bool:
    cnt = 1
    st = lst[0]
    for v in lst:
        if v - st > mid:
            cnt += 1
            st = v
    if cnt <= k:
        return True
    return False
while l < r:
    mid = l + r >> 1
    if check(mid):
        r = mid
    else:
        l = mid + 1

print(l)
from itertools import pairwise
n = int(input())
a = list(map(int, input().split()))
a.sort()
for v1, v2 in pairwise(a):
    if v1 + 1 != v2:
        print(v1 + 1)
        exit()
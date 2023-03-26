from itertools import combinations
n, k = map(int, input().split())
point = []
for _ in range(n):
    point.append(tuple(map(int, input().split())))
dic = dict()
for p1, p2 in combinations(point, 2):
    x = abs
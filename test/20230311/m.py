from itertools import combinations
n, k = map(int, input().split())
point = []
for _ in range(n):
    point.append(tuple(map(int, input().split())))
from collections import defaultdict

def count_lines(points, k):
    lines = set()
    slope_intercept = defaultdict(list)
    for i in range(len(points)):
        for j in range(i+1, len(points)):
            x1, y1 = points[i]
            x2, y2 = points[j]
            if x1 == x2:
                slope = float('inf')
                intercept = x1
            else:
                slope = (y1 - y2) / (x1 - x2)
                intercept = y1 - slope * x1
            slope_intercept[(slope, intercept)].append((i, j))
    for lst in slope_intercept.values():
        if len(lst) >= k:
            points_on_line = set()
            for i, j in lst:
                points_on_line.add(i)
                points_on_line.add(j)
            if len(points_on_line) >= k:
                lines.add((lst[0][0], lst[0][1]))
    return len(lines)
print(count_lines(point, k))
a, v1, v2, v1p = map(int, input().split())
t1 = a / (v1 + v2)
t2 = t1 * v2 / v1p
print(t1 + t2)
n = int(input())
dic = dict()
for _ in range(n):
    v = int(input())
    dic[v] = dic.get(v, 0) + 1
ma = 0
for v in dic.values():
    ma = max(v, ma)
for p in dic.items():
    if p[1] == ma:
        print(p[0])
        print(p[1])
n, m = map(int, input().split())
dic = {}
for i in range(n):
    st = set(list(map(int, input().split()))[1:])
    for v in st:
        dic[v] = dic.get(v, 0) + 1
ans = 0
for k, v in dic.items():
    ans ^= v
print('Alice' if ans else 'Bob')
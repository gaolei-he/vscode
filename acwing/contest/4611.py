n, k = map(int, input().split())
a = list(map(int, input().split()))
dic = [{} for i in range(11)]
for i in a:
    x = 1
    for j in range(1, 11):
        x *= 10
        mod = i * x % k
        dic[j][mod] = dic[j].get(mod, 0) + 1
res = 0

for i in a:
    t, x = 0, i
    while x != 0:
        x //= 10
        t += 1
    r = i % k
    if r != 0:
        r = k - r
    res += dic[t].get(r, 0)
    x = i
    while t != 0:
        x *= 10
        t -= 1
    x += i
    if x % k == 0:
        res -= 1
print(res)

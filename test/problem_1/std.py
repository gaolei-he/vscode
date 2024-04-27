m, n, q = map(int, input().split())
dic = {}
for _ in range(m):
    pub, pri = input().split()
    dic[pri] = pub
hosts = {}
for _ in range(n):
    ip, k = input().split()
    k = int(k)
    for __ in range(k):
        user, t, *keys = input().split()
        t = int(t)
        hosts[(ip, user)] = set(keys)

for _ in range(q):
    user, ip, key = input().split()
    pub = dic[key]
    if (ip, user) in hosts and pub in hosts[(ip, user)]:
        print('Yes')
    else:
        print('No')

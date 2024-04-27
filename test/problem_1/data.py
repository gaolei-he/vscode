from random import randint, shuffle
m, q, n = randint(1, 100), randint(1, 100), randint(1, 10)
keys = set()
data = 'abcedfghijklmnopqrstuvwxyz'
while len(keys) < m * 2:
    keys.add(''.join([data[randint(0, 25)] for _ in range(randint(1, 10))]))
keys = list(keys)
print(m, n, q)
for i in range(0, m * 2, 2):
    print(keys[i], keys[i + 1])

ips = set()
while len(ips) < n:
    ip = '.'.join([str(randint(0, 255)) for _ in range(4)])
    ips.add(ip)


query = []
ips = list(ips)
all_users = []
for IPv4 in ips:
    k = randint(1, 10)
    print(IPv4, k)
    users = set()
    while len(users) < k:
        name = ''.join([data[randint(0, 25)] for _ in range(randint(1, 10))])
        users.add(name)
    users = list(users)
    for user in users:
        all_users.append(user)
        t = randint(1, min(10, m))

        idxs = [_ for _ in range(0, m * 2, 2)]
        shuffle(idxs)
        idxs = idxs[:t]
        for idx in idxs:
            query.append(user + ' ' + IPv4 + ' ' + keys[idx+1])
        print(user, t, ' '.join([keys[idx] for idx in idxs]))

for _ in range(q):
    if randint(0, 1) == 0:
        print(query[randint(0, len(query) - 1)])
        continue
    print(all_users[randint(0, len(all_users) - 1)], ips[randint(0, len(ips) - 1)], keys[randint(0, m - 1) * 2 + 1])


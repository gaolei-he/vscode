from random import randint





char = 'abcdefghijklmnopqrstuvwxyz'
n = randint(1, 100)

dic = {}
dic['/'] = set()
pwd = '/'



print(n)
for i in range(n):
    ans = '/'
    for k in range(randint(1, 3)):
        for j in range(randint(1, 3)):
            ans += char[randint(0, 3)]
        ans += '/'
    print(ans[:-1])
    data = ans.strip().split('/')[1:]
    key = '/'
    for v in data:
        dic[key] = dic.get(key, set())
        dic[key].add(v)
        if key[-1] != '/':
            key = key + '/'
        key = key + v
m = randint(1, 100)
print(m)
for i in range(m):
    op = randint(0, 2)
    data = ''
    if op == 0:
        print('pwd')
        data = 'pwd'
    elif op == 1:
        print('ls')
        data = 'ls'
    else:
        data = 'cd '
        op = randint(0, 2)
        if op == 0:
            print('cd .')
        elif op == 1:
            print('cd ..')
        else:

            ans = list(dic.get(pwd, set()))
            ans.sort()
            data = data + ans[randint(0, len(ans) - 1)]
            print(data)
            dir = data[3:]
            if dir == '.':
                continue
            elif dir == '..':
                if pwd != '/':
                    pwd = pwd[:pwd.rfind('/')]
                continue
            if pwd != '/':
                pwd = pwd + '/' + dir
            else:
                pwd = pwd + dir

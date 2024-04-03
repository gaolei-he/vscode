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
    dir = ''
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
            dir = '.'
        elif op == 1:
            print('cd ..')
            dir = '..'
        else:

            ans = list(dic.get(pwd, set()))
            if len(ans) == 0:
                print('cd .')
                continue
            data = data + ans[randint(0, len(ans) - 1)]
            print(data)
            if(data.strip() == 'cd'):
                print(data, "fff", *ans)
                exit(-1)
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

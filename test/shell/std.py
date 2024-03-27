n = int(input())
dic = {}
dic['/'] = set()
for i in range(n):
    data = input().strip().split('/')[1:]
    key = '/'
    for v in data:
        dic[key] = dic.get(key, set())
        dic[key].add(v)
        if key[-1] != '/':
            key = key + '/'
        key = key + v
m = int(input())
pwd = '/'
for i in range(m):
    data = input().strip()
    if data == 'pwd':
        print(pwd)
    elif data == 'ls':
        ans = list(dic.get(pwd, set()))
        ans.sort()
        for v in ans:
            print(v)
    else:
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
gi
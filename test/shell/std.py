'''
以绝对路径的形式存储目录项 即map<string, set<string>> dic
例如 /dir下有a,b两个文件夹 则dic['/dir'] = {'a', 'b'}
读入目录过程中 以/分割路径 逐级存入dic

执行命令过程中，维护当前绝对路径pwd，对于cd命令，注意特判

'''

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
                if pwd == '':
                    pwd = '/'
            continue
        if pwd != '/':
            pwd = pwd + '/' + dir
        else:
            pwd = pwd + dir
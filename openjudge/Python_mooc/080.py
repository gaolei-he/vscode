t = int(input())
for i in range(t):
    dic = {}
    n = int(input())
    for i in range(n*10):
        tmp = input().split()
        dic[tmp[0]] = dic.get(tmp[0], [])
        dic[tmp[0]].append(int(tmp[1]))
    for i in dic.keys():
        dic[i] = sum(dic[i]) / len(dic[i])
    dic = list(dic.items())
    dic.sort(key=lambda x:x[1])
    print(dic[0][0])
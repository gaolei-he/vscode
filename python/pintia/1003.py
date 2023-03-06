s = input()
dic = {}
for i in s:
    dic[i] = dic.get(i, 0) + 1
dic = list(dic.items())
dic.sort()
for p in dic:
    print(str(p[0]) + ':' + str(p[1]))

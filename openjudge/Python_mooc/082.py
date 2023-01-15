n = int(input())
dic = {}
for i in range(n):
    tmp = input().split()
    dic[tmp[0]] = dic.get(tmp[0], [])
    dic[tmp[0]].append([tmp[1], int(tmp[2])])
m = int(input())
for i in range(m):
    tmp = input().split()[1:]
    ans = {}
    for j in tmp:
        for k in dic[j]:
            ans[k[0]] = ans.get(k[0], [])
            ans[k[0]].append(k[1])
    ans1 = []
    for j in ans.items():
        if len(j[1]) == len(tmp):
            ans1.append([j[0], sum(j[1])/len(tmp)])
    ans1.sort(key=lambda x:[-x[1], x[0]])
    print(ans1[0][0])
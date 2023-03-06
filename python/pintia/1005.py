n = int(input())
dic = {}
for _ in range(n):
    tmp = input().split()
    dic[tmp[1]] = tmp[0] + ' ' + tmp[2]
m = int(input())
query = input().split()
for q in query:
    print(dic[q])
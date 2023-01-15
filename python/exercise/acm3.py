n = int(input())
lists = []
for i in range(n):
    a,b = map(str,input().split())
    lists1 = a.split('.')
    lists2 = b.split('.')
    x = lists1[0]+'.'+lists1[1]+'.'+lists1[2]+'.'+lists2[-1]
    lists.append(x)
for i in range(n):
    print(lists.pop(0))
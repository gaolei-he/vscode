n = {}
try:
    while True:
        tmp = input()
        n[tmp] = n.get(tmp, 0) + 1
except:
    pass
n = list(n.items())
n.sort(key=lambda x:[-x[1],x[0]])
for i in n:
    print(i[1], i[0])
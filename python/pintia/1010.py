a = list(map(int, input().split()))
a.sort()
for i, v in enumerate(a):
    if i != 0:
        print('->', end='')
    print(v, end='')
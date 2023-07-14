a = list(map(int, input().split()))
lst = a[0]
for v in a:
    if v >= lst and v % 25 == 0 and v >= 100 and v <= 675:
        lst = v
        continue
    else:
        print('No')
        exit(0)
print('Yes')

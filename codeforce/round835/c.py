t = int(input())
for i in range(t):
    n = int(input())
    lst = list(map(int, input().split()))
    ma = max(lst)
    tmp = sorted(lst)
    if tmp[-1] == tmp[-2]:
        for j in lst:
            print(j-ma, end=' ')
    else:
        tmp.pop(-1)
        ma1 = max(tmp)
        for  j in lst:
            if j == ma:
                print(j-ma1, end=' ')
            else:
                print(j-ma, end=' ')
    print()
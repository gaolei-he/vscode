for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    dic1 = dict()
    last, cnt = a[0], 0
    for v in a:
        if v == last:
            cnt += 1
        else:
            dic1[last] = max(dic1.get(last, 0), cnt)
            last, cnt = v, 1
    dic1[last] = max(dic1.get(last, 0), cnt)
    dic2 = dict()
    last, cnt = b[0], 0
    for v in b:
        if v == last:
            cnt += 1
        else:
            dic2[last] = max(dic2.get(last, 0), cnt)
            last, cnt = v, 1
    dic2[last] = max(dic2.get(last, 0), cnt)
    ans = 0
    for k, v in dic1.items():
        ans = max(v + dic2.get(k, 0), ans)
    for k, v in dic2.items():
        ans = max(v + dic1.get(k, 0), ans)
    print(ans)

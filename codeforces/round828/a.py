for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    s = input()
    dic = dict()
    ans = 'YES'
    for i, v in enumerate(a):
        if dic.get(v, None) == None:
            dic[v] = s[i]
        elif dic.get(v) != s[i]:
            ans = 'NO'
            break
    print(ans)
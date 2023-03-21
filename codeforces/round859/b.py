for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b, c = [], []
    for x in a:
        if x % 2 == 0:
            b.append(x)
        else:
            c.append(x)
    if(sum(b) > sum(c)):
        print("YES")
    else:
        print("NO")
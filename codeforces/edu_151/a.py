for _ in range(int(input())):
    n, k, x = map(int, input().split())
    if x != 1:
        print('YES')
        print(n)
        print("1 " * n)
    elif k >= 3:
        print('YES')
        if n % 2 == 0:
            print(n // 2)
            print("2 " * (n // 2))
        else:
            print(n // 2)
            print("3 ")
            print("2 " * (n // 2 - 1))
    elif k == 2:
        if n % 2 == 0:
            print('YES')
            print(n // 2)
            print("2 " * (n // 2))
        else:
            print('NO')
    else:
        print('NO')
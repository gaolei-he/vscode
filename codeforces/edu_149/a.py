for _ in range(int(input())):
    x, k = map(int, input().split())
    if x < k:
        print("1\n" + str(x))
    elif x == k:
        print("2\n1 " + str(x - 1))
    elif x % k != 0:
        print("1\n" + str(x))
    else:
        print("2\n" + str(x + 1) + " -1")
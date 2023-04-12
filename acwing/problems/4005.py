for _ in range(int(input())):
    n, k = map(int, input().split())
    if k % 3 != 0:
        if n % 3 == 0:
            print("Bob")
        else:
            print("Alice")
    else:
        k //= 3
        T = k * 3 + 1
        n %= T
        if n != T - 1 and n % 3 == 0:
            print("Bob")
        else:
            print("Alice")
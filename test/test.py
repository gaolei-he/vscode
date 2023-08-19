for _ in range(int(input())):
    m, n = map(int, input().split())
    if (m % 3) ^ n == 0:
        print("Bob")
    else:
        print("Alice")
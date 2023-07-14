for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    for v in a:
        print(n + 1 - v, end=' ')
    print()
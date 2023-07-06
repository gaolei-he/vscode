for _ in range(int(input())):
    n, k = map(int, input().split())
    if k >= 50:
        k = 50
    print(min(n+1, pow(2, k)))
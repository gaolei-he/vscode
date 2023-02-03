t = int(input())
while t != 0:
    t -= 1
    n, m = map(int, input().split())
    sum = 1
    # n, m = n + 1, m + 1
    for i in range(n-2, n+2):
        sum *= i
    for i in range(m-2, m+2):
        sum *= i
    print(int(int(sum//2//3//4//2//3//4) % (1000000007)) )

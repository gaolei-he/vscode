from math import factorial


def C(n, k):
    return factorial(n) // factorial(k) // factorial(n-k)

for n in range(1, 6):
    for m in range(1, 6):
        sum = 0
        for i in range(1, m):
            for j in range(1, n+1):
                sum += C(n, j) * j * int(pow(i, n-j))
        print(sum + n, end=' ')
    print()

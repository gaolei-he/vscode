from random import randint
n = randint(1, 100)
print(n)
for i in range(n):
    n = randint(1, 10**5)
    S = randint(n, 10**9)
    k = randint(0, n-1)
    print(n, S, k)

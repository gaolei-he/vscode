from random import randint
n, q = randint(1, 10**5*2), randint(1, 10**5*2)
print(n, q)
for i in range(n):
    print(randint(-10**9, 10**9), end=' ')
print()
for i in range(q):
    print(randint(1, n))
from random import randint
n = randint(1, 50)
print(n)
for i in range(n):
    print(randint(1, 10 ** 3), end=" ")
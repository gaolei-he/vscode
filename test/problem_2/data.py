from random import randint
n = randint(1, 10**5)
print(n)
data = 'abcedfghijklmnopqrstuvwxyz'
for _ in range(n):
    ai = [data[randint(0, 25)] for _ in range(randint(1, 10))]
    bi = [data[randint(0, 25)] for _ in range(randint(1, 10))]
    print(''.join(ai), ''.join(bi))
q = randint(1, 10**5)
print(q)
for _ in range(q):
    s = [data[randint(0, 25)] for _ in range(randint(1, 10))]
    print(''.join(s))

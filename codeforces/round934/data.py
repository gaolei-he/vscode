from random import randint
print(1)
n = randint(10, 30)
q = randint(10, 30)
print(n, q)
for i in range(n):
    print("ab"[randint(0, 1)], end="")
print()
for i in range(q):
    l = randint(1, n)
    r = randint(l, n)
    print(l, r)

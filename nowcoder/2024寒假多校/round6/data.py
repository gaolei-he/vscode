from random import randint
n, m, q = randint(1, 10), randint(1, 10), randint(1, 10)
print(n, m, q)
data = "red"
for i in range(n):
    for j in range(m):
        print(data[randint(0, 2)], end="")
    print()
for i in range(q):
    x1, y1 = randint(1, n), randint(1, m)
    x2, y2 = randint(x1, n), randint(y1, m)
    print(x1, y1, x2, y2)

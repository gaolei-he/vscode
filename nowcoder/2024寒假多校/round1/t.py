n = 10**5
from random import randint
def check(x, y, r)->bool:
    if x + r <= 100 and x - r >= -100 and y + r <= 100 and y - r >= -100:
        return True
    return False
print(100000)
for _ in range(n):
    x, y = randint(-99, 99), randint(-99, 99)
    while True:
        r = randint(1, 100)
        if check(x, y, r):
            print(x, y, r)
            break



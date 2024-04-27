from random import randint
length = randint(1, 10**6*2)
b = randint(1, 10**9)
data = "0123456789"
a = [data[randint(1, 9)]]
for _ in range(length - 1):
    a.append(data[randint(0, 9)])
print(''.join(a), b)
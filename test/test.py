from random import random
t = int(input())
for _ in range(t):
    n = int(random() * 100000)
    filename = './' + str(_ + 1) + '.in'
    file = open(filename, 'w')
    file.write(str(n) + '\n')
    for i in range(n):
        file.write(str(int(random() * 100000)) + ' ')
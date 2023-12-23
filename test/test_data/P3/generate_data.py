from random import randint
import subprocess
t = int(input())
for _ in range(t):
    file = open('./data/' + str(_ + 1) + '.in', 'w')

    n = randint(0, 1000)
    file.write(str(n) + '\n')

    for i in range(n):
        for j in range(3):
            x = randint(0, n)
            file.write(str(x) + '.')
        file.write(str(randint(0, max(280, n))) + '\n')
    file.close()

    subprocess.run('./a.out', stdin=open('./data/' + str(_ + 1) + '.in', 'r'), stdout=open('./data/' + str(_ + 1) + '.out', 'w'))


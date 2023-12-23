from random import randint
from random import shuffle
import subprocess

t = int(input()) # number of test cases

data = '0123456789abcdef'
for i in range(t):
    n = randint(1, 1000)
    array = []

    cnt = randint(1, n)
    for j in range(cnt):
        tmp = ''
        for k in range(64):
            tmp += data[randint(0, 15)]
        array.append(tmp)
    for j in range(n - cnt):
        array.append(array[randint(0, cnt - 1)])
    
    shuffle(array)
    file = open('./data/' + str(i + 1) + '.in', 'w')
    file.write(str(n) + '\n')
    for x in array:
        file.write(x + '\n')
    file.close()


    subprocess.run(['./a.out'], stdin=open('./data/' + str(i + 1) + '.in', 'r'), stdout=open('./data/' + str(i + 1) + '.out', 'w'))
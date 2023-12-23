from random import randint
import subprocess

n = int(input()) # number of test cases
for i in range(n):
    file = open('./data/' + str(i + 1) + '.in', 'w')
    querys = randint(1, 1000)
    file.write(str(querys) + '\n')
    array = []
    for j in range(querys):
        array.append((randint(1, querys), randint(1, 6)))
    array.sort()
    for x, y in array:
        file.write(str(x) + ' ' + str(y) + '\n')
    file.close()

    subprocess.run(['./a.out'], stdin=open('./data/' + str(i + 1) + '.in', 'r'), stdout=open('./data/' + str(i + 1) + '.out', 'w'))


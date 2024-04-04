from random import randint, shuffle
file1 = open('in1.txt', 'w')
file1.write('1\n')
n = randint(8, 16)
x = randint(2, n)
y = randint(0, n - x)
file1.write(str(n) + ' ' + str(x) + f' {y}\n')
data = [i for i in range(1, n + 1)]
shuffle(data)
for i in range(x):
    file1.write(str(data[i]) + ' ')
file1.write('\n')
file1.close()
from random import randint
import subprocess

data = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
st = set()
st.add('')
t = int(input())
for _ in range(t):
    n = randint(1, 1000)
    file = open('./data/' + str(_ + 1) + '.in', 'w')
    file.write(str(n) + '\n')

    for x in range(n):
        name = ''
        while name in st:
            name = ''
            for i in range(randint(1, 10)):
                name += data[randint(0, 51)]
        st.add(name)
        file.write(name + ' ' + str(randint(1, 1000)) + '\n')
    
    file.close()

    subprocess.run('./a.out', stdout=open('./data/' + str(_ + 1) + '.out', 'w'), stdin=open('./data/' + str(_ + 1) + '.in', 'r'))


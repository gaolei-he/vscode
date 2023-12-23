from random import randint
import subprocess

t = int(input())
for _ in range(t):
    with open('./data/' + str(_ + 1) + '.in', 'w') as file:
        n = randint(50, 200)
        file.write(str(n) + '\n')
        for i in range(n):
            ri, mi = randint(0, 1000), randint(0, 1000)
            pij = set()
            while len(pij) < ri:
                val = randint(1, 1000)
                if randint(1, 100) < 10:
                    val = randint(1, 10**9)
                pij.add(val)
            file.write(str(ri) + ' ' + str(mi) + ' ')
            pij = list(pij)
            for v in pij:
                file.write(str(v))
                file.write(' ' if v != pij[-1] else '\n')
            
            for j in range(mi):
                dij, uij, rij = randint(i-10, i), randint(1, 10**3), randint(1, 10**3)
                if randint(1, 100) < 10:
                    dij = randint(-10**5, i)
                if randint(1, 100) < 10:
                    uij = randint(1, 10**9)
                if randint(1, 100) < 10:
                    rij = randint(1, 10**9)

                file.write(str(dij) + ' ' + str(uij) + ' ' + str(rij) + '\n')
            
    with open('./data/' + str(_ + 1) + '.in', 'r') as file:
        with open('./data/' + str(_ + 1) + '.out', 'w') as file2:
            subprocess.run(['./a.out'], stdin=file, stdout=file2)
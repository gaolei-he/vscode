from math import factorial


for i in range(1, 101):
    ans = factorial(i*2) // factorial(i) // factorial(i)
    print('"', end='')
    print(ans//(i+1), end='')
    print('"', end='')
    print(', ', end='')
    if i % 10 == 0:
        print('')

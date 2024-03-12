from random import randint

n = randint(10, 20)
data_control = "CQR"
print(n)
data = "a"
def print_file():
    t = randint(1, 3)
    ans = ''
    for i in range(t):
        ans += "/"
        for j in range(randint(1, 1)):
            ans += data 
    print(ans, end=' ')


for i in range(n):
    op = data_control[randint(0, 2)]
    if op == 'C':
        print(op, end=' ')
        print_file()
        print(randint(1, 1000))
    elif op == 'Q':
        print(op, end=' ')
        print_file()
        print(randint(0, 1000), end=' ')
        print(randint(0, 1000))
    else:
        print(op, end=' ')
        print_file()
        print()

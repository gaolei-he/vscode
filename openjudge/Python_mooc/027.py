n = int(input())
for i in range(1, n):
    if n % i == 0:
        print(str(i)+" ", end='')
else:
    print(n)
n = int(input())
if n < 0:
    print('-', end='')
    n = -n
while n % 10 == 0:
    n //= 10
while n != 0:
    print(n%10, end='')
    n //= 10
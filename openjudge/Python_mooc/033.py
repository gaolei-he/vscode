n = int(input())
ans = ''
if n < 0:
    n = -n
    print('-', end='')
if n == 0:
    print('0')
else:
    while n:
        ans = str(n&1) + ans
        n >>= 1
    print(ans)

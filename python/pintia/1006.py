n = int(input())
a, i = [], 1
while i * i <= n:
    if n % i == 0:
        if i != 1:
            a.append(i)
        a.append(n // i)
    i += 1
a.sort()
ans, length = 0, 0
for num in a:
    tnum = num
    tmp = num
    while tmp <= n:
        if n % tmp == 0 and length < (num - tnum + 1):
            ans, length = tnum, num-tnum+1
        num += 1
        tmp = tmp * num
print(length)
for i in range(length):
    if i != 0:
        print('*', end='')
    print(i + ans, end='')
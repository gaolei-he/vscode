a, b = map(int, input().split())
for i in range(a, b+1):
    print('{0:>5}'.format(i), end='')
    if (i - a + 1) % 5 == 0:
        print('')
if (b - a + 1) % 5 != 0:
    print('')
print("Sum =", (a + b) * (b - a + 1) // 2)
for _ in range(int(input())):
    s = input()
    a = set(['abc', 'acb', 'cba', 'bac'])
    if s in a:
        print('YES')
    else:
        print('NO')
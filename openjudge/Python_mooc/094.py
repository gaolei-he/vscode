from logging import exception


dic = {'2':15, 'A': 14, 'K': 13, 'Q': 12, 'J': 11, 'h': 4, 's': 3, 'd': 2, 'c': 1}
def f(n):
    res = 0
    if n[1] in '2AKQJ':
        res += dic[n[1:]] * 10
    else:
        res += int(n[1:]) * 10
    res += dic[n[0]]
    return res

while True:
    try:
        s = input().split()
        s.sort(key=f)
        s.reverse()
        for i in s:
            print(i, end=' ')
        print()
    except Exception as e:
        # print(e)

        break
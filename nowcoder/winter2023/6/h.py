x = int(input())
l, r = map(int, input().split())
fenmu = r - l + 1
fenzi = x - l
if fenzi <= 0:
    print('0')
elif x > r:
    print('1')
else:
    print(fenzi/fenmu)
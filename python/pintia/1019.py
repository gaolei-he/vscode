a, b = map(int, input().split())
n = int(input())
c, d = 0, 0
while True:
    if a == -1:
        print("A")
        print(d)
        break
    elif b == -1:
        print('B')
        print(c)
        break
    i, j, k, l = map(int, input().split())
    if j == i + k and l != i + k:
        a -= 1
        c += 1
    elif j != i + k and l == i + k:
        b -= 1
        d += 1
d = [0 for i in range(50)]
d[0] = d[1] = 1
for i in range(2, 50):
    d[i] = d[i-1] + d[i-2]
for _ in range(int(input())):
    n, x, y = map(int, input().split())
    xp, yp = d[n], d[n+1]
    while True:
        yp -= xp
        if y > yp:
            y -= xp
        xp, yp = yp, xp
        x, y = y, x
        if xp == 1 and yp == 1:
            break
    if x == 1 and y == 1:
        print("YES")
    else:
        print("NO")
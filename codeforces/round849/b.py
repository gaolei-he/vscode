for _ in range(int(input())):
    n = int(input())
    string = input()
    x, y = 0, 0
    flag = False
    for c in string:
        if c == 'U':
            x += 1
        elif c == 'D':
            x -= 1
        elif c == 'L':
            y -= 1
        elif c == 'R':
            y += 1
        if x == 1 and y == 1:
            flag = True
    if flag:
        print("YES")
    else:
        print("NO")
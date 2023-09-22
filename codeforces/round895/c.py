def solve(x:int):
    if x < 4:
        print(-1)
        return
    elif x % 2 == 0:
        print(2, x - 2)
        return
    div = 3 
    while div * div <= x:
        if x % div == 0:
            print(x // div, x - x // div)
            return
        div += 2
    print(-1)

for _ in range(int(input())):
    l, r = map(int, input().split())
    if l == r:
        solve(l)
    elif r >= 4:
        print(2, r - r % 2 - 2)
    else:
        print(-1)
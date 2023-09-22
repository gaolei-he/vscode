dic = dict({1:5, 3:4, 5:3, 7:2, 9:1})
for _ in range(int(input())):
    maps = []
    for i in range(10):
        maps.append(input())
    ans = 0
    for x in range(10):
        for y in range(10):
            if maps[x][y] == 'X':
                v = max(abs(x * 2 - 9), abs(y * 2 - 9))
                ans += dic[v]
    print(ans)
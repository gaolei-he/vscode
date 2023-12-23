for _ in range(int(input())):
    s = input().strip()
    string = '1234567890'
    loc, ans = 0, 0
    for i in range(4):
        ans += abs(loc - string.index(s[i]))
        loc = string.index(s[i])
    print(ans + 4)
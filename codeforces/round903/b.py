for _ in range(int(input())):
    a, b, c = map(int, input().split())
    def calc(a:int, op:int)->bool:
        if a < op or a % op != 0:
            return -1
        return a // op - 1
    def check(a:int, b:int, c:int, op:int)->bool:
        ans = 0
        v = calc(a, op)
        if v == -1:
            return False
        ans += v
        v = calc(b, op)
        if v == -1:
            return False
        ans += v
        v = calc(c, op)
        if v == -1:
            return False
        ans += v
        if ans > 3:
            return False
        return True
    if check(a, b, c, a) or check(a, b, c, b) or check(a, b, c, c) or ((a + b + c) % 6 == 0 and check(a, b, c, (a + b + c) // 6)):
        print("YES")
    else:
        print("NO")
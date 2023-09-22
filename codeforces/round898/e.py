for _ in range(int(input())):
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    l, r = 1, 10**12
    def check(mid:int)->bool:
        sm = 0
        for v in a:
            if v < mid:
                sm += mid - v
        return x >= sm
    while l < r:
        mid = (l + r + 1) // 2
        if check(mid):
            l = mid
        else:
            r = mid - 1
    print(l)
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    l, r = 0, 10**9+10
    def check(mid:int)->bool:
        lst = a[0]
        cnt = 1
        for v in a:
            if v - lst > mid * 2:
                lst = v
                cnt += 1
        return cnt <= 3


    while l < r:
        mid = l + r >> 1
        if check(mid):
            r = mid
        else:
            l = mid + 1
    print(l)
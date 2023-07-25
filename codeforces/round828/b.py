for _ in range(int(input())):
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    sm, odd, even = 0, 0, 0
    val = sum(a)
    for v in a:
        if v & 1:
            odd += 1
        else:
            even += 1
    for i in range(q):
        k, v = map(int, input().split())
        if k & 1:
            sm += odd * v
            if v & 1:
                even += odd
                odd = 0
        else:
            sm += even * v
            if v & 1:
                odd += even
                even = 0
        print(sm + val)
for _ in range(int(input())):
    n, k, q = map(int, input().split())
    a = list(map(int, input().split()))
    vec = []
    val = 0
    for v in a:
        if v <= q:
            val += 1
        else:
            vec.append(val)
            val = 0
    vec.append(val)
    val = 0
    for v in vec:
        if v - k < 0:
            continue
        val += (1 + v - k + 1) * (v - k + 1) // 2
    print(val)
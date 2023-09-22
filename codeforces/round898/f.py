for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    h = list(map(int, input().split()))
    l, r = -1, -1
    query = []
    for i in range(n - 1):
        val = h[i] % h[i + 1]
        if val == 0:
            r = i + 1
        if val == 0 and l == -1:
            l = i
        if val != 0 and l != -1:
            query.append((l, r))
            l = r = -1
    if l != -1:
        query.append((l, r))
    ans = 0
    if a[0] <= k:
        ans = 1
    for i in range(1, n):
        if a[i] <= k:
            ans = 1
        a[i] += a[i - 1]
    for tmp, y in query:
        for x in range(tmp, y + 1):
            l, r = x, y
            val = 0
            if l != 0:
                val = a[l - 1]
            while l < r:
                mid = (l + r + 1) // 2
                if a[mid] - val > k:
                    r = mid - 1
                else:
                    l = mid
            if a[l] - val > k:
                continue
            ans = max(ans, l - x + 1)
    print(ans)
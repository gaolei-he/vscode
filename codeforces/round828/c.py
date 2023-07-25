for _ in range(int(input())):
    n, now = input().split()
    n = int(n)
    s = input()
    ans = []
    for i, v in enumerate(s):
        if v == 'g':
            ans.append(i + 1)
            ans.append(i + 1 + n)
    res = -1
    ans.sort()
    for i, v in enumerate(s):
        if v == now:
            l, r = 0, len(ans) - 1
            while l < r:
                mid = (l + r) // 2
                if ans[mid] < i + 1:
                    l = mid + 1
                else:
                    r = mid
            # print(ans[l], i + 1)
            res = max(res, ans[l] - i - 1)
    print(res)
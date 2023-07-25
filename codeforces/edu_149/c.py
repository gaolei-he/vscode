for _ in range(int(input())):
    s = input()
    ans = ['0' for i in range(len(s))]
    for i, v in enumerate(s):
        if v == '?' and i > 0 and s[i - 1] == '1':
            ans[i] = '1'
        elif v == '?' and i > 0 and s[i - 1] == '0':
            ans[i] = '0'
        elif v == '?' and i > 0 and s[i - 1] == '?':
            ans[i] = ans[i - 1]
        elif v == '?' and i == 0:
            ans[i] = '0'
        else:
            ans[i] = v
    # print(*ans, sep = '')
    for i, v in enumerate(reversed(s)):
        i = len(s) - i - 1
        if ans[i] == '1':
            continue
        if v == '?' and i < len(s) - 1 and s[i + 1] == '1':
            ans[i] = '1'
        elif v == '?' and i < len(s) - 1 and s[i + 1] == '0':
            ans[i] = '0'
        elif v == '?' and i < len(s) - 1 and s[i + 1] == '?':
            ans[i] = ans[i + 1]
        elif v == '?' and i == len(s) - 1:
            ans[i] = '0'
        else:
            ans[i] = v
    print(*ans, sep = '')
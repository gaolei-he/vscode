dic = {0:'', 1:'T', 2:'B', 3:'K'}
dic1 = {0:'', 1:'W', 2:'Y'}
for _ in range(int(input())):
    s = input()[::-1]
    ans = []
    for i in range(len(s)-1, -1, -1):
        if len(ans) > 0 and ans[-1] != '0' and s[i] == '0':
            ans.append(s[i])
        elif s[i] != '0':
            ans.append(s[i])
        if s[i] != '0':
            ans.append(dic[i % 4])
        if i % 4 == 0:
            ans.append(dic1[i // 4])
    for i in range(len(ans)):
        if (ans[i] == 'Y' or ans[i] == 'W') and i - 1 >= 0 and ans[i-1] == '0':
            ans[i-1] = ''
    ans1 = []
    for v in ans:
        if v != '':
            ans1.append(v)
    while len(ans1) > 0 and ans1[-1] == '0':
        ans1.pop()
    for i in range(len(ans1)):
        if ans1[i] == 'W' and ans1[i-1] == 'Y':
            if i == len(ans1) - 1:
                ans1[i] = ''
            else:
                ans1[i] = '0'

    for v in ans1:
        print(v, end='')
    if len(ans1) == 0:
        print(0, end='')
    print()
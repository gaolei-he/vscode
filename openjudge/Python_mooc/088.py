import re


n = int(input())
pat = '<[1-9][0-9]{0,2}>|<0>'
while True:
    try:
        s = input()
        ans = re.findall(pat, s)
        if len(ans) > 0:
            for i in ans:
                print(i[1:-1],end=' ')
            print()
        else:
            print("NONE")
    except:
        break
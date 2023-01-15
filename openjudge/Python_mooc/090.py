import re

n = int(input())
pat = '<([a-z]{1,})>(.*?)</\\1>'
pat1 = '\((\d{1,2})\)-(\d{3,})'
while n != 0:
    n -= 1

    s = input()
    ans = re.findall(pat, s)

    myflag = True

    for i in ans:
        s = i[1]
        tmp = re.findall(pat1, s)
        


        ans1 = []
        for j in tmp:
            if len(j[1]) == 3:
                ans1.append(j)
        # for j in ans1:
        #     print(j[0], end=',')
        if len(ans1) > 0:
            print(f"<{i[0]}>",end='')
            print(ans1[0][0], end='')
            for j in range(1, len(ans1)):
                print(',', end='')
                print(ans1[j][0], end='')
            print(f"</{i[0]}>")

            myflag = False
    if myflag:
        print("NONE")
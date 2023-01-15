import re
try:
    while True:
        s = input()
        pat = '\d+\.\d+\.\d+\.\d+$'
        s = re.split('[^0-9.]', s)
        for i in s:
            ans = re.match(pat, i)
            if ans:
                tmp = ans.group()
                tmp = tmp.split('.')
                myflag = True
                for j in tmp:
                    if (len(j) > 1 and j[0] == '0') or int(j) > 255:
                        myflag = False
                if myflag:
                    print(ans.string)
except:
    pass
    

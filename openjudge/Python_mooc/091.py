import re


pat = '<([a-zA-Z]{1,})>(.*?)</\\1>'
pat1 = '%([^%]+)%([a-zA-Z0-9_]{1,7}@(stu\.)?pku\.edu\.cn)'
while True:
    try:
        
        myflag = True
        s = input()
        print('----')
        s = re.findall(pat, s)
        s = list(map(lambda x:x[1], s))
        # print(s)
        for i in s:
            ans = re.findall(pat1, i)
            if ans == None:
                break
            for j in ans:
                print(j[0]+' '+j[1])
                myflag = False
            
        if myflag:
            print("NONE")
    except Exception as e:
        # print(e)
        break
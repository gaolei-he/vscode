import re


pat = '\$[1-9][0-9]{0,2}(,[0-9]{3}){0,}\$'
while True:
    try:
        s = input()
        if re.search(pat, s) != None:
            print("yes")
        else:
            print("no")
    except:

        break
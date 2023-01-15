import re
m = '[a-zA-Z][A-Za-z0-9_-]{7,}$'

while True:
    try:
        s = input()
        if re.match(m,s) != None:
            print("yes")
        else:
            print("no")
    except:
        break
import re

m = '[0-9][0-9]*'

while True:
    try:
        s = input()
        lst = re.findall(m, s)
        for x in lst:
            print(x)
    except:
        break
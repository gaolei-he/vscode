import datetime
import re

st = datetime.date(2000, 1, 1)
while True:
    try:
        s = input()
        pat = '[0-9][0-9][0-9][0-9]-[0-9][0-9]-[0-9][0-9]', '[0-9][0-9]/[0-9][0-9]/[0-9][0-9][0-9][0-9]'
        try:
            if re.match(pat[0], s):
                s = s.split('-')
                dt = datetime.date(int(s[0]), int(s[1]), int(s[2]))
                days = dt - st
                print(days.days)
            elif re.match(pat[1], s):
                s = s.split('/')
                dt = datetime.date(int(s[2]), int(s[0]), int(s[1]))
                days = dt - st
                print(days.days)
            else:
                print('Error')
        except:
            print('Error')
    except:
        break
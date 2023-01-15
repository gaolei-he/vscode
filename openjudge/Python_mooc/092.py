import datetime
import re
pat = ' |-|:'
try:
    while True:

        st = input()
        st = re.split(pat, st)
        be = ''
        if len(st) == 5:
            st = list(map(int, st))
            be = datetime.datetime(st[0], st[1], st[2], st[3], st[4], 0)
        else:
            if st[5][0] == 'P':
                st[3] = int(st[3]) + 12
            st.pop()
            st = list(map(int, st))
            be = datetime.datetime(st[2], st[0], st[1], st[3], st[4], 0)
        st = input().split()
        pa = ''
        if len(st) > 1:
            pa = 1440 * int(st[0]) + 60 * int(st[1]) + int(st[2])
            pa *= 60
        else:
            pa = int(st[0])
        ans = be + datetime.timedelta(seconds=pa)

        print(ans)

except Exception as e:
    # print(e)
    pass
s, s1, s2 = input().split(',')
t1 = s.find(s1)
t2 = s.rfind(s2)
if t1 == -1 or t2 == -1 or t1 + len(s1) > t2:
    print('-1')
else:
    print(t2 - t1 - len(s1))
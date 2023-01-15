from re import X


cnt = 1
r = []
ans = []
for i in range(1, 100):
    ans.append(0)
for i in range(1, 10):
    r.append(True)
s1, s2 = [], []
for i in range(1, 17):
    s1.append(True)
    s2.append(True)
def myprint():
    for i in range(1, 9):
        for j in range(1, 9):
            print(ans[(i-1)*8+j], end=' ')
        print()
def f(a):
    global cnt
    if a > 8:
        print(f"No. {cnt}")
        cnt += 1
        myprint()
    else:
        for i in range(1, 9):
            t1 = a + i - 1
            t2 = 8 - a + i
            if r[i] and s1[t1] and s2[t2]:
                r[i] = s1[t1] = s2[t2] = False
                ans[(i-1)*8+a] = 1
                f(a+1)
                r[i] = s1[t1] = s2[t2] = True
                ans[(i-1)*8+a] = 0
f(1)
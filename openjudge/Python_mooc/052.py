ans = []
n = int(input())
c = []
for i in range(0, n):
    c.append(True)
s1, s2 = [], []
for i in range(0, 2*n):
    s1.append(True)
    s2.append(True)
def myprint():
    for i in ans:
        print(i, end=' ')
    print()
ret = True
def f(k):
    if k == n:
        myprint()
        global ret
        ret = False
    else:
        for i in range(0, n):
            t1 = k + i
            t2 = n - 1 - i + k
            if s1[t1] and s2[t2] and c[i]:
                s1[t1] = s2[t2] = c[i] = False
                ans.append(i)
                f(k+1)
                ans.remove(i)
                s1[t1] = s2[t2] = c[i] = True
f(0)
if ret:
    print("NO ANSWER")
res = 0
ans = []
def f(cnt, k):
    global a, res
    if k == a:
        res += 1
    else:
        if k > a:
            return
        else:
            for i in range(cnt, len(ans)):
                f(i, k*ans[i])
n = int(input())
a = 0
for i in range(n):
    a = int(input())
    for j in range(2, a + 1):
        if a % j == 0:
            ans.append(j)
    f(0, 1)
    print(res)
    ans.clear()
    res = 0
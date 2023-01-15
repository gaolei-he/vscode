import datetime
a = input()
b = input()
st = datetime.datetime(int(a[0:4]), int(a[4:6]), int(a[6:]))
ed = datetime.datetime(int(b[0:4]), int(b[4:6]), int(b[6:]))
delta = datetime.timedelta(days=1)
ans = 0
def isHui(s):
    for i in range(8):
        if s[i] != s[7-i]:
            return False
    return True
def f(k):
    k1 = k
    k %= 100
    k = k % 10 * 10 + k // 10
    k1 //= 100
    k1 = k1 % 10 * 10 + k1 // 10
    if k1 > 31:
        return True
    if k >=1 and k <= 12:
        return False
    return True

while st < ed:

    if f(st.year):
        try:
            st = datetime.datetime(st.year+1, 1, 1)
        except:
            break
        continue
    s = st.strftime("%Y%m%d")
    if isHui(s):
        ans += 1
    st += delta
if isHui(ed.strftime("%Y%m%d")):
    ans += 1
print(ans)
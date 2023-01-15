s = input()
n = len(s)
ans = []
st = []
for i in range(n):
    st.append(True)
def f(cnt):
    if cnt == n:
        for i in ans:
            print(s[i], end='')
        print()
        return
    for i in range(n):
        if st[i]:
            st[i] = False
            ans.append(i)
            f(cnt+1)
            st[i] = True
            ans.pop()
f(0)

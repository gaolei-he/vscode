n = int(input())
s = input()
st = set({'A', 'B', 'C'})
for i, c in enumerate(s):
    if c in st:
        st.remove(c)
    if len(st) == 0:
        print(i + 1)
        break
n = int(input())
s = input()
st = set()
x, y = 0, 0
st.add((x, y))
for c in s:
    if c == 'R':
        x += 1
    elif c == 'L':
        x -= 1
    elif c == 'U':
        y += 1
    elif c == 'D':
        y -= 1
    if (x, y) in st:
        print('Yes')
        exit()
    st.add((x, y))
print('No')
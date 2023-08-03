n = int(input())
s = input()
flag = False
for c in s:
    if c == '(':
        flag = True
    elif c == ')':
        flag = False
    if c == ',' and flag:
        print('.', end='')
    else:
        print(c, end='')
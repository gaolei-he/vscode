n, na, nb = input().split()
cnt1, cnt2 = 0, 0
sa = input().split()
sb = input().split()
for i in range(int(n)):
    if sa[i % int(na)] == '0':
        if sb[i % int(nb)] == '2':
            cnt1 += 1
        elif sb[i % int(nb)] == '5':
            cnt2 += 1
    elif sa[i % int(na)] == '2':
        if sb[i % int(nb)] == '5':
            cnt1 += 1
        elif sb[i % int(nb)] == '0':
            cnt2 += 1
    else:
        if sb[i % int(nb)] == '0':
            cnt1 += 1
        elif sb[i % int(nb)] == '2':
            cnt2 += 1
if cnt1 > cnt2:
    print('A')
elif cnt1 < cnt2:
    print('B')
else:
    print('draw')
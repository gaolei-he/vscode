h, m = map(int, input().split(':'))
if h >= 0 and h < 12 or h == 12 and m == 0:
    print('Only %02d:%02d.  Too early to Dang.' % (h, m))
else:
    ans = h - 12
    if m != 0:
        ans += 1
    print('Dang' * ans)
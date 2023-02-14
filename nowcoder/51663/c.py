from math import fabs
xa, ya, xb, yb = map(int, input().split())
ans = 0
if xa * xb <= 0:
    ans += 1
if ya * yb <= 0:
    ans += 1
try:
    if xa == 0 and ya == 0 or xb == 0 and yb == 0:
        ans -= 1
    if fabs(ya/xa - yb/xb) < 1e-4 and ans == 2:
        ans -= 1
except:
    pass
print(ans)
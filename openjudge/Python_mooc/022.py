n = float(input())
if 0 <= n < 5:
    print("%.3f" % (2.5-n))
elif 5 <= n < 10:
    print("%.3f" % (2-1.5*(n-3)*(n-3)))
else:
    print("%.3f" % (n/2-1.5))
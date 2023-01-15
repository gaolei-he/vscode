n = input().split()
x, a, b, c, d = float(n[0]), float(n[1]), float(n[2]), float(n[3]), float(n[4])
print("%.7f" % float(a*x*x*x+b*x*x+c*x+d))
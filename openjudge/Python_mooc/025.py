from math import sqrt


n = input().split()
a, b, c = float(n[0]), float(n[1]), float(n[2])
if round(b*b) == round(4*a*c):
    ans = -b/2/a
    if round(ans, 6) == 0:
        ans = 0.0
    print("x1=x2=%.5f" % ans)
elif round(b*b, 5) > round(4*a*c, 5):
    delta = sqrt(b * b - 4 * a * c)
    x1 = (-b - delta) / 2 / a
    x2 = (-b + delta) / 2 / a
    if x1 < x2:
        x1, x2 = x2, x1
    if round(x1, 6) == 0:
        x1 = 0.0
    if round(x2, 6) == 0:
        x2 = 0.0
    print("x1=%.5f;x2=%.5f" % (x1, x2))
else:
    shi = -b / (2 * a)
    if round(shi, 6) == 0:
        shi = 0.0
    xu = sqrt(4*a*c-b*b)/(2*a)
    if xu < 0:
        xu = -xu
    print("x1=%.5f+%.5fi;x2=%.5f-%.5fi" % (shi, xu, shi, xu))
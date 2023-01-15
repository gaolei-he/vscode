n = input().split()
a, b, c = int(n[0]), int(n[1]), int(n[2])
if a+b>c and a+c>b and b+c>a:
    print("yes")
else:
    print("no")
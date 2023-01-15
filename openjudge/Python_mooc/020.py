n = input().split()
x, y = int(n[0]), int(n[1])
if -1 <= x <= 1 and -1 <= y <= 1:
    print("yes")
else:
    print("no")
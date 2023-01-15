ans = input().split()
n, x, y = int(ans[0]), int(ans[1]), int(ans[2])
if n < y/x:
    print("0")
elif -0.0001 < y/x - y//x < 0.0001:
    print(n-y//x)
else:
    print(n-y//x-1)
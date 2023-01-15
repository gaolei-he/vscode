n = input().split()
h, r = int(n[0]), int(n[1])
ans = 20000 / 3.14159 / r / r / h
ans += 0.000001
if -0.0001 < ans - int(ans) < 0.0001:
    print(int(ans))
else:
    print(int(ans)+1)
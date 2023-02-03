a, b = map(int, input().split())
if b < 0:
    print(-abs(a))
else:
    print(abs(a))
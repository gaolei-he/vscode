n = input().split()
cnt = 0
for i in range(int(n[0]), int(n[1])+1):
    while i != 0:
        if i % 10 == 2:
            cnt += 1
        i //= 10
print(cnt)
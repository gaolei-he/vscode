arr = input().split()
n, m = int(arr[0]), int(arr[1])
sum = 0
for i in range(1, n):
    for j in range(i+1, n+1):
        if m % (i+j) == 0:
            print(i, j)
            sum += 1
print(sum)
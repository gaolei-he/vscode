p = int(input())
sum = 0
for i in range(1, p):
    sum += pow(i, p-2, p)
print(sum)
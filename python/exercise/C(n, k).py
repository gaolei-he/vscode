n = int(input())
k = int(input())
sum1 = 1
sum2 = 1
for i in range(1, k+1):
    sum1 *= i
for i in range(n, n-k, -1):
    sum2 *= i
print(sum2/sum1)

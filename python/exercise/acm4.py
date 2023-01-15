n = int(input())
ans = 0

while(n!=0):
    sum1 = 1
    for i in range(1, n+1):
        sum1 = sum1 * i
    ans = ans + sum1
    n = n - 1
print(ans)

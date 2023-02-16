n = int(input())
a = list(map(int, input().split()))
ans = n * (n - 1)
num = [0 for i in range(2*10**5+5)]
for i in a:
    while i % 2 == 0:
        i //= 2
    while i % 5 == 0:
        i //= 5
    num[i] += 1
for i in range(1, 2*10**5+1):
    for j in range(i+i, 2*10**5+1, i):
        ans -= num[i] * num[j]
for i in range(1, 2*10**5+1):
    ans -= num[i] * (num[i] - 1)
print(ans)
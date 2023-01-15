n = int(input())
a, b = list(map(int, input().split())), list(map(int, input().split()))
for i in range(0, len(a)):
    a[i] = a[i] * b[i]
print(sum(a))
n = int(input())
a = list(map(int, input().split()))
a.sort()
a = a[n:4*n]
print(sum(a) / len(a))
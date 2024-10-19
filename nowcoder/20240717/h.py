n = int(input())
arr = list(map(int, input().split()))
print(sum(arr) + max(max(arr) * n, max(arr) + n) - max(arr))
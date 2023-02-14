n = int(input())
print(n*(n-1)*pow(2, n-2, int (1e9+7))%int(1e9+7))
n = int(input())
print((n*(n-1)*6-n*6) * pow(n*(n-1), int(1e9+5), int(1e9+7)) % int(1e9+7))
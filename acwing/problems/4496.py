from math import factorial
n, m, k = map(int, input().split())
print(factorial(n-1) * m * ((m-1)**k) // factorial(n-1-k) // factorial(k) % 998244353)
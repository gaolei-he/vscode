n = int(input())
a = 1
b = 1
ans = 1
for i in range(2, n+1):
    ans = a + b
    b = a
    a = ans
print(ans)
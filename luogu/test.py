sum = 1000
ans = 0
for i in range(0, 11):
    ans += (sum - i * 100) * 0.029
print(ans)
n = int(input())
sum = 0
for i in range(1, n+1):
    sum += int(input())
print(str(sum)+' ', end='')
print('{0:0.5f}'.format(sum/n))
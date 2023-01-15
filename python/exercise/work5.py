num = 0
n = input()
for i in range(1, int(n)):
    num += str(i).count('2')
print(num)
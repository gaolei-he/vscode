n = int(input())
lists = []
a = int(input())
b = int(input())
c = int(input())
for i in range(1, n+1):
    if (i % a != 0 and i % b != 0) and i % c != 0:
        lists.append(i)
print(lists)
        
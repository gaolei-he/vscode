p = int(input())
n = int(p/2)
x = input()
lists = x.split(' ')
one = 0
two = 0
for i in range(n):
    if lists[0] > lists[-1]:
        a = int(lists.pop(0))
    else:
        a = int(lists.pop(-1))
    one += a
    if lists[0] > lists[-1]:
        a = int(lists.pop(0))
    else:
        a = int(lists.pop(-1))
    two += a
if one > two:
    print('YES')
else:
    print('NO')
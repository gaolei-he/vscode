n = int(input())
ans = []
while n != 0:
    try:

        n -= 1
        ans.append(input().split())
        ans.sort(key=lambda x:[-int(x[1]),x[0]])
    except Exception as e:
        print(e)
for i in ans:
    print(i[0]+' '+i[1])
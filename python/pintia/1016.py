n = int(input())
ans = []
w = [7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2]
dic = {0:'1', 1:'0', 2:'X', 3:'9', 4:'8', 5:'7', 6:'6', 7:'5', 8:'4', \
    9:'3', 10:'2'}
for tmp in range(n):
    tmp = input()
    m = tmp[-1]
    s = tmp[0:-1]
    z = 0
    for i, j in zip(w, s):
        try:
            z += i * int(j)
        except:
            z = -1
            break
    if z < 0:
        ans.append(tmp)
        continue
    z %= 11
    if dic[z] != m:
        ans.append(tmp)
if len(ans) == 0:
    print('All passed')
else:
    for i in ans:
        print(i)
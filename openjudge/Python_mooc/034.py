ans = []
try:
    while True:
        n = input().split()
        for i in n:
            ans.append(int(i))

except:
    ans.sort()
    ans.reverse()
    print(ans[0])
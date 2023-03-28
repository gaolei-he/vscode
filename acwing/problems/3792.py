prime = [True for i in range(1010)]
for i in range(2, 1002):
    for j in range(i+i, 1002, i):
        prime[j] = False
ans = []
for i, v in enumerate(prime):
    if i >= 2 and v:
        ans.append(i)
for _ in range(int(input())):
    n, k = map(int, input().split())
    cnt = 0
    for i in range(len(ans)-1):
        if ans[i] + ans[i+1] + 1 <= n and prime[ans[i] + ans[i+1] + 1]:
            cnt += 1
    if k <= cnt:
        print("YES")
    else:
        print("NO")
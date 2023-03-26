def solve():
    n = int(input())
    s = input()
    dic = {}
    for i, c in enumerate(s):
        dic[c] = dic.get(c, [])
        dic[c].append(i)
    for k, v in dic.items():
        for i in range(len(v)-1):
            if (v[i+1] - v[i]) % 2 == 1:
                print("NO")
                return
    print("YES")
for _ in range(int(input())):
    solve()

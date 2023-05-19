h1 = [0 for i in range(60)]
h2 = [0 for i in range(60)]
mod = 2**64
p = [131**i%mod for i in range(60)]
for _ in range(int(input())):
    s = input()
    tmp = ' ' + s
    for i in range(1, len(tmp)):
        h1[i] = (h1[i-1]*131 + ord(tmp[i])) % mod
        h2[i] = (h2[i-1]*131 + ord(tmp[-i])) % mod
    ans = -1
    for i in range(len(tmp)-1, 0, -1):
        for j in range(1, len(tmp) - i):
            v1 = (h1[j+i-1] - h1[j-1] * p[i] + mod) % mod
            v2 = (h2[len(tmp)-j] - h2[len(tmp)-j-i] * p[i] + mod) % mod
            if v1 != v2:
                ans = max(ans, i)
                break
    print(ans)
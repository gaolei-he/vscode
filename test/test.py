x = int(input())
N, ans = 1000010, 0
sta = [True for i in range(N)]
def g():
    for i in range(2, N):
        for j in range(i+i, N, i):
            sta[j] = False
g()
def f(x:int)->int:
    for i in range(2, x//2+1):
        if sta[i] and sta[x-i]:
            return x - (i << 1)
while x >= 4:
    x = f(x)
    ans += 1
print(ans)
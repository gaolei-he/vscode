sg = [_ for _ in range(10001)]
for _ in range(int(input())):
    n = int(input())
    ans = 0
    def f(x):
        global ans
        ans ^= int(x)
    list(map(f, input().split()))
    print('Yes' if ans != 0 else 'No')

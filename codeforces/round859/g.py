from sys import stderr
def solve():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    sm = 0
    for i, x in enumerate(a):
        # print(sm, file=stderr)
        if i == 0 and x != 1:
            print("NO")
            return
        if i != 0 and sm < x:
            print("NO")
            return
        sm += x
    print("YES")
for _ in range(int(input())):
    solve()
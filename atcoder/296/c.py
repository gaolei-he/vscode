from sys import stderr
n, x = map(int, input().split())
a = set(map(int, input().split()))
# print(a, file=stderr)
ans = "No"
for v in a:
    if x + v in a:
        # print(x-v, file=stderr)
        ans = "Yes"
        break
print(ans)

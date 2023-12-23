n = int(input())
a = list(map(int, input().split()))
a.sort(reverse=True)
for v in a:
    if v != a[0]:
        print(v)
        break

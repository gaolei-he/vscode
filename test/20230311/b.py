a, b, c = map(int, input().split())
if b >= min(a, c) and b <= max(a, c):
    print('Yes')
else:
    print('No')
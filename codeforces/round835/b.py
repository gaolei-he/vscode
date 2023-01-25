t = int(input())
for i in range(t):
    n = int(input())
    s = input()
    s = sorted(s)
    # print(s)
    print(ord(s[-1]) - ord('a')+1)
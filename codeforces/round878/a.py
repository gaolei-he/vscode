for _ in range(int(input())):
    n = int(input())
    s = input()
    i = 1
    c = s[0]
    while i < n:
        if s[i] == c:
            print(c, end='')
            i += 1
            if i >= n:
                break
            c = s[i]

        i += 1
    print()
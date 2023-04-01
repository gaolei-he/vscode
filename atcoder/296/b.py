for i in range(8):
    s = input()
    for j, c in enumerate(s):
        if c == '*':
            print(chr(ord('a') + j) + str(8-i))
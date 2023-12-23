mod = 9982443530000000000000
for i in range(1, 1000):
    for j in range(1, 1000):
        if pow(i, j, mod) == pow(j, i, mod):
            if i != j:
                print(i, j)
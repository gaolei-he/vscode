from audioop import reverse


for i in range(49, 729):
    s1 = []
    s1.append(i//49)
    s1.append(i%49//7)
    s1.append(i%7)
    s2 = []
    s2.append(i//81)
    s2.append(i%81//9)
    s2.append(i%9)
    if s1 == s2[-1::-1]:
        print(i)
        for j in s1:
            print(j, end='')
        print()
        for j in s2:
            print(j, end='')
        print()
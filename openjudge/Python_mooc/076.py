tmp = input()
for i in range(2, len(tmp)+1):
    for j in range(0, len(tmp)-i+1):
        tmp1 = tmp[j:i+j]
        if tmp1[::-1] == tmp1:
            print(tmp1)
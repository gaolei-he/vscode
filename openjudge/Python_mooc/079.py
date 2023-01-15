ans = []
for i in range(5):
    ans.append(list(map(int, input().split())))

def mymin(op, i, j):
    if op == 1:
        for k in range(5):
            if ans[i][j] > ans[k][j]:
                return False
        return True
    else:
        for k in range(5):
            if ans[i][j] < ans[i][k]:
                return False
        return True

for i in range(5):
    for j in range(5):
        t = ans[i][j]
        if mymin(0, i, j) and mymin(1, i, j):
            print(i+1, j+1, t)
            exit(0)
print('not found')
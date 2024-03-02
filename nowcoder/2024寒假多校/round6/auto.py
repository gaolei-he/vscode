import subprocess
while True:
    subprocess.run("python3 data.py > data.txt", shell=True)
    subprocess.run("./my.out < data.txt > my.txt", shell=True)
    subprocess.run("./std.out < data.txt > std.txt", shell=True)
    tmp = open("std.txt", "r")
    file = open("data.txt", "r")
    t = int(file.readline())
    output = open("my.txt", "r")
    flag = False
    for i in range(t):
        n, S, k = map(int, file.readline().split())
        arr = list(map(int, output.readline().split()))
        tmp_arr = list(map(int, tmp.readline().split()))
        if arr[0] != tmp_arr[0] and min(tmp_arr[0], arr[0]) == -1:
            print(i + 1, "WA0")
            flag = True
            break
        if arr[0] == -1:
            continue
        if len(arr) != n or sum(arr) != S:
            print(i + 1, "WA1")
            flag = True
            break
        cnt = 0
        for j in range(n - 2):
            if arr[j] > arr[j+1] and arr[j] == arr[j + 2]:
                cnt += 1
        if cnt != k:
            print(i + 1, "WA2")
            flag = True
            break
    if flag:
        break

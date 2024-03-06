import subprocess
from random import randint
while True:
    v1, v2, v3 = randint(0, 3*343), randint(0, 3*343), randint(0, 3*343)
    data = open("data.txt", "w")
    data.write(f"{v1} {v2} {v3}\n")
    data.close()
    subprocess.run("./std.out < data.txt > std.txt", shell=True)
    subprocess.run("./my.out < data.txt > my.txt", shell=True)
    if subprocess.run("diff std.txt my.txt", shell=True).returncode != 0:
        print("WA")
        break

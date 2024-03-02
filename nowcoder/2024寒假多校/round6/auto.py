import subprocess
while True:
    subprocess.run("python3 data.py > data.txt", shell=True)
    subprocess.run("./my.out < data.txt > my.txt", shell=True)
    subprocess.run("./std.out < data.txt > std.txt", shell=True)
    if subprocess.run("diff my.txt std.txt", shell=True).returncode != 0:
        print("WA")
        break
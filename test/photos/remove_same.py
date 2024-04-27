import subprocess
import os

result = os.listdir('./photos')
store = set()
for idx, val in enumerate(result):
    suf = val.split('.')[-1]
    subprocess.run(f"mv ./photos/'{val}' ./photos/{idx}.{suf}", shell=True)
result = os.listdir('./photos')
for val in result:
    ans = subprocess.run("sha256sum ./photos/" + val, shell=True, capture_output=True)
    ans = ans.stdout.decode().split(' ')[0]
    if ans in store:
        subprocess.run("rm ./photos/" + val, shell=True)
    else:
        store.add(ans)

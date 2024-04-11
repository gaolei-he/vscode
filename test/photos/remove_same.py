import subprocess
import os

result = os.listdir('./valid')
store = set()
for val in result:
    ans = subprocess.run("sha256sum ./valid/" + val, shell=True, capture_output=True)
    ans = ans.stdout.decode().split(' ')[0]
    if ans in store:
        subprocess.run("rm ./valid/" + val, shell=True)
    else:
        store.add(ans)

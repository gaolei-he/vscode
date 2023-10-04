import subprocess
cmd = "echo 'scale=100; a(1) * 4' | bc -l "
file = open('text', 'w')
subprocess.run(cmd, shell=True, stdout=file)
file.close()

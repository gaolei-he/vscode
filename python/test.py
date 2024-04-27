import threading
from time import sleep

def f():
    for i in range(10):
        print(i)
        sleep(1)

for i in range(2):
    thread = threading.Thread(target=f)
    thread.start()
sleep(3)
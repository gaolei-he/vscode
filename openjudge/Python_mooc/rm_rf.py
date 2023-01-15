from genericpath import isfile
import os
path = input()
def rf(path):
    lst = os.listdir(path)
    for x in lst:
        realpath = path + '/' + x
        if os.path.isfile(realpath):
            os.remove(realpath)
        else:
            rf(realpath)
    os.rmdir(path)
rf(path)
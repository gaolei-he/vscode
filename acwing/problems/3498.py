from datetime import datetime

while True:
    try:
        a, b = input().strip(), input().strip()
        d1 = datetime(int(a[:4]), int(a[4:6]), int(a[6:8]))
        d2 = datetime(int(b[:4]), int(b[4:6]), int(b[6:8]))
        print(abs((d2 - d1).days) + 1)
    except:
        break

from xxlimited import Str


n = input()
if n[-1] in 'Cc':
    ans = float(n[0:-1]) * 1.8 + 32
    if -0.0001 < ans - int(ans+0.0000001) < 0.0001:
        print(str(int(ans+0.0000001)) + "F")
    else:
        print(str("%.2f" % ans) + "F")
    #print("F")
else:
    ans = ( float(n[0:-1]) - 32 ) / 1.8
    if -0.0001 < ans - int(ans+0.0000001) < 0.0001:
        print(str(int(ans+0.0000001))+"C")
    else:
        print(str("%.2f" % ans) + "C")
    #print("C")
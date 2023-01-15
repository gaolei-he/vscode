def f(n):
    if n==1:
        return 1
    elif n==2:
        return 2
    elif n==3:
        return 5
    else:
        return (f(n-1)*2+f(n-3))%10000
n = int(input())
print(f(n)%10000)
def f(n, src, mid, dst):
    if n==1:
        #print(n, end=' ')
        print(src+"->"+dst)
    else:
        f(n-1, src, dst, mid)
        #print(n, end=' ')
        print(src+"->"+dst)
        f(n-1, mid, src, dst)
n = int(input())
f(n, 'A', 'B', 'C')
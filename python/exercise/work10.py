a,b,p = map(int,input().split())
x=1
while b != 0:
    x=a*x
    b=b-1
n=x%p 
print(n)
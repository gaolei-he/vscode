n=int(input())
a,b,c=map(int,input().split())
sum=0
for x in range(n):
    if x%a!=0 and x%b!=0 and x%c!=0:
        sum+=1
print(sum)
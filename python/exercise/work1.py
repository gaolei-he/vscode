def prime(x):
    for i in range(2,x):
        if x%i==0:
            return False
        if i == x-1:
            return True 
output=filter(prime,range(2,1001))
print(list(output))
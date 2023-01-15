n = input().split()
if n[2] not in '+-*/':
    print("Invalid operator!")
elif n[2]=='/' and n[1]=='0':
    print("Divided by zero!")
else:
    print(int(eval(n[0]+n[2]+n[1])))
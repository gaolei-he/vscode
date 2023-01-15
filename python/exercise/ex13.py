from sys import argv
# read the WYSS section for how to run this
script, first, second, third = argv

print("The script is called:", script)
print(f'''Your first variable is : {first}
Your second variable is : {second}
Your third variable is : {third}
''')
x = int(input('age?'))
print(x*x)

def add(a, b):
    print(f'ADDING {a} + {b}')
    return a + b 

def subtract(a, b):
    print(f'SUBTRACTING {a} - {b}')
    return a - b 

def multiply(a, b):
    print(f'MULTIPLYING {a} * {b}')
    return a * b 

def divide(a, b):
    print(f'DIVIDING {a} / {b}')
    return a / b 

print('Let\'s do some math with just functions!')
x = int(input('Your age\n'))
y = int(input('Your girlfriend\'s age\n'))
age = divide(x, y)
x = int(input('Your height\n'))
y = int(input('Kanger\'s height\n'))
height = subtract(x, y)
# Let's do something simple.
weight = multiply(90, 2)
x = int(input('Your IQ?\n'))
y = int(input('Kanger\'s IQ?\n'))
iq = add(x, y)
print(f'Your IQ:{iq},height:{height},weight:{weight},IQ:{iq}')

# We will do something strange.
print("Here they are.")

what = add(age, subtract(height, multiply(weight, divide(iq, 2))))

print(f'That becomes: {what}. Can you do it by hand?')
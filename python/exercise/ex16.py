from sys import argv

script, filename = argv 

print(f"We're going to erase {filename}.")
print('''If you want this type 'y'. 
You can shut this program down by typing any key.''')

x = input('?')
if x == 'y':
    print("Opening the file....")
    target = open(filename, 'w')
    print('Truncating the file. Goodbye!')
    target.truncate()
    
    print('Now I\'m going to ask you for three lines.')
    line1 = input('line1: ')
    line2 = input('line2: ')
    line3 = input('line3: ')
    print('I\'m going to write these to the file.')
    target.write(line1)
    target.write('\n')
    target.write(line2)
    target.write('\n')
    target.write(line3)
    target.write('\n')
    
    print('And finally, we close it.')
    target.close()
else:
    print('We will do nothing to your flie, goodbye.')
    
#this script is written to open the file delete.bat
filename = input('type the filename which you want to open. \n>')
filea=open(filename, 'r')
print('This is your file.')
print(filea.read())


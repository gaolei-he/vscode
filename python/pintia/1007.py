s = input()
dic = {'-':'fu', '0':'ling', '1':'yi', '2':'er', '3':'san', '4':'si', \
       '5':'wu', '6':'liu', '7':'qi', '8':'ba', '9':'jiu'}
       
for i in range(len(s)):
    if i != 0:
        print('', end=' ')
    print(dic[s[i]], end='')
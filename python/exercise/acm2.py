x = input()
lists = x.split(' ')
if int(lists[0])+int(lists[1])+int(lists[2])<=4000000000:
    n = int(lists[0])**int(lists[1])%int(lists[2])
    print(n)

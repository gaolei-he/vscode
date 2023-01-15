print('''You enter a dark room with too doors.
Do you go through door 1 or door 2?''')

def function1():
    door = input('please type 1 or 2\n>')

    if door == '1':
        print('''There is a mad dog sitting in a 3990X
        whose cores number is 128''')
        print('What will you do?')
        print('1. Take 3990X away and set in your own computer.')
        print('2. Call Kanger and ask him to drive the dog away.')
    
        dog = input('please type 1 or 2\n>')
    
        if dog == '1':
            print('''Doing some dangerous things is risk,
            when you are trying to take 3990X away,
            the dog attacked you violently.''')
            print('You lost too much blood and died.')
            print('''Goodbye!
            Good luck to you next time.''')
            exit()
        elif dog == '2':
            print('Kanger has gotten the message.')
            print('A few minutes later, Kanger came with a tractor.')
            print('''Sadly, Kanger has nothing to do with the dog.
            Now You two guys are going to find a way together.''')
            
            way = input('''What you gonna do?
1. Directly take 3990X away together with Kanger.
2. Beat the dog and take both 3990X and the dog.''')
            if way = '1':
                print('Both you and Kanger are weak, you died and exit the game.')
                print('Goodbye')
                exit()
            elif way = '2':
                print('''You are making an impossible dream,
the dog won't let you do this, you chose the wrong option.
    Good luck to you next time.''')
                exit()
            else:
                print('syntax error, auto exit.')
                exit()
            
        else:
            print('The things you have done is useless.')
            print('The dog taken 3990X away and you got nothing.')
            print('''If you want to restart the game, type 'yes'
            or the game will come to an end.''')
        
            x = input('>')
        
            if x == 'yes':
                print('Let\'s begin.')
                function1()
            else:
                exit()
    elif door == '2':
        print('''Amazing! This place is Kanger's bedroom, 
        You found that Kanger's 1060 is on the bed.''')
        print('''What do you want to do?
        1. Take 1060 away and sold it on www.taobao.com
        2. Break it down to make Kanger say goodbye to his WeGame and Steam,
           So that he can focus on his study.(It seems impossible.)''')
        def function2():
            y = input('please type 1 or 2\n>')   
            if y =='1':
                print('''You sold Kanger's graphics card and make a small profit.
                You use the money buying a Kingston's SSD and set in your laptop.
                Great!''')
                exit()
            elif y == '2':
                print('''As expected, Kanger gets angry and wants to snatch your 4800H.
                You're afraid and get out from the house.''')
                print('''Finally, Kanger bought a 3090 and got more games.''')
                print('Game over!')
                quit()
            else:
                print('Syntax Error!')
                function2()
        function2()
    else:
        print('Man, type 1 or 2, OK?')   
        function1()
function1()
            
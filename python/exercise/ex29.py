def function():
    people = input('people\n>')
    cats = input('cats\n>')
    dogs = input('dogs\n>')
    if people < cats:
        print('Too many cats! The world is doomed!')
    elif people > cats:
        print('Not many cats! The world is saved!')
    else:
        print('please type a number')
        function()
function()

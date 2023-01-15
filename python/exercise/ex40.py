#coding:utf-8
class Song(object):

    def __init__(self, lyrics):
        self.lyrics = lyrics
        
    def sing_me_a_song(self):
        for line in self.lyrics:
            print(line)
            
happy_bday = Song(["Happy birthday to you",
                   "I don't want to get sued",
                   "So I'll stop right there"])
                   
bulls_on_parade = Song(["They rally around the family",
                        "With pockets full of shells"])

#只赋值给类中的变量                        
happy_bday.sing_me_a_song()

bulls_on_parade.sing_me_a_song()

#赋值给全局变量，不赋值给类

sing_me_a_song(happy_bday)

sing_me_a_song(bulls_on_parade)
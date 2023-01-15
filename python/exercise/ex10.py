#coding:utf-8
# \t 相当于按下Tab,输出内容空格
tabby_cat = "\tI'm tabbed in."
#\n 换行
persian_cat = "I'm split\non a line"
#\\这个转义符我并没有理解有什么用,\or\\效果貌似一样
backslash_cat = "I'm \ a \ cat."
fat_cat = '''
I'll do a list:
\t* Cat food
\t* Fishies
\t* Catnip\n\t* Grass
'''
#这个*10真有意思
print (tabby_cat *10)
print (persian_cat)
print (backslash_cat) 
print (fat_cat) 
#\"将"作为字符串的边界
print ("I am 6'2\" tall.")
#\'将'作为字符串的边界
#字符串内部含'再加个\即可
print ('I am 6\'2" 3\' tall.')
#interseting \a 响铃符

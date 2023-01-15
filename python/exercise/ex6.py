#coding:utf-8
#变量赋值
x = "There are %d types of people." % 10
binary = "binary"
do_not = "don't"
y = "Those who know %s and those who %s." % (binary, do_not)
#打印
print x
print y 
print "I said: '%s'." % y 
#变量赋值
hilarious = False
joke_evaluation = "Isn't that joke so funny?! %r"
#打印
print joke_evaluation % hilarious
w = "This is the left side of..."
e = "a string with a right side."
print w + e 
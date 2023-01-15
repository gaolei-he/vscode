#coding:utf-8
formatter = "%r %r %r %r"
print formatter % (1, 2, 3, 4)
print formatter % ("one", "two", "three", "four")
print formatter % (True, False, False, True)
print formatter % (formatter, formatter, formatter, formatter)
# 变量之间逗号隔开
# 第三个变量双引号内含单引号,不含的话输出便是单引号
print formatter % (
    "I had this thing.",
    "That type up right.",
    "But it didn't sing.",
    "So I said goodnight."
    )
    
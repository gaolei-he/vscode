#coding:utf-8
#任务:输出50-100以内能被9整除的数,输出50-100以内所有素数
#way1
i = 50
lists = []
while i != 100:
    x = i % 9
    if x == 0:
        lists.append(i)
    i = i + 1
print(lists)

#way2
lists = []
for i in range(50, 101):
    x = i % 9
    if x == 0:
        lists.append(i)
print(lists)
        
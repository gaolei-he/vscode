import sqlite3
db = sqlite3.connect('/home/mechrevo/Documents/files/test.db')
cur = db.cursor()
sql = 'select name, gpa, age from students where gpa > 3.0 order by age desc'
#查找gpa > 3.3 的记录，提取其中三个字段，按年龄降序排列
cur.execute(sql)
x = cur.fetchall()
if x != []:
    print('total: ', len(x))
    for r in x:
        print(r)
cur.close()
db.close()
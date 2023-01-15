import sqlite3
db = sqlite3.connect('/home/mechrevo/Documents/files/test.db')
cur = db.cursor()
sql = '''CREATE TABLE if not exists students (id integer primary
key, name text, gpa real, birthday date, age integer, picture
blob)'''
cur.execute(sql)
cur.execute("insert into students values(1600, '张三', 3.81, '2000-09-12', 18, null)")
mylist = [(1700, '李四', "3.25", '2001-12-01', 17, None), 
(1800, '王五', '3.25', '1999-01-01', 19, None)]
for s in mylist:
    cur.execute('INSERT INTO students VALUES(?,?,?,?,?,?)',
    (s[0], s[1], s[2], s[3], s[4], s[5]))
db.commit()
cur.close()
db.close()
import sqlite3
db = sqlite3.connect('/home/mechrevo/Documents/files/test.db')
cur = db.cursor()
sql = 'select * from students'
cur.execute(sql)
x = cur.fetchone()
print(x)
print(x[1])
for x in cur.fetchall():
    print(x)
cur.execute("SELECT * FROM students WHERE name='Jack'")
x = cur.fetchone()
if x == None:
    print("can't find Jack")
cur.close()
db.close()
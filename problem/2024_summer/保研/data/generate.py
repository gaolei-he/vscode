from random import randint
data = "abcdefghijklmnopqrstuvwxyz"

n = randint(50, 100)
print(n)
stu_name = set()
while len(stu_name) < n:
    name = "".join([data[randint(0, 25)] for j in range(randint(5, 20))])
    stu_name.add(name)
for name in stu_name:
    k = randint(20, 80)
    total_course = set()
    while len(total_course) < k:
        name = "".join([data[randint(0, 25)] for j in range(randint(5, 10))])
        total_course.add(name)
    
    print(k, name)

    for course in total_course:
        s2 = randint(1, 100)
        s3 = randint(1, 5)
        num = "".join([data[randint(0, 25)] for j in range(randint(5, 10))])
        if randint(1, 10) == 1:
            num = "tsk" + num
        flag = 0
        if randint(1, 5) == 1 and not num.startswith("tsk"):
            flag = 1
        print(course, s2, s3, num, flag)
    
    t = randint(1, 10)
    print(t, end=' ')
    for j in range(t):
        print(randint(1, 6), end=' ')
    print()
    print(randint(1, 500), randint(0, 2), randint(0, 1))
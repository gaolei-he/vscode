user_output = open('1.out')
output = open('../1.out')

ans = output.readlines()
user_ans = user_output.readlines()

if len(ans) != len(user_ans):
    exit(1)

for v1, v2 in zip(ans, user_ans):
    v1, v2 = v1.strip(), v2.strip()
    for i in range(8):
        if v1[i] != v2[i]:
            print('$', v1, v2)
            exit(1)
    for t1, t2 in zip(v1, v2):
        if t2 == '.' and t1 != '.':
            print('#', v1, v2)
            exit(1)

exit(0)

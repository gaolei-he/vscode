n = int(input())
s = input().strip()
dic = dict()
cnt, op = 1, '$'
for c in s:
    if c != op:
        dic[op] = max(dic.get(op, 0), cnt)
        op = c
        cnt = 1
    else:
        cnt += 1

dic[op] = max(dic.get(op, 0), cnt)
cnt = -1
for k, v in dic.items():
    cnt += v
print(cnt)
#统计单词频率，但不管出现在cet4列表中的单词
#python xxx.py a1.txt ans.txt
from opcode import opname
import re
import sys

dic = set([])
def CountWords(path, res):
    try:
        tmp = open(path, 'r', encoding='utf-8')
    except Exception as e:
        print(e)
        return -1
    txt = tmp.read()
    tmp.close()
    lst = re.split('[^a-zA-Z][^a-zA-Z]*', txt)
    for i in lst:
        i = i.strip()
        i = i.lower()
        if i in dic:
            continue
        res[i] = res.get(i, 0) + 1

tmp = open('cet4words.txt', 'r', encoding='utf-8')
txt = tmp.readlines()
tmp.close()

for i in txt:
    i = i.strip()
    if re.match('^\$.*', i):
        i = i[1::1]
        dic.add(i)
print(dic)
res = {}
tmp = open(sys.argv[2], 'w', encoding='utf-8')
CountWords(sys.argv[1], res)
lst = list(res.items())
lst.sort()
for i in lst:
    tmp.write('%s %d\n' % (i[0], i[1]))
tmp.close()

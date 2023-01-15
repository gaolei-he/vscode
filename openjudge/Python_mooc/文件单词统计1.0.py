#python xxx.py a1.txt ans.txt
#统计a1.txt文件中单次数量排序并记录到ans.txt中
import os
import re
import sys
def CountWords(path, res):
    try:
        tmp = open(path, 'r', encoding='utf-8')
    except Exception as e:
        print(e)
        return -1
    txt = tmp.read()
    txt.strip()
    tmp.close()
    lst = re.split('[^a-zA-Z][^a-zA-Z]*', txt)
    for i in lst:
        i = i.lower()
        res[i] = res.get(i, 0) + 1
res = {}
CountWords(sys.argv[1], res)
tmp = open(sys.argv[2], 'w', encoding='utf-8')
lst = list(res.items())
lst.sort()
for i in lst:
    tmp.write('%s %d\n' % (i[0], i[1]))
tmp.close()
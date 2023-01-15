#统计当前目录下以a开头以.txt结尾的文件单词频率，结果存ans.txt
#python3 xxx.py ans.txt
import os
import sys
import re
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
        i = i.lower()
        res[i] = res.get(i, 0) + 1

res = {}
lst = os.listdir()
for i in lst:
    if re.match('^a.*\.txt', i):
        CountWords(i, res)
tmp = open(sys.argv[1], 'w', encoding='utf-8')
lst = list(res.items())
lst.sort()
for i in lst:
    tmp.write('%s %d\n'%(i[0], i[1]))
tmp.close()
#统计txt文件中单词数量，遇到变形单词，变成原型后再统计
#python3 xxx.py a1.txt res.txt
import re
import sys

dic = {}
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
        if i in dic.keys():
            i = dic[i]
        res[i] = res.get(i, 0) + 1
tmp = open('word_varys.txt', 'r', encoding='utf-8')
txt = tmp.readlines()
tmp.close()
for i in range(0, len(txt), 2):
    val = txt[i].strip()
    key = txt[i+1].strip().split('|')
    for j in key:
        dic[j] = val
res = {}
CountWords(sys.argv[1], res)
tmp = open(sys.argv[2], 'w', encoding='utf-8')
lst = list(res.items())
lst.sort()
for i in lst:
    tmp.write('%s %d\n' % (i[0], i[1]))
tmp.close()
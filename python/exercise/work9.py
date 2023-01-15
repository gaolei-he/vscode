#coding:utf-8
lists = [0] * 26
s = input()
#记录字母出现个数
for i in s:
    lists[ord(i) - ord('a')] += 1
k = 0
#挨个比较找出最大值
for i in range(26):
    if lists[i] > lists[k]
        k = i 
print(chr(k + ord('a')))
print(lists[k])
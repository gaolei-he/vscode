n = int(input())
jige = 0
youxiu = 0
for i in range(n):
    score = int(input())
    if score >= 60:
        jige += 1
    if score >= 85:
        youxiu += 1
print(str(round(jige * 100/n))+"%")
print(str(round(youxiu * 100/n)),"%")
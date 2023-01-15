cnt = [0]*26
s = input()
for i in s:
    cnt[ord(i) - ord('a')] += 1
k = 0
for i in range(26):
    if cnt[i] > cnt[k]:
        k = i
print(chr(k+ord('a')))
print(cnt[k])
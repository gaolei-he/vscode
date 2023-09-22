s = input()
ans = 1
def check(s:str)->bool:
    for x, y in zip(s, reversed(s)):
        if x != y:
            return False
    return True
for i in range(len(s)):
    for j in range(i + 1, len(s) + 1):
        if check(s[i:j]):
            ans = max(ans, j - i)
print(ans)
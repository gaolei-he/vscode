from collections import deque
q = deque()

for _ in range(int(input())):
    s = input().split()
    if len(s) == 3:
        q.append((int(s[2]), int(s[1])))
    elif len(s) == 2:
        ans = 0
        c = int(s[1])
        while c > 0:
            t = q.popleft()
            if c >= t[0]:
                c -= t[0]
                ans += t[0] * t[1]
            else:
                q.appendleft((t[0] - c, t[1]))
                ans += c * t[1]
                c = 0
        print(ans)
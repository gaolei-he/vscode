n = int(input())

ans = []

for _ in range(n):
    k, s = input().split()
    k = int(k)
    score1, grade1, score2, grade2 = 0, 0, 0, 0
    st = set()
    for __ in range(k):
        s1, s2, s3, s4, s5 = input().split()
        s2, s3, s5 = int(s2), int(s3), int(s5)
        if s4.startswith("tsk") or s1 in st:
            continue
        st.add(s1)
        score1 += s2 * s3
        grade1 += s3
        if s5 == 1:
            score2 += s2 * s3
            grade2 += s3
        
    total = grade1 * score1 / grade1 * 0.9
    total += grade2 * score2 / grade2 * 0.02
    arr = list(map(int, input().split()))
    v1, v2 = 0, 0
    arr = arr[1:]
    for v in arr:
        if v == 1:
            v1 += 2.0
        elif v == 2:
            v1 += 1.8
        elif v == 3:
            v1 += 1.6
        elif v == 4:
            v1 += 0.8
        elif v == 5:
            v1 += 0.6
        elif v == 6:
            v1 += 0.3
    v1 = min(v1, 4.8)
    t1, t2, t3 = map(int, input().split())
    if t1 >= 150 and t1 < 200:
        v2 += 0.4
    elif t1 >= 200 and t1 < 300:
        v2 += 0.8
    elif t1 >= 300 and t1 < 400:
        v2 += 1.5
    elif t1 >= 400 and t1 < 450:
        v2 += 3.2
    elif t1 >= 450:
        v2 += 4.8
    if t2 == 1:
        v2 += 0.4
    elif t2 == 2:
        v2 += 0.8
    v2 = min(v2, 4.8)
    total += min(6, v1 + v2)
    if t3 == 1:
        total += 2
    ans.append((s, total))

ans.sort(key=lambda x: (-x[1], x[0]))
for name, score in ans:
    print(name)

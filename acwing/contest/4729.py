for _ in range(int(input())):
    n, d, e = map(int, input().split())
    a, b, c = 1, e * d - n - 2, n
    if b * b - 4 * a * c < 0:
        print('NO')
        continue
    delta = int((b * b - 4 * a * c) ** 0.5)
    if delta ** 2 != b ** 2 - 4 * c or (-b + delta) % 2 == 1:
        print('NO')
    else:
        print((-b-delta) // 2, (-b+delta) // 2)
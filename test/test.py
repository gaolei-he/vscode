import hashlib

ans = "01c02f5f0d8d545f76b7d3c854c828e011b71fc17d58b12346810e608b725f3d"


def solve(st: int) -> None:
    sha256sum = hashlib.sha256()

    for ed in range(0, 10**7):
        s = st * 10 ** 12 + ed
        sha256sum.update(str(s).encode("utf-8"))
        if sha256sum.hexdigest() == ans:
            print(s)
            exit(0)

t = hashlib.sha256()
t.update("abc\n".encode("utf-8"))
print(t.hexdigest())


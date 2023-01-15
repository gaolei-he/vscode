class A:
    def __init__(self, x) -> None:
        self.x = x
        pass
    # def __hash__(self) -> int:
    #     return hash(self.x)
a = dict({})
b = [A(1) for i in range(1000000)]
for i in b:
    a[i] = "fi"


import copy
n, m = map(int, input().split())

class queue:
    
    def __init__(self) -> None:
        self.lst = []
    def push(self, n):
        self.lst.append(n)
    def pop_front(self):
        self.lst.pop(0)
    def pop_back(self):
        self.lst.pop(-1)
    def front(self):
        return self.lst[0]
    def back(self):
        return self.lst[-1]
    def size(self):
        return len(self.lst)

class stack:
    lst = []
    def __init__(self) -> None:
        pass
    def push(self, n):
        self.lst.append(n)
    def top(self):
        return self.lst[-1]
    def pop(self):
        self.lst.pop(-1)

first = queue()
for i in range(1, n + 1):
    first.push(i)
second = queue()
cnt = 0

lib = set()

while cnt < n:
    cnt += 1
    tmp = copy.deepcopy(first)
    while second.size() != m:
        if first.size() != 0:
            if first.front() in lib:
                first.pop_front()
                continue
            second.push(first.front())
            first.pop_front()
        else:
            first = copy.deepcopy(tmp)
    print(second.back(), end=' ')
    lib.add(second.back())
    second.pop_back()
    while second.size() != 0:
        if second.front() in lib:
            second.pop_front()
            continue
        first.push(second.front())
        second.pop_front()

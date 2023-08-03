st = set()
for i in range(110):
    st.add(i * i)
n = int(input())
a = list(map(int, input().split()))
print(sum([1 if v in st else 0 for v in a]))
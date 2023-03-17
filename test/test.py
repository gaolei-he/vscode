from datetime import datetime, timedelta
st = datetime(1901, 1, 1)
ed = datetime(2000, 12, 31)
delta = timedelta(1)
ans = 0
while st <= ed:
    if st.weekday() == 6 and st.day == 1:
        ans += 1
    st += delta
print(ans)
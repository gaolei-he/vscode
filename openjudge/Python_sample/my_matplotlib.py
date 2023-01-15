import matplotlib.pyplot as plt
from matplotlib import rcParams
rcParams['font.family'] = rcParams['font.sans-serif'] = 'SimHei'
ax = plt.figure().add_subplot()
# ax.bar(x = (0.2, 0.6, 0.8, 1.2), height=(1, 2, 3, 0.5), width=0.1)
ax.barh(y = (0.2, 0.6, 0.8, 1.2), width=(1, 2, 3, 0.5), height=0.1)

ax.set_title('我的直方图')
plt.show()


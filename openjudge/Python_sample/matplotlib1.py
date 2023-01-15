import matplotlib.pyplot as plt
ax = plt.figure().add_subplot()
labels = ['Jan', 'Feb', 'Mar', 'Apr']
num1 = [20, 30, 15, 35]
num2 = [15, 30, 40, 20]
cordx = range(len(num1))
rects1 = ax.bar(x = cordx, height=num1, width=0.5, color='red',label='Dept1')
rects2 = ax.bar(x=cordx, height=num2, width=0.5, color='green', label='Dept2', bottom=num1)
ax.set_ylim(0, 100)
ax.set_ylabel("Profit")
ax.set_xticks(cordx)
ax.set_xticklabels(labels)
ax.set_xlabel("In year 2020")
ax.set_title("My Company")
ax.legend()
plt.show()
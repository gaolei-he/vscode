import threading
import time

resource = [0 for _ in range(16)]
# 定义一个函数作为线程的执行任务
def thread_function(thread_id):
    while True:
        resource[thread_id] += 1

# 创建多个线程
threads = []
for i in range(16):  # 创建 3 个线程
    thread = threading.Thread(target=thread_function, args=(i,))
    threads.append(thread)

# 启动线程
for thread in threads:
    thread.start()

# 等待所有线程执行完毕
for thread in threads:
    thread.join()
print(*resource)
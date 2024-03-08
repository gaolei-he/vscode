#include <atomic>
#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <vector>
#include <queue>

std::shared_mutex rwMutex;
int counter;

// lock_guard unique_lock shared_lock 的作用在与实现RAII
// 避免了手动上锁和解锁，以及程序抛出异常导致未能及时解锁的情况

// 这些锁可以看做是对 锁 的封装，mutex 即最基本的互斥锁类型
// shared_mutex 可看做 mutex 的升级版，共享锁，支持多个线程持有

void reader() {
    // std::lock_guard<std::mutex> lock(mtx);
    // 互斥锁 同一时刻只能由一个线程持有
    // std::unique_lock<std::mutex> lock(mtx);
    // lock_guard的升级版，支持更多操作，例如可以手动解锁上锁

    // 共享锁 允许多个线程持有
    // 共享锁的意义在于 对于多线程同时访问不会造成数据竞争的情况，对资源上共享锁
    // 用以提高程序的并发性
    int data;

    // 读取变量使用共享锁，提高程序并发性
    {
        std::shared_lock<std::shared_mutex> lock(rwMutex);
        data = counter;
    }

    // 输出时必须使用互斥锁，输出是互斥行为，同一时刻只能由一个线程持有
    {
        std::lock_guard<std::shared_mutex> lck(rwMutex);
        std::cout << "Reader Thread ID: " << std::this_thread::get_id()
                  << " - Shared value: " << data << std::endl;
    }
}

void writer() {
    // 写锁，互斥锁，同一时刻只能由一个线程持有
    std::lock_guard<std::shared_mutex> lock(rwMutex);
    counter++;
    std::cout << "Writer Thread ID: " << std::this_thread::get_id()
              << " - Incremented shared value to: " << counter << std::endl;
}

int main() {
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    q.push(1);
    q.push(2);
    std::cout << q.top();

    return 0;
}
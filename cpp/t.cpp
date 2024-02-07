#include <atomic>
#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <vector>

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
    std::shared_lock<std::shared_mutex> lock(rwMutex);
    std::cout << "Reader Thread ID: " << std::this_thread::get_id()
              << " - Shared value: " << counter << std::endl;
}

void writer() {
    // 互斥锁，同一时刻只能由一个线程持有
    std::lock_guard<std::shared_mutex> lock(rwMutex);
    counter++;
    std::cout << "Writer Thread ID: " << std::this_thread::get_id()
              << " - Incremented shared value to: " << counter << std::endl;
}

int main() {
    std::thread th(writer);

    std::vector<std::thread> readers;
    for (int i = 0; i < 16; i++) readers.emplace_back(reader);

    th.join();
    for(auto& t : readers) t.join();

    return 0;
}
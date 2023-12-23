#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>

std::queue<int> buffer;
std::mutex mtx;
std::condition_variable buffer_not_full;
std::condition_variable buffer_not_empty;

void producer(int id)
{
    for (int i = 0; i < 10; ++i)
    {
        std::unique_lock<std::mutex> lock(mtx);// 不同于lock_guard，unique_lock可以在任何时候unlock
        // wait()首先释放锁，判断第二个参数是否为true，如果为true则继续执行，否则阻塞当前线程，直到其他线程调用notify_one()或notify_all()唤醒当前线程
        buffer_not_full.wait(lock, [] { return buffer.size() < 10; });
        buffer.push(i);
        std::cout << "Producer " << id << " produced " << i << std::endl;
        // 唤醒一个等待的消费者进程
        buffer_not_empty.notify_one();
    }
}

void consumer(int id)
{
    for (int i = 0; i < 10; ++i)
    {
        std::unique_lock<std::mutex> lock(mtx);
        buffer_not_empty.wait(lock, [] { return buffer.size() > 0; });
        int item = buffer.front();
        buffer.pop();
        std::cout << "Consumer "  << id << " consumed " << item << std::endl;
        buffer_not_full.notify_one();
    }
}

int main()
{
    std::vector<std::thread> producers;
    std::vector<std::thread> consumers;
    for (int i = 0; i < 10; i++)
    {
        producers.emplace_back(producer, i);
    }
    for (int i = 0; i < 10; i++)
    {
        consumers.emplace_back(consumer, i);
    }
    for (auto &th : producers) th.join();
    for (auto &th : consumers) th.join();
    
    
    return 0;
}
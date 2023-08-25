#include <thread>
#include <iostream>
#include <vector>
#include <mutex>
std::vector<int> vec;
class A
{
public:
    A() { std::cout << "A()" << std::endl; }
    A(int i) { std::cout << "A(int)" << std::endl; }
};
void f(int id)
{
    for(int i=0;i<1000000;i++)
        vec[id] ++;
}
int main()
{
    vec.resize(16);
    std::vector<std::thread> threads(16);
    for (int i = 0; i < threads.size(); i++)
    {
        threads[i] = std::thread(f, i);
    }
    
    for(auto &th : threads) th.join();
    for(auto x : vec) std::cout << x << ' ';
    return 0;
}
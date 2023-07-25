#include <iostream>
#include <vector>
#include <thread>
#include <cstdlib>
#include <sys/types.h>
#include <unistd.h>
using namespace std;
int val;
void task()
{
    for(int i=1;i<=1000000;i++) val ++;
}
int main()
{
    vector<thread> vec;
    for(int i=0;i<16;i++)
    {
        vec.push_back(thread(task));
    }
    for(auto &th:vec)
    {
        th.join();
    }
    cout << val << endl;
    return 0;
}
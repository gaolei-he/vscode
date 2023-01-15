#include <iostream>
#include <cstring>
using namespace std;//M输入数据行数
const int M = 1;
template <class T, class F>
auto k(T a, F b) -> decltype(a + b)
{
    return a + b;
}
int main()
{
    //cout << k(1, 2.3);
    char* const p = "jfoe";
    p = "fj";
    return 0;
}
#include <iostream>
#include <vector>
class A
{
public:
    int val;
public:
    A(int x):val(x){}
    A(const A &a)
    {
        val = a.val + 1;
    }
};
int main()
{
    A a(10);
    A b = a;
    std::cout << b.val;
    return 0;
}
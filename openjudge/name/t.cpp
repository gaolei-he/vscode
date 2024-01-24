#include <iostream>
class A 
{
public:
    int x;
    A(int x_):x(x_){std::cout << x << "called\n";}
    A(const A & a) { x = a.x + 2; std::cout << "copy\n";}
    ~A() {std::cout << x << "decalled\n";}
};
A f()
{
    A b(10);
    return b;
}
int main()
{
    A a(1);
    a = f();
    return 0;
}
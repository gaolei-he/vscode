#include <iostream>
#include <vector>
class Node
{
private:
    int member;
public:
    Node()
    {
        member = 1;
    }
    ~Node()
    {
        std::cout << "decalled" << std::endl;
    }
};
Node f()
{
    Node a;
    return a;
}
int main()
{
    auto t = f();
    return 0;
}
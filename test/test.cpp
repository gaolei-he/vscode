#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <cstring>
using namespace std;
struct Node
{
    void operator()(int a, int b) {
        cout << a << ' ' << b << endl;
    }
};

int main()
{
    Node node;
    node(1, 2);
    return 0;
}
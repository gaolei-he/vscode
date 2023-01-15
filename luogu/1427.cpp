#include <iostream>
using namespace std;
void f()
{
    int n;
    cin >> n;
    if(n==0) return;
    f();
    printf("%d ", n);
}
int main()
{
    f();
    return 0;
}
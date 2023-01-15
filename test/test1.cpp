#include <cmath>
#include <array>
#include <iostream>
#include <vector>
#include <unistd.h>
using namespace std;
typedef long long ll;
ll n = 0;
void f()
{
    // printf("%d\n", n);
    n ++;
    f();
}
int main()
{
    // f();
    array<int, 4> ar;
    cout << ar.size() << endl;
    ar.at(3) = 3;
    for(auto i:ar) cout << i << endl;
    cout << sizeof(ar);
    // cout << (1 and 0) << endl;
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int n = -2147483648;
    for(int i=0;i<32;i++)
    {
        n >>= 1;
        for(int i=0;i<32;i++) cout << ((n >> i) & 1);
        cout <<  ' ' << n;
        puts("");
    }
    return 0;
}
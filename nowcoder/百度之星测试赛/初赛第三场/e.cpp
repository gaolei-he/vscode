#include <iostream>
#define int long long
using namespace std;
const int mod = 998244353;
int f(int n)
{
    if(n == 2) return 3;
    return (1 << n) - f(n - 1);
}
signed main()
{
    int n;

    for (int i = 2; i < 62; i++)
    {
        cout << f(i) % mod << endl;

    }
    
    
    return 0;
}
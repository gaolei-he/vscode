#include <iostream>
#define int long long
using namespace std;
const int mod = 1e11+3;
int f[10000009];
signed main()
{
    f[1] = f[2] = 1;
    f[2] = 3;
    int n;
    for (int i=3;i<=10000000;i++) f[i] = (f[i-1] + f[i-2]) % mod;
    cin >> n;
    int sum = 0;
    for (int i=1;i<=n;i++) sum = (sum + f[i]) % mod;
    cout << sum << endl;
    return 0;
}
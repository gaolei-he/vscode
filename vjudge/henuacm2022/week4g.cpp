#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const ll mod = 998244353;
const int N = 1e6+10;
ll f[N];
int main()
{
    f[1] = 1;
    for(int i=2;i<=N-5;i++) f[i] = (f[i-1] + f[i-2]) % mod;
    int p;
    cin >> p;
    for(int i=2;i<=N-5;i++) f[i] = (f[i] + f[i-1]) % mod;
    cout << f[p];
    return 0;
}

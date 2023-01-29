#include <iostream>
#define rep(i, a, n) for(int i=(a);i<=(n);i++)
#define dec(i, n, a) for(int i=(n);i>=(a);i--)
using namespace std;
const int N = 1e3+10;
int f[N];
int n, V;
int w[N], v[N];
int main()
{
    cin >> n >> V;
    rep(i, 1, n) cin >> v[i] >> w[i];
    rep(i, 1, V) f[i] = i / v[1] * w[1];
    rep(i, 2, n)
        rep(j, v[i], V)
            if(j-v[i] >= 0) f[j] = max(f[j], f[j-v[i]] + w[i]);
    cout << f[V];

    return 0;
}
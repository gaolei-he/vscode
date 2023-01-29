#include <iostream>
#define rep(i, a, n) for(int i=(a);i<=(n);i++)
#define dec(i, n, a) for(int i=(n);i>=(a);i--)
using namespace std;
int n, m;
const int N = 1e3+10;
const int mod = 1e9+7;
int f[N], g[N];
int main()
{
    cin >> n >> m;

    rep(j, 0, m)
        g[j] = 1;
    rep(i, 1, n)
    {
        int v, w;
        cin >> v >> w;
        dec(j, m, v)
        {

            if(f[j] == f[j-v]+w)
            {
                g[j] = (g[j] + g[j-v]) % mod;
                f[j] = f[j];
            }
            else if(f[j] > f[j-v]+w)
            {
                g[j] = g[j];
                f[j] = f[j];
            }
            else
            {
                g[j] = g[j-v];
                f[j] = f[j-v] + w;
            }
        }

    }
    cout << g[m] << endl;

    return 0;
}
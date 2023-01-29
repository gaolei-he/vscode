#include <iostream>
#define rep(i, a, n) for(int i=(a);i<=(n);i++)
#define dec(i, n, a) for(int i=(n);i>=(a);i--)
using namespace std;
int n, m;
int f[110];
int v[110], w[110];
int main()
{
    cin >> n >> m;
    rep(i, 1, n)
    {
        int s;
        cin >> s;
        rep(j, 1, s) cin >> v[j] >> w[j];
        dec(j, m, 1)
        {
            rep(k, 1, s)
                if(j >= v[k]) f[j] = max(f[j], f[j-v[k]]+w[k]);
        }
    }
    cout << f[m] << endl;
    return 0;
}
/*
对于每组物品，f[i, j]表示前i组体积最大为j
对于每个f[i, j]，枚举该组所有物品，得出最大的f[i, j]
*/
#include <iostream>
#include <cstring>
#define rep(i, a, n) for(int i=(a);i<=(n);i++)
#define dec(i, n, a) for(int i=(n);i>=(a);i--)
using namespace std;
const int N = 310;
int a[N], s[N];
int f[N][N];
int main()
{
    int n; cin >> n;
    memset(f, 0x3f, sizeof(f));
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) s[i] = s[i-1] + a[i];
    rep(i, 0, n-1)
        rep(j, 1, n - i)
        {
            if(!i) f[j][j] = 0;
            rep(k, j, j+i-1)
                f[j][j+i] = min(f[j][k]+f[k+1][j+i] + s[j+i] - s[j-1], f[j][j+i]);
        }

    cout << f[1][n] << endl;
    

    return 0;
}
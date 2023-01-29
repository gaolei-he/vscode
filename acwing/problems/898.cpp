#include <iostream>
#include <cstring>
#define rep(i, a, n) for(int i=(a);i<=(n);i++)
#define dec(i, n, a) for(int i=(n);i>=(a);i--)
using namespace std;
const int N = 510;
int f[N][N];
int main()
{
    int n;
    memset(f, 0xff, sizeof(f));
    cin >> n;
    rep(i, 0, n+3) f[0][i] = 0;
    rep(i, 1, n)
        rep(j, 1, i)
        {
            int x;
            cin >> x;
            if(j == i)
            {
                f[i][j] = f[i-1][j-1] + x;
                continue;
            }
            f[i][j] = f[i-1][j];
            if(j>1) f[i][j] = max(f[i][j], f[i-1][j-1]);
            f[i][j] += x;
        }
    int ans = 0;
    rep(i, 1, n) ans = max(f[n][i], ans);
    cout << ans << endl;
    return 0;
}
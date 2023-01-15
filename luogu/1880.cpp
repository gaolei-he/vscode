#include <iostream>
#include <cstring>
#define rep(i, a, n) for(int i=(a);i<=(n);i++)
#define dec(i, n, a) for(int i=(n);i>=(a);i--)
using namespace std;
const int N = 210;
int a[N], s[N];
int f[N][N];
int main()
{
    int n; cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, n+1, n<<1) a[i] = a[i-n];
    n <<= 1;

    memset(f, 0x3f, sizeof(f));
    
    rep(i, 1, n) s[i] = s[i-1] + a[i];
    rep(i, 0, n-1)
        rep(j, 1, n - i)
        {
            if(!i) f[j][j] = 0;
            rep(k, j, j+i-1)
                f[j][j+i] = min(f[j][k]+f[k+1][j+i] + s[j+i] - s[j-1], f[j][j+i]);
        }

    int ans = 0x3f3f3f3f;
    rep(i, 1, n >> 1) ans = min(f[i][i+(n>>1)-1], ans);
    cout << ans << endl;
    memset(f, 0, sizeof(f));
    rep(i, 0, n-1)
        rep(j, 1, n - i)
        {
            if(!i) f[j][j] = 0;
            rep(k, j, j+i-1)
                f[j][j+i] = max(f[j][k]+f[k+1][j+i] + s[j+i] - s[j-1], f[j][j+i]);
        }
    ans = 0;
    rep(i, 1, n >> 1) ans = max(f[i][i+(n>>1)-1], ans);
    cout << ans << endl;
    return 0;
}
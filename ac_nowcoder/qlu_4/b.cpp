#include <cstring>
#include <iostream>
#define int long long
#define rep(i, a, n) for (int i=(a); i<=(n); ++i)
#define dec(i, a, n) for (int i=(a); i>=(n); --i)
using namespace std;
signed main()
{
    int n, m;
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int a[n+10][m+10], b[n+10][m+10], c[n+10][m+10], d[n+10][m+10];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));
    rep(i, 1, n)
        rep(j, 1, m)
            cin >> a[i][j];
    int w, h;
    cin >> h >> w;
    rep(i, 1, n)
        dec(j, m, 1)
            if(j == m) b[i][j] = 1;
            else b[i][j] = (a[i][j] == a[i][j+1] ? b[i][j+1] + 1 : 1);
    bool ans = false;

    
    dec(i, n, 1)
        rep(j, 1, m)
        {
            if(b[i][j] >= w)
            {
                if(a[i][j] == a[i+1][j]) c[i][j] = c[i+1][j] + 1;
                else c[i][j] = 1;
            }
            if(c[i][j] >= h) ans = true;
            if(b[i][j] >= h)
            {
                if(a[i][j] == a[i+1][j]) d[i][j] = d[i+1][j] + 1;
                else d[i][j] = 1;
            }
            if(d[i][j] >= w) ans = true;
        }
    if(ans) cout << "YES";
    else cout << "NO";
    return 0;
}
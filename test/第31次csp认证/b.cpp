#include <iostream>
#include <cmath>
#include <iomanip>
#define endl "\n"
#define rep(i, a, n) for(int i=(a);i<=(n);i++)
using namespace std;
const int N = 1e5 + 10;
double s1[N], s2[N];
void solve()
{
    int n, m; cin >> n >> m;
    rep(i, 0, n) s1[i] = 1;
    rep(i, 1, n)
    {
        int op;
        double val;
        cin >> op >> val;
        if(op == 1) s1[i] = val;
        else s2[i] = val;
        s1[i] *= s1[i - 1];
        s2[i] += s2[i - 1];
    }
    rep(i, 1, m)
    {   
        int l, r;
        double x, y;
        cin >> l >> r >> x >> y;
        double k = s1[r] / s1[l - 1];
        double th = s2[r] - s2[l - 1];
        x *= k, y *= k;
        double a = x * cos(th) - y * sin(th);
        double b = x * sin(th) + y * cos(th);
        cout << fixed << setprecision(5) << a << ' ' << b << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
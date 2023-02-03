#include <iostream>
#include <cmath>
#define rep(i, a, n) for(int i=(a);i<=(n);i++)
#define dec(i, n, a) for(int i=(n);i>=(a);i--)
#define int long long
using namespace std;
int n, l, r;
double g(int i)
{
    return n * 1.0 / i + i - 1;
}
int f(int i)
{
    return n / i + i -1;
}
const double eps = 1e-5;
void solve()
{
    cin >> n >> l >> r;
    int pos = l;
    if(f(r) < f(l)) pos = r;
    int x = sqrt(n);
    if(l <= x && r >= x && f(x) < f(pos)) pos = x;
    x ++;
    if(l <= x && r >= x && f(x) < f(pos)) pos = x;
    r = pos;
    while(l < r)
    {
        int mid = l + r >>  1;
        if(f(mid) > f(pos)) l = mid + 1;
        else r = mid;
    }
    cout << l << endl;
}
signed main()
{
    // n = 8;
    // rep(i, 1, 10) cout << f(i) << ' ';
    int t; cin >> t;
    while(t --)
        solve();

    return 0;
}
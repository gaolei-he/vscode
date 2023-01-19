#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <random>
#include <cassert>
#include <functional>
#include <iomanip>
#include <array>
#include <unordered_map>
#include <unordered_set>
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
#define ll long long
#define int long long
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using PII = pair<int, int>;
using ar2 = array<int, 2>;
const long double eps = 1e-5;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
void solve()
{
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    long double xd, yd, xe, ye, xf, yf;
    cin >> xd >> yd >> xe >> ye >> xf >> yf;
    xa -= xb, ya -= yb;
    xc -= xb, yc -= yb;
    if(xa * xa + ya * ya < xc * xc + yc * yc)
    {
        swap(xa, xc);
        swap(ya, yc);
    }
    xd -= xe, yd -= ye;
    xf -= xe, yf -= ye;
    if(xd * xd + yd * yd < xf * xf + yf * yf)
    {
        swap(xd, xf);
        swap(yd, yf);
    }
    if(fabs(xa * xa + ya * ya - xc * xc - yc * yc) < eps) cout << "NO" << endl;
    else
    {
        long double tmp = (xa * yc - xc * ya) * (xd * yf - xf * yd);
        if(tmp > 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    long double l = 0, s = 0;
    bool flag = false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}
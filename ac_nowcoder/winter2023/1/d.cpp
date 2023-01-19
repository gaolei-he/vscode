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
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
void solve()
{
    int x, y, xp, yp;
    cin >> x >> y >> xp >> yp;
    long double ans = 0, k = 1.0;
    int t = 0, sm = 0;
    if(xp >= 0 && xp <= x && yp >= 0 && yp <= y)
    {
        sm = x * y;
        t = max(t, xp * yp);
        t = max(t, (x-xp)*yp);
        t = max(t, xp * (y-yp));
        t = max(t, (x-xp) * (y-yp));
    }
    else
    {
        if(xp >= 0 && xp <= x)
        {
            t = max((x-xp) * y, xp * y);
            sm = x * y + max((x-xp) * yp, xp*yp) - t;
        }
        else if(yp >= 0 && yp <= y)
        {
            t = max(yp * x, (y-yp) * x);
            sm = x * y + max(xp * yp, (y-yp) * xp) - t;
        }
        else
        {
            sm = xp * yp;
            t = x * y;
        }
    }
    cout << fixed << setprecision(10) << t * k / sm << endl;
}
signed main()
{
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}
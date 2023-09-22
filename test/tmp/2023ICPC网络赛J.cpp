#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <stack>
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
#define int long long
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;
void solve()
{
    int x11, y11, x12, y12, x21, y21, x22, y22;
    cin >> x11 >> y11 >> x12 >> y12;
    cin >> x21 >> y21 >> x22 >> y22;
    double x1, y1, x2, y2;
    x1 = (x11 + x12) / 2.0, y1 = (y11 + y12) / 2.0;
    x2 = (x21 + x22) / 2.0, y2 = (y21 + y22) / 2.0;
    double ans = fabs(x1 - x2) + fabs(y1 - y2);
    ans -= sqrt(2) * sqrt((x2 - x21) * (x2 - x21) + (y2 - y21) * (y2 - y21));
    cout << fixed << setprecision(10) << ans << endl;
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
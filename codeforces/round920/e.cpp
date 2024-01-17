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
    int h, w, xa, ya, xb, yb;
    cin >> h >> w >> xa >> ya >> xb >> yb;
    if(xa > xb) cout << "Draw" << endl;
    else if((xb - xa) & 1)
    {
        while(xa < xb)
        {
            int cases;
            if(ya < yb) cases = 1;
            else if(ya > yb) cases = -1;
            else
            {
                cout << "Alice" << endl;
                return;
            }
            xa ++;
            if(cases == 1) ya ++;
            else if(cases == -1) ya --;
            if(xa == xb and ya == yb)
            {
                cout << "Alice" << endl;
                return;
            }
            if(cases == 1 and yb != w) yb ++;
            else if(cases == -1 and yb != 1) yb --;
            xb --;
        }
        cout << "Draw" << endl;
    }
    else
    {
        while(xa < xb)
        {
            int cases;
            if(ya < yb) cases = 1;
            else if(ya > yb) cases = -1;
            else
            {
                cout << "Bob" << endl;
                return;
            }
            xa ++;
            if(cases == 1 and ya != 1) ya --;
            else if(cases == -1 and ya != w) ya ++;
            if(yb > ya) yb --;
            else if(yb < ya) yb ++;
            xb --;

            if(xa == xb and ya == yb)
            {
                cout << "Bob" << endl;
                return;
            }
        }
        cout << "Draw" << endl;
    }
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
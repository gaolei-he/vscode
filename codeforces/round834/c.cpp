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
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
#define ll long long
#define int long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using PII = pair<int, int>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
void solve()
{
    int l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;
    int ans = 0;
    if(abs(a - b) >= x) ans = 1;
    else
    {
        if(a > b)
        {
            if(a + x <= r) ans = 2;
            else if(b - l >= x) ans = 2;
            else ans = -1;
        }
        else if(a < b)
        {
            if(a - l >= x) ans = 2;
            else if(r - b >= x) ans = 2;
            else ans = -1;
        }
        else ans = 0;
    }
    if(ans == -1 && (b-l >= x || r-b >=x) && (r-a>=x || a-l >=x)) ans = 3;
    cout << ans << endl;
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
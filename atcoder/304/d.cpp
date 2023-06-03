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
    int w, h, n, a, b;
    cin >> w >> h >> n;
    vector<pii> star(n);
    for(auto& x:star) cin >> x.first >> x.second;
    cin >> a;
    vector<int> vecx(a);
    for(auto& x:vecx) cin >> x;
    cin >> b;
    vector<int> vecy(b);
    for(auto& x:vecy) cin >> x;
    unordered_map<string, int> mp;
    for(auto x:star)
    {
        int tx, ty;
        auto it = lower_bound(vecx.begin(), vecx.end(), x.first);
        if(it == vecx.begin()) tx = 0;
        else tx = *(--it);
        it = lower_bound(vecy.begin(), vecy.end(), x.second);
        if(it == vecy.begin()) ty = 0;
        else ty = *(--it);
        mp[to_string(tx) + " " + to_string(ty)] ++;
    }
    int mi = 1e9, ma = -1;
    for(auto x:mp) mi = min(x.second, mi), ma = max(x.second, ma);
    if((a + 1) * (b + 1) > mp.size()) mi = 0;
    cout << mi << ' ' << ma << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}
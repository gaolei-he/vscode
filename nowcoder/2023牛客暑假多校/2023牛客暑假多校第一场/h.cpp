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
    int n; cin >> n;
    int ans = 0, sm = 0;
    vector<pii> vec(n);
    for(auto &[x, y] : vec) cin >> x;
    for(auto &[x, y] : vec) cin >> y;
    vector<pii> T, tmp;
    vector<int> Sx, Sy, len;
    for(auto [x, y] : vec) {
        sm += abs(x - y);
        if(x < y) tmp.emplace_back(x, y);
        else if(x > y) T.emplace_back(y, x);
    }
    sort(tmp.begin(), tmp.end());
    int r = -1e18;
    for(auto [x, y] : tmp) {
        if(y <= r) continue;
        r = y;
        Sx.emplace_back(x), Sy.emplace_back(y);
        len.emplace_back(y - x);
    }
    auto query = [&](int x, int y) {
        int n = Sx.size(), res = 0;
        int l = upper_bound(Sx.begin(), Sx.end(), x) - Sx.begin();
        int r = lower_bound(Sy.begin(), Sy.end(), y) - Sy.begin();
        if(l > 0) res = max(res, min(y, Sy[l - 1]) - x);
        if(r < n) res = max(res, y - max(x, Sx[r]));
        if(l < r) res = max(res, *max_element(len.begin() + l, len.begin() + r));
        return res;
    };
    for(auto [x, y] : T) ans = max(ans, query(x, y));
    cout << sm - ans * 2 << endl;
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
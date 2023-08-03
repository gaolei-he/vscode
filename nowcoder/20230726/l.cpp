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
    int n, h; cin >> n >> h;
    vector<pii> vec(n);
    for(auto &x : vec) cin >> x.first >> x.second;
    sort(vec.begin(), vec.end());
    auto it = lower_bound(vec.begin(), vec.end(), pii(vec.back().first, 0));
    vector<pii> ans;
    for(auto x : vec)
        if(x.second >= it->first)
            ans.push_back(x);
    sort(ans.begin(), ans.end(), [&](pii a, pii b) {
        if(a.second != b.second) return a.second > b.second;
        return a.first > b.first;
    });
    int res = 0;
    ans.pop_back();
    for(auto x : ans)
    {
        if(h <= 0) break;
        res ++;
        h -= x.second;
    }
    while(h > 0)
    {
        res ++;
        if(h - it->second <= 0) break;
        h -= it->first;
    }
    cout << res << endl;

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
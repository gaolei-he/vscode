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
    int n, m; cin >> n >> m;
    set<pii> st1, st2;
    rep(i, 1, n) st1.emplace(i, 0);
    vector<int> ans(n + 1);
    rep(i, 1, m)
    {
        int t, w, s;
        cin >> t >> w >> s;
        while(!st2.empty() and st2.begin()->first <= t)
        {
            auto it = *st2.begin();
            st2.erase(it);
            st1.insert({it.second, 0});
        }
        if(!st1.empty())
        {
            auto it = *st1.begin();
            st1.erase(it);
            ans[it.first] += w;
            st2.insert({t + s, it.first});
        }

    }
    rep(i, 1, n) cout << ans[i] << endl;
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
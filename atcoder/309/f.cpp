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
using ar3 = array<int, 3>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;
void solve()
{
    int n; cin >> n;
    map<int, vector<pii>> mp;
    rep(i, 1, n)
    {
        int x, y, z; cin >> x >> y >> z;
        ar3 a = {x, y, z};
        sort(a.begin(), a.end());
        x = a[0], y = a[1], z = a[2];
        mp[x].push_back({y, z});
    }
    set<pii> st;
    st.insert({linf, 0});
    st.insert({0, linf});
    for(auto &[h, vec] : mp)
    {
        for(auto [w, d] : vec)
        {
            auto it = st.lower_bound({w, 0});
            -- it;
            if(it -> second < d)
            {
                cout << "Yes" << endl;
                return;
            }
        }
        for(auto [w, d] : vec)
        {
            auto it = st.upper_bound({w, d});
            while(it->second >= d) it = st.erase(it);
            -- it;
            if(it->second > d) st.insert({w, d});
        }
    }
    cout << "No" << endl;
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
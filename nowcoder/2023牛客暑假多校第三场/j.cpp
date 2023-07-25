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
    set<pii> st;
    rep(i, 1, m)
    {
        int u, v; cin >> u >> v;
        st.insert({u, v});
    }
    map<int, int> mp;
    vector<vector<int>> vec;
    while(st.size())
    {
        vector<pii> tmp;
        for(auto [u, v] : st)
        {
            if(mp.count(u) and mp.count(v) and mp[u] > mp[v]) continue;
            else if(mp.count(u) and mp.count(v)) cerr << "error" << endl;
            else if(mp.count(u)) mp[v] = mp[u] + 1, cerr << v << ' ' << mp[v] << endl;
            else if(mp.count(v)) mp[u] = mp[v] - 1, cerr << u << ' ' << mp[u] << endl;
            else mp[u] = 1, mp[v] = 2, cerr << u << ' ' << mp[u] << endl, cerr << v << ' ' << mp[v] << endl;
            tmp.emplace_back(u, v);
        }
        for(auto x : tmp) st.erase(x);
        tmp.clear();
        for(auto [v, val] : mp) tmp.emplace_back(val, v);
        sort(tmp.begin(), tmp.end());
        unordered_set<int> st1;
        rep(i, 1, n) st1.insert(i);
        vec.push_back(vector<int>());
        for(auto [val, v] : tmp)
        {
            vec.back().push_back(v);
            st1.erase(v);
        }
        for(auto x : st1) vec.back().push_back(x);
        mp.clear();
    }
    cout << vec.size() << endl;
    for(auto ver : vec)
    {
        for(auto x : ver) cout << x << ' ';
        cout << endl;
    }
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
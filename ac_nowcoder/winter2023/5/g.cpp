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
using pii = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 7e4, mod = 1e9 + 7;
int match[N];
bool st[N];
vector<vector<int>> g;

bool find(int k)
{
    for(auto i:g[k])
    {
        if(st[i]) continue;
        st[i] = true;
        if(match[i] == 0 || find(match[i]))
        {
            match[i] = k;
            return true;
        }
    }
    return false;
}
void solve()
{
    int n; cin >> n;
    g.resize(n+1);
    vector<int> v(n/2);
    for(auto& x:v) cin >> x;
    function<vector<int>(int)> f = [&](int k) {
        if(k >= v.size()) return vector<int>();
        vector<int> res;
        rep(i, 0, mod)
        {
            int x = v[k];
            x = x ^ (1 << i);
            if(x >= n) break;
            res.push_back(x);
        }
        return res;
    };
    unordered_set<int> total;
    for(auto i:v) total.insert(i);
    for(int i=1;i<n;i+=2)
    {
        auto v1 = f(i/2);
        auto v2 = f(i/2+1);
        set<int> st;
        for(auto k:v1) st.insert(k);
        if(v2.size()) {for(auto k:v2) if(st.count(k) && (!total.count(k))) g[i].push_back(k);}
        else {for(auto k:v1) if(!total.count(k)) g[i].push_back(k);}
    }
    for(int i=1;i<n;i+=2)
    {
        memset(st, 0, sizeof(st));
        find(i);
    }
    vector<pii> ans;
    rep(i, 0, n-1) if(match[i]) ans.push_back({match[i], i});
    sort(ans.begin(), ans.end());
    rep(i, 0, n/2-1) cout << v[i] << ' ' << ans[i].second << ' ';
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
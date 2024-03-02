#include <vector>
#include <iostream>
#include <set>
#include <functional>
#define rep(i, a, n) for(int i=(a); i<=(n); ++i)
#define int long long
using namespace std;
using pii = pair<int, int>;

signed main()
{
    int n; cin >> n;
    vector<set<pii>> g(n + 1);
    vector<int> tmp(n - 1);
    for(auto &x : tmp) cin >> x;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];

    rep(i, 0, n - 2)
        g[tmp[i]].emplace(a[i + 2], i + 2);

    vector<int> ans(n + 1);

    function<void(int)> dfs = [&](int fa) {
        for(auto &p : g[fa]) {
            dfs(p.second);
        }

        set<pii> st = g[fa];
        for(auto &p : g[fa]) {
            for(auto v : g[p.second]) st.insert(v);
            g[p.second].clear();
        }
        st.emplace(a[fa], fa);
        auto it = st.begin();
        int res = 0;
        if(st.size() > 1)
        for(auto &p : st)
        {
            // cerr << p.first << ' ' << p.second << endl;
            if(it == st.begin())
            {
                ++ it;
                res += (p.first - it->first) * (p.first - it->first);
            }
            else
            {
                -- it;
                int val = (p.first - it->first) * (p.first - it->first);
                ++ it;
                ++ it;
                if(it != st.end()) val = min(val, (p.first - it->first) * (p.first - it->first));
                res += val;
            }
        }
        // cerr << endl;
        ans[fa] = res;
        g[fa].clear();
        g[fa] = move(st);
    };
    dfs(1);

    rep(i, 1, n) cout << ans[i] << endl;

    return 0;
}
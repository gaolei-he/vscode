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
void solve()
{
    int n, t, m; cin >> n >> t >> m;
    vector<pii> vec(m);
    int res = 0;
    for(auto &[x, y]:vec) cin >> x >> y;
    vector<set<int>> ans(t);
    vector<bool> vis(n+1);
    function<bool(void)> check = [&]() {

        for(auto &[x, y] : vec)
            for(auto &st : ans)
                if (st.count(x) and st.count(y))
                    return false;
        return true;
    };
    function<void(int)> dfs1 = [&](int cnt) {
        if(cnt == n - t and check())
        {
            res ++;
            return;
        }
        else if(cnt >= n - t) return;

        rep(i, 1, n)
        {
            if(vis[i]) continue;
            vis[i] = true;
            rep(j, 0, t-1)
            {
                if(i < *ans[j].rbegin()) continue;
                ans[j].insert(i);
                dfs1(cnt + 1);
                ans[j].erase(i);
            }
            vis[i] = false;
            break;
        }
    };
    function<void(int, int)> dfs = [&](int cnt, int index) {
        if(cnt == t)
        {
            dfs1(0);
            return;
        }
        else if(cnt > t) return;
        rep(i, index, n)
        {
            if(vis[i]) continue;
            vis[i] = true;
            ans[cnt].insert(i);
            dfs(cnt + 1, i + 1);
            ans[cnt].erase(i);
            vis[i] = false;
        }
    };
    dfs(0, 1);
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
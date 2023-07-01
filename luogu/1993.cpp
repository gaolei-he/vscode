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
const int N = 10 + 3e5, mod = 1e9 + 7;
int dist[N], cnt[N];
bool st[N];
int n, m;
bool spfa(vector<vector<pii>>& g)
{
    queue<int> q;
    rep(i, 0, n) q.push(i), st[i] = true;
    memset(dist, 0x3f, sizeof(dist));
    while(q.size())
    {
        int t = q.front();
        st[t] = false;
        q.pop();
        for(auto [j, w] : g[t])
        {
            if(dist[j] > dist[t] + w)
            {
                dist[j] = dist[t] + w;
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n) return true;
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}
void solve()
{
    cin >> n >> m;
    vector<vector<pii>> g(n + 1);
    rep(i, 1, m)
    {
        int op, a, b, c;
        cin >> op >> a >> b;
        if(op != 3) cin >> c;
        else c = 0;
        if(op == 1) g[a].push_back({b, -c});
        else if(op == 2) g[b].push_back({a, c});
        else
        {
            g[a].push_back({b, 0});
            g[b].push_back({a, 0});
        }
    }
    rep(i, 1, n) g[0].push_back({i, 0});
    if(spfa(g)) cout << "No" << endl;
    else cout << "Yes" << endl;
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
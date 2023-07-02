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
int n, s, t;
bool sta[N];
bool spfa(vector<vector<ar3>> &g, double t, vector<int>& score)
{
    vector<vector<pair<int, double>>> gg(g.size());
    rep(i, 1, n)
    {
        for(auto& [j, d, k]: g[i])
        {
            if(d == 1)
            {
                if(k <= t) continue;
                gg[i].push_back({j, -log2(k - t)});
            }
            else gg[j].push_back({i, log2(k + t)});
        }
    }
    rep(i, 1, n)
    {
        if(score[i]) 
            gg[0].push_back({i, log2(score[i])}), gg[i].push_back({0, -log2(score[i])});
    }
    queue<int> q;
    vector<double> dist(n + 1, 1e18);
    vector<int> cnt(n+1, 0);
    dist[0] = 0;
    rep(i, 0, n) q.push(i), sta[i] = true;
    // cerr << t << endl;
    // rep(i, 0, n)
    //     for(auto& [j, v]: gg[i])
    //         cerr << i << ' ' << j << ' ' << v << endl;
    // cerr << endl;
    while(q.size())
    {
        int ver = q.front();
        q.pop();
        sta[ver] = false;
        for(auto& [j, d]: gg[ver])
        {
            if(dist[j] > dist[ver] + d)
            {
                cnt[j] = cnt[ver] + 1;
                if(cnt[j] >= n) return true;
                dist[j] = dist[ver] + d;
                if(!sta[j]) q.push(j), sta[j] = true;
            }
        }
    }
    return false;
}
void solve()
{
    cin >> n >> s >> t;
    vector<vector<ar3>> g(n + 1);
    rep(i, 1, s)
    {
        int o, A, B, k;
        cin >> o >> A >> B >> k;
        if(o == 1) g[A].push_back({B, 1, k});
        else g[B].push_back({A, -1, k});
    }
    double l = 0, r = 10;
    vector<int> score(n+1, 0);
    rep(i, 1, t)
    {
        int C, x;
        cin >> C >> x;
        score[C] = x;
    }
    while(r-l>1e-6)
    {
        double mid = (l + r) / 2;
        if(spfa(g, mid, score)) l = mid;
        else r = mid;
    }
    if(!spfa(g, 0, score)) cout << -1 << endl;
    else cout << fixed << setprecision(6) << l << endl;
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
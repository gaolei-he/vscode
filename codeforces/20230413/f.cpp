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
const int N = 10 + 1e2, mod = 1e9 + 7;
int n, m;
int cnt[N];
map<int, string> mp;
vector<vector<int>> g;
void bfs()
{
    memset(cnt, 0, sizeof(cnt));
    queue<int> q;
    q.push(m);
    while(q.size())
    {
        int v = q.front();
        q.pop();
        for(auto x:g[v])
        {
            if(cnt[x] <= 100) q.push(x);
            cnt[x] ++;
        }
    }
}
void solve()
{
    mp.clear();
    g.clear();
    cin >> n >> m;
    g.resize(n + 1);
    rep(i, 1, n)
    {
        string s; cin >> s;
        mp[i] = s;
    }
    rep(i, 1, n)
    {
        int k; cin >> k;
        while(k --)
        {
            int v; cin >> v;
            g[i].push_back(v);
        }
    }
    bfs();
    vector<int> ans;
    rep(i, 1, n) if(cnt[i] > 100) ans.push_back(i);
    if(ans.empty()) cout << "No one is disturbed!";
    else
    {
        cout << ans.size() << endl;
        for(auto x:ans) cout << mp[x] << ' ';
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}
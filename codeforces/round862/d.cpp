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
const int N = 10 + 1e5, mod = 1e9 + 7;
bool sta[N];
void solve()
{
    int n; cin >> n;
    vector<vector<int>> g(n+1);
    rep(i, 1, n-1)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int a, b;
    int disa = 0, disb = 0;
    function<void(int, int, int)> dfs = [&](int v, int dis, int op) {
        bool flag = true;
        for(auto p:g[v])
        {
            if(!sta[p])
            {
                flag = false;
                sta[p] = true;
                dfs(p, dis + 1, op);
                sta[p] = false;
            }
        }
        if(flag)
        {
            if(disa < dis && op == 0)
            {
                disa = dis;
                a = v;
            }
            else if(disb < dis && op == 1)
            {
                disb = dis;
                b = v;
            }
        }
    };
    vector<int> dist1(n + 1, mod), dist2(n + 1, mod);

    function<void(int, vector<int>&)> bfs = [&](int root, vector<int>& dist) {
        dist[root] = 0;
        memset(sta, 0, sizeof(sta));
        sta[root] = true;
        queue<int> q;
        q.push(root);
        while(q.size())
        {
            auto t = q.front();
            q.pop();
            for(auto v:g[t])
            {
                if(!sta[v])
                {
                    q.push(v);
                    sta[v] = true;
                    dist[v] = dist[t] + 1;
                }
            }
        }
    };
    sta[1] = true;
    dfs(1, 0, 0);
    sta[1] = false;
    sta[a] = true;
    dfs(a, 0, 1);

    bfs(a, dist1);

    bfs(b, dist2);
    vector<int> ans(n + 1);
    rep(i, 1, n)
    {
        int v = max(dist1[i], dist2[i]) + 1;
        ans[v] ++;
    }
    int val = 1;
    rep(i, 1, n)
    {
        val += ans[i];
        cout << min(val, n) << ' ';
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
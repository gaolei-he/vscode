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
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> g[n+1];
    vector<int> deg(n+1, 0);
    rep(i, 1, m)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        deg[y] ++;
    }
    queue<int> q;
    rep(i, 1, n) if(!deg[i]) q.push(i);
    vector<int> ans;
    ans.push_back(0);
    while(q.size())
    {
        if(q.size() > 1)
        {
            cout << "No" << endl;
            return;
        }
        int t = q.front();
        ans.push_back(t);
        q.pop();
        for(auto v:g[t])
        {
            deg[v] --;
            if(!deg[v]) q.push(v);
        }
    }
    cout << "Yes\n";
    vector<int> res(n+1);
    rep(i, 1, n) res[ans[i]] = i;
    rep(i, 1, n) cout << res[i] << ' ';

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
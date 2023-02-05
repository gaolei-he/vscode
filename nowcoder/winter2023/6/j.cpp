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
const int N = 10 + 2e4, mod = 1e9 + 7;
map<string ,set<int>> query;
map<string, set<pii>> pro;
struct Node
{
    int op, t, w;
    string name;
}node[N], node1[N];

void solve()
{
    int n, T, R;
    cin >> n >> T >> R;
    int op, t, w;
    string name;
    
    rep(i, 1, n)
    {
        int op, t, w;
        string name;
        cin >> op >> t >> name;
        if(op==2) cin >> w;
        node[i].op = op, node[i].t = t;
        node[i].name = name, node[i].w = w;
    }
    rep(i, 1, n) node1[i] = node[i];
    sort(node+1, node+n+1, [](Node a, Node b){return a.t < b.t;});
    unordered_map<int, int> ans;
    rep(i, 1, n)
    {
        op = node[i].op, name = node[i].name;
        t = node[i].t, w = node[i].w;
        if(op == 2)
        {
            if(pro[name].empty()) pro[name].insert({-t, w});
            else pro[name].insert({-t, (*pro[name].begin()).second+w});
        }
        else
        {
            int tmp = t - t % T;
            int tmp1 = t;
            auto it = query[name].lower_bound(-t);
            if(it != query[name].end()) t = *it;
            else t = tmp;
            t = -max(-t, tmp);
            auto it1 = pro[name].lower_bound({t, 0});
            if(it1 == pro[name].end()) ans.insert({tmp1, 0});
            else ans.insert({tmp1, it1->second});
            query[name].insert(-tmp1-R);
        }
    }
    rep(i, 1, n)
    {
        if(node1[i].op == 1) cout << ans[node1[i].t] << endl;
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
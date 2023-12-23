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
class Node
{
public:
    int val, cost;
    Node(int v1, int v2) : val(v1), cost(v2) {}
    bool operator>(const Node &rhs) const
    {
        return val * (1ll << rhs.cost) > rhs.val * (1ll << cost);
    }
};
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> vec;
    int l = 0;
    rep(i, 1, q)
    {
        int x; cin >> x;
        if(x > l + 1) vec.push_back(x - l - 1);
        l = x;
    }
    if (l < n) vec.push_back(n - l);
    set<Node, greater<Node>> st;
    map<int, int> mp;
    rep(i, 1, m)
    {
        int x, y; cin >> x >> y;
        mp[x] = max(mp[x], y);
    }
    for(auto [k, v] : mp) st.insert(Node(v, k));
    // for(auto node : st) cerr << node.val << " " << node.cost << endl;
    int ans = 0;
    for(auto x : vec)
    {
        // cerr << x << endl;
        for(auto &node : st)
        {
            while((1ll << (node.cost)) <= x)
            {
                x -= (1ll << (node.cost));
                ans += node.val;
            }
        }
    }
    cout << ans << endl;
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
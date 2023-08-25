#include <bits/extc++.h>
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
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;
tree<pii, null_type, greater<pii>, rb_tree_tag, tree_order_statistics_node_update> tr;
void solve()
{
    int n, m, d; cin >> n >> m >> d;
    vector<int> vec;
    rep(i, 1, n)
    {
        int x; cin >> x;
        vec.push_back(x);
        tr.insert({x, i});
    }
    int sm = 0, tmp = m;
    for(auto &x : tr)
    {
        if(!tmp or x.first <= 0) break;
        sm += x.first;
        tmp--;
    }
    tmp = m - tmp;
    int ans = sm - d * n;
    dec(i, n, 0)
    {
        tr.erase({vec[i], i + 1});
        if(tr.order_of_key({vec[i], i + 1}) < tmp)
        {
            sm -= vec[i];
            tmp--;
        }
        auto it = tr.find_by_order(tmp);
        while(tmp < m and it != tr.end() and it -> first > 0)
        {
            sm += tr.find_by_order(tmp) -> first;
            tmp++;
            it = tr.find_by_order(tmp);
        }
        ans = max(ans, sm - d * i);
    }
    cout << ans << endl;
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
/*
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
const int N = 10 + 2e5, mod = 1e9 + 7;
int lowbit(int x) { return x & -x; }
int tr[N * 4], n, x;
int a[N], s[N];
int sum(int x)
{
    int res = 0;
    for(int i=x;i;i-=lowbit(i)) res += tr[i];
    return res;
}
void add(int x, int c)
{
    for(int i=x;i<=n;i+=lowbit(i)) tr[i] += c;
}
void solve()
{
    cin >> n >> x;
    rep(i, 1, n) cin >> a[i], s[i] = s[i - 1] + a[i];
    vector<int> vec;
    memset(a, 0, sizeof(a));
    rep(i, 1, n) vec.push_back(s[i]);
    sort(vec.begin(), vec.end());
    int num = 0;
    map<int, int> mp;
    for(auto x : vec)
    {
        // cerr << x << endl;
        if(!mp.count(x)) mp[x] = ++num;
        a[mp[x]] ++;
        // add(num, 1);
        // add(num + 1, -1);
    }
    rep(i, 1, n) add(i, a[i]);
    int sm = 0;
    // add(0, 1);
    // cerr << sum(5) << endl;
    // rep(i, 1, n) cerr << s[i] << ' ';
    dec(i, n, 1)
    {
        num = mp[s[i]];
        auto it = mp.upper_bound(s[i] - x);
        add(num, -1);
        if(it != mp.begin())
        {
            -- it;
             sm += sum(it->second);
        }
        if(s[i] >= x) sm ++;
    }
    cout << sm << endl;
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
}*/
#include <bits/extc++.h>
#define int long long
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
using pii = pair<int, int>;
signed main()
{
    int n, x; cin >> n >> x;
    vector<int> a(n + 1, 0), s(n + 1, 0);
    for(int i=1;i<=n;i++) cin >> a[i], s[i] = s[i - 1] + a[i];
    tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> tr;
    int ans = 0;
    tr.insert({0, 0});
    for(int i=1;i<=n;i++)
    {
        ans += tr.order_of_key({s[i]-x, n + 1});
        tr.insert({s[i], i});
    }
    cout << ans << endl;
    return 0;
}
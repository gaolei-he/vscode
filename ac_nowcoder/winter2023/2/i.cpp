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
using PII = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
int x[N];
void solve()
{
    int n; cin >> n;
    rep(i, 1, n) cin >> x[i];
    rep(i, 1, n) x[i] -= 1000000000000ll;
    int a, b, c, d;
    int v1, v2, v3, v4, v5;
    cin >> a >> b >> c >> d;
    cin >> v1 >> v2 >> v3 >> v4 >> v5;
    int ans = v1 * n;
    map<int, vector<PII>> mp;
    rep(i, 1, n)
    {
        mp[a-x[i]].push_back({v1, v2});
        mp[b-x[i]].push_back({v2, v3});
        mp[c-x[i]].push_back({v3, v4});
        mp[d+1-x[i]].push_back({v4, v5});
    }
    int res = ans;
    for(auto& p:mp)
    {
        for(auto i:p.second)
        {
            ans -= i.first;
            ans += i.second;
        }
        res = max(res, ans);
    }
    cout << res << endl;
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
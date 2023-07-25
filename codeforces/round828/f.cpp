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
void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    unordered_map<int, int> mp;
    for (int i = 0; i < a.size(); i++)
    {
        mp[a[i]] = i + 1;
    }
    int l = mp[0], r = mp[0];
    int ans = 1;
    int val = 0;
    rep(i, 2, n)
    {
        int tl = 1, tr = n;
        if(r - l + 1 <= i)
        {
            tl = max(tl, l - (i - (r - l + 1)));
            tr = min(tr, r + (i - (r - l + 1)));
            ans += tr - tl + 1 - i + 1;
        }
        if(i % 2 == 0)
        {
            val ++;
            int pos = mp[val];
            if(pos < l) l = pos;
            if(pos > r) r = pos;
        }
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
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
    unordered_map<int, int> mp;
    vector<int> vec(n);
    int mx = 0;
    for(auto &x : vec)
    {
        cin >> x;
        mx = max(mx, x);
        mp[x]++;
    }
    int ans = 0;
    for(auto [x, v] : mp)
        for(int b = 2;  x * b * b <= mx; b ++)
        {
            int v1, v2, v3;
            bool flag = true;
            if(mp.count(x)) v1 = mp[x];
            else flag = false;
            if(mp.count(x * b)) v2 = mp[x * b];
            else flag = false;
            if(mp.count(x * b * b)) v3 = mp[x * b * b];
            else flag = false;
            if(flag)
                ans += v1 * v2 * v3;
        }
    for(auto [k, v] : mp)
        if(v >= 3)
            ans += v * (v - 1) * (v - 2);
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
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
#define int __int128_t
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
    map<int, int> mp;
    long long n; cin >> n;
    while(n--)
    {
        long long x; cin >> x;
        mp[(int)x] ++;
    }
    long long q; cin >> q;
    function<int(int)> f = [&](int delta) {
        int l = 0, r = delta;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(mid * mid > delta) r = mid - 1;
            else l = mid;
        }
        if(l * l != delta) return (int)-1;
        return l;
    };
    function<int(int, int)> calc = [&](int x, int y) {
        int delta = x * x - 4 * y;
        int sq = f(delta);
        if(sq < 0) return (int)0;
        int res = 0;
        int x1 = x + sq;
        int tmp = linf;
        if(x1 % 2 == 0)
        {
            res += mp[x1/2] * mp[x - x1/2];
            tmp = x - x1/2;
            if(x1/2 == tmp) res -= mp[x1/2] * mp[tmp] - mp[x1/2] * (mp[tmp] - 1) / 2;
        }
        x1 = x - sq;
        if(x1 % 2 == 0 and tmp != x1 / 2) 
        {
            res += mp[x1 / 2] * mp[x - x1/2];
            tmp = x - x1/2;
            if(x1/2 == tmp) res -= mp[x1/2] * mp[tmp] - mp[x1/2] * (mp[tmp] - 1) / 2;
        }
        return res;
    };
    while(q--)
    {
        long long x, y; cin >> x >> y;
        int ans = calc(x, y);
        cout << (long long)ans << ' ';
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long t; cin >> t;
    while(t--)
        solve();

    return 0;
}
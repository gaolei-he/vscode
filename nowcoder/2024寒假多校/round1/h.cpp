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
    int n, m; cin >> n >> m;
    vector<pii> vec(n);
    for(auto &[x, y] : vec) cin >> x >> y;
    int ans = 0;
    rep(i, 0, 30)
    {
        int tm = m;
        if((tm >> i) & 1) tm ^= (1 << i);
        else continue;
        rep(j, 0, i - 1) tm >>= 1;
        rep(j, 0, i - 1) tm <<= 1;
        int tmp = 0;
        // cerr << tm << endl;
        for(auto [x, y] : vec)
        {
            int val = (y | tm) - tm;
            if(val < (1 << i)) tmp += x;
        }
        ans = max(ans, tmp);
    }
    int tmp = 0;
    for(auto [x, y] : vec)
    {
        if((y | m) - m == 0) tmp += x;
    }
    ans = max(ans, tmp);
    cout << ans << endl;

}

/*
4 11 1011
5 8 1000
1 4 0100
1 5 0101
1 1 0001
*/
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
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
int a[N], s[40][N];
void solve()
{
    int n; cin >> n;
    rep(i, 1, n)
    {

        int x; cin >> x;
        a[i] = x;
        rep(j, 0, 31)
        {
            s[j][i] = 0;
            if((x >> j) & 1) s[j][i] = 1;
            s[j][i] += s[j][i - 1];
        }
    }
    int q; cin >> q;
    auto check = [&](int l, int r, int k) {
        int val = 0xffffffff;
        rep(i, 0, 31)
        {
            if(s[i][r] - s[i][l - 1] < r - l + 1) val ^= (1ll << i);
        }
        return val >= k;
    };
    // cout << check(1, 5, 7) << endl;
    while(q --)
    {
        int k, v; cin >> v >> k;
        int l = v, r = n;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(check(v, mid, k)) l = mid;
            else r = mid - 1;
        }
        if(check(v, l, k)) cout << l << ' ';
        else cout << -1 << ' ';
    }
    cout << endl;
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
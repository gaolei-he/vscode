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
const int N = 10 + 4e5, mod = 998244353;
int a[N], s[N];
int f(int n, int l1, int r1, int l2, int r2)
{
    if(l1 > l2)
    {
        swap(l1, l2);
        swap(r1, r2);
    }
    int r3 = n - l1;
    int l3 = r3 - (r1 - l1);
    int ans = 0;
    if(r2 >= l3 && r2 <= r3)
    {
        ans = r2 - max(l3, l2) + 1;
    }
    else if(l2 >= l3 && l2 <= r3)
    {
        ans = min(r3, r2) - l2 + 1;
    }
    else if(l2 < l3 && r2 > r3) ans = r3 - l3 + 1;
    else ans = 0;
    return ans;
}
PII qu[N];
void solve()
{
    int n, m, ans = 0;
    cin >> n >> m;
    rep(i, 1, m)
    {
        int l, r; cin >> l >> r;
        qu[i] = {l, r};
        s[l] ++, s[r+1]--;
    }
    rep(i, 1, n) s[i] += s[i-1];
    rep(i, 1, n) ans = (ans + s[i] * s[n-i]) % mod;
    rep(i, 1, m)
    {
        auto it = qu[i];
        int tmp = f(n, it.first, it.second, it.first, it.second);
        ans = ans - tmp;
        if(ans < 0) ans += mod;
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
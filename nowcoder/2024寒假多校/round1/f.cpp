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
int qp(int a, int b)
{
    int ans = 1;
    while(b)
    {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
void solve()
{
    int n, m; cin >> n >> m;
    if(m > n)
    {
        cout << 0 << endl;
        return;
    }
    vector<int> fact(n + 1, 1), infact(n + 1, 1);
    rep(i, 1, n)
    {
        fact[i] = fact[i - 1] * i % mod;
        infact[i] = infact[i - 1] * qp(i, mod - 2) % mod;
    }
    int ans = 0;
    rep(i, 0, m)
    {
        int val = qp(i, n) * infact[i] % mod * infact[m - i] % mod;
        if((m - i) % 2 == 0) ans += val;
        else ans -= val;
        ans = (ans + mod) % mod;
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int t; cin >> t;
    int t = 1;
    while(t--)
        solve();

    return 0;
}
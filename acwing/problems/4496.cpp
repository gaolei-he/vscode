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
#define ll long long
#define int long long
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e3, mod = 998244353;
int fact[N];
int invfact[N];
int qpow(int a, int b)
{
    int res = 1;
    while(b)
    {
        if(b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void solve()
{
    fact[0] = fact[1] = 1;
    rep(i, 2, N - 1)
        fact[i] = fact[i - 1] * i % mod;
    invfact[0] = invfact[1] = 1;
    rep(i, 2, N - 1)
        invfact[i] = invfact[i - 1] * qpow(i, mod - 2) % mod;
    int n, m, k;
    cin >> n >> m >> k;
    int ans = fact[n - 1] * m % mod * invfact[k] % mod * invfact[n - 1 - k] % mod;
    rep(i, 1, k)
        ans = ans * (m - 1) % mod;
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
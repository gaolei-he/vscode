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
using pii = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
int a[N];
int qp(int a, int b, int p = mod)
{
    int res = 1 % p;
    while(b)
    {
        if(b & 1) res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return res;
}
int inv(int a, int p = mod)
{
    return qp(a, p - 2);
}
void solve()
{
    int n; cin >> n;
    rep(i, 1, n)
    {
        int x; cin >> x;
        a[1] ++;
        a[x + 1] --;
    } 
    rep(i, 1, N-5) a[i] += a[i-1];
    int lst = 1, ans = 0;
    rep(i, 1, N)
    {
        if(!a[i]) break;
        int q = (i+1)*inv(i) % mod;
        int a1 = lst * q % mod;
        ans = ans + (1 - qp(q, a[i]) + mod) % mod * inv((1-q+mod) % mod) % mod * a1 % mod;
        ans %= mod;
        lst = a1 * qp(q, a[i]-1) % mod;
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
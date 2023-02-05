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
int n, m;
int qp(int a, int b, int p = mod)
{
    int res = 1;
    while(b)
    {
        if(b&1) res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return res;
}
int fact[N], inv[N];
vector<pii> vec;
void g(int x, int y)
{
    int a = x - 1;
    int b = y - 1;
    a += b;
    vec.push_back({a, b});
}
map<pii, int> mp;
int f(int a, int b)
{
    int res = fact[a] * inv[b] % mod * inv[a-b] % mod;
    for(auto p:vec)
    {
        if(p.first < a)
        {
            if(b >= p.second && b <= p.second + a - p.first)
            {
                int tmp;
                if(mp.count(p)) tmp = mp[p];
                else tmp = fact[p.first] * inv[p.second] % mod * inv[p.first-p.second] % mod;
                int x = a - p.first;
                int y = b - p.second;
                tmp = tmp * fact[x] % mod * inv[y] % mod * inv[x-y] % mod;
                res = (res - tmp + mod) % mod;
            }
        }
    }
    mp[{a, b}] = res;
    return res * qp(2, n-1-a) % mod;
}
void solve()
{
    cin >> n >> m;
    fact[0] = inv[0] = 1;
    rep(i, 1, n)
    {
        fact[i] = fact[i-1] * i % mod;
        inv[i] = inv[i-1]*qp(i, mod-2, mod)%mod;
    }
    int ans = qp(2, n-1);
    rep(i, 1, m)
    {
        int x, y;
        cin >> x >> y;
        g(x, y);
    }
    sort(vec.begin(), vec.end());
    for(auto p:vec)
        ans = (ans - f(p.first, p.second) + mod) % mod;

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
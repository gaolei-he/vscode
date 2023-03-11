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
const int N = 10 + 1e5, mod = 1e9 + 7;
ll exgcd(ll a, ll b, ll &x, ll &y)// 拓欧
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}
ll inv(ll a, ll p)
{
    ll x, y;
    if (exgcd(a, p, x, y) != 1) // 无解的情形
        return -1;
    return (x % p + p) % p;
}
int qp(int a, int b, int p)
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
void solve()
{
    int a, x, m;
    cin >> a >> x >> m;
    if(a == 1)
    {
        cout << x % m << endl;
    }
    int in = inv(a-1, m);
    if(in == -1)
    cout << (qp(a, x, m) - 1 + m) % m *  % m << endl;
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
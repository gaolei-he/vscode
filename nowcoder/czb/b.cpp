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
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
#define ll long long
#define int long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using PII = pair<int, int>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1), b(m+1);
    dec(i, n, 1) cin >> a[i];
    dec(i, m, 1) cin >> b[i];
    vector<int> c(max(n, m) + 1);
    int p = 0;
    rep(i, 1, max(n, m))
    {
        if(i <= n) p += a[i];
        if(i <= m) p += b[i];
        if(p > i) c[i] = p - i - 1, p = 1;
        else c[i] = p, p = 0;
    }
    if(p)
    {
        c[max(n, m) + 1] = 1;
        p = max(n, m) + 1;
    }
    else p = max(n, m);
    dec(i, p, 1) cout << c[i] << ' ';
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
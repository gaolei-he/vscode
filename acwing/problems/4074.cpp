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
const int N = 10 + 400, mod = 1e9 + 7;
int d[N][N];
int n, m;
int floyd()
{
    rep(k, 1, n)
        rep(i, 1, n)
            rep(j, 1, n)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    if(d[1][n] < linf) return d[1][n];
    return -1;
}
void solve()
{
    cin >> n >> m;
    memset(d, 0x3f, sizeof(d));
    rep(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        d[u][v] = 1;
        d[v][u] = 1;
    }
    if(d[1][n] == 1)
    {
        rep(i, 1, n)
        {
            rep(j, 1, n)
            {
                if(d[i][j] == 1) d[i][j] = linf;
                else d[i][j] = 1;
            }
        }

    }
    rep(i, 1, n) d[i][i] = 0;
    cout << floyd() << endl;
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
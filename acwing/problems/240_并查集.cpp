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
const int N = 10 + 5e4, mod = 1e9 + 7;
int p[N], d[N];
int find(int x)
{
    if(p[x] != x)
    {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}
set<pii> st;
void solve()
{
    int n, k; cin >> n >> k;
    int ans = 0;
    rep(i, 1, n) p[i] = i;
    while(k --)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if(x > n || y > n) ans ++;
        else
        {
            int px = find(x), py = find(y);
            if(op == 1)
            {
                if(px == py && (d[x]-d[y])%3) ans ++;
                else if(px != py)
                {
                    p[px] = py;
                    d[px] = d[y] - d[x];
                }
            }
            else if(op == 2)
            {
                if(px == py && (d[x]-d[y]-1) % 3) ans ++;
                else if(px != py)
                {
                    p[px] = py;
                    d[px] = d[y] - d[x] + 1;
                }
            }

        }
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
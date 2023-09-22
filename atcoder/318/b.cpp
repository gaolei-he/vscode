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
const int N = 10 + 1e2, mod = 1e9 + 7;
bool vis[N][N];
void solve()
{
    int n; cin >> n;
    while(n --)
    {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        rep(i, x1+1, y1)
            rep(j, x2+1, y2)
                vis[i][j] = true;
    }
    int ans = 0;
    rep(i, 0, 100)
        rep(j, 0, 100)
            if(vis[i][j]) ans ++;
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
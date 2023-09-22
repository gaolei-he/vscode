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
const int N = 10 + 10, mod = 1e9 + 7;
int d[N][N];
bool vis[N];
void solve()
{
    int n; cin >> n;
    int op = 0;
    if(n & 1) op = 1;
    rep(i, 1 + op, n + op - 1)
        rep(j, i + 1, n + op)
            cin >> d[i][j];
    n += op;
    int ans = 0;
    function<void(int, int)> dfs = [&](int cnt, int val) {
        ans = max(ans, val);
        if(cnt >= n) return;
        if(vis[cnt]) dfs(cnt + 1, val);
        else
        {
            vis[cnt] = true;
            rep(i, cnt + 1, n)
            {
                if(!vis[i])
                {
                    vis[i] = true;
                    dfs(cnt + 1, val + d[cnt][i]);
                    vis[i] = false;
                }
            }
            vis[cnt] = false;
        }
        // dfs(cnt + 1, val);
    };
    dfs(1, 0);
    // dfs(2, 0);
    // if(n & 1) exit(-1);
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
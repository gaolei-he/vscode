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
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 15+5e3, mod = 1e9 + 7;
int s[N][N];
void solve()
{
    int n, r; cin >> n >> r;
    rep(i, 1, n)
    {
        int x, y, w;
        cin >> x >> y >> w;
        x ++, y ++;
        s[x][y] += w;
    }
    rep(i, 1, N-5)
        rep(j, 1, N-5)
            s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];

    int ans = 0;
    rep(i, 1, N-9)
        rep(j, 1, N-9)
        {
            ans = max(ans, s[min(i+r-1, N-8)][min(j+r-1, N-8)] + s[i-1][j-1] - s[min(i+r-1, N-8)][j-1] - s[i-1][min(j+r-1, N-8)]);
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
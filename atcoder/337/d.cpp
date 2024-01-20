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
#include <regex>
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
const int N = 10 + 1e5, mod = 1e9 + 7;
void solve()
{
    int h, w; cin >> h >> w;
    int k; cin >> k;
    vector<string> vec(h + 1);
    rep(i, 1, h)
    {
        string tmp; cin >> tmp;
        tmp = " " + tmp;
        vec[i] = tmp;
    }
    vector<vector<int>> sm(h + 1, vector<int>(w + 1, 0)), judge(h + 1, vector<int>(w + 1, 0));
    rep(i, 1, h)
        rep(j, 1, w)
        {
            sm[i][j] = sm[i-1][j] + sm[i][j-1] - sm[i-1][j-1];
            if(vec[i][j] == 'o') sm[i][j] += 1;
            judge[i][j] = judge[i-1][j] + judge[i][j-1] - judge[i-1][j-1];
            if(vec[i][j] == 'x') judge[i][j] += 1;
            // cerr << judge[i][j];
        }
    int ans = linf;
    rep(i, 1, h)
        rep(j, 1, w)
        {
            int r = j + k - 1;
            // if(r <= w) cerr << judge[i][r] - judge[i][j-1] << endl;
            if(r <= w and judge[i][r] - judge[i][j-1] - judge[i-1][r] + judge[i-1][j-1] == 0)
                ans = min(ans, k - (sm[i][r] - sm[i][j-1] - sm[i-1][r] + sm[i-1][j-1]));
            int l = i + k - 1;
            if(l <= h and judge[l][j] - judge[l][j-1] - judge[i-1][j] + judge[i-1][j-1] == 0)
                ans = min(ans, k - (sm[l][j] - sm[i-1][j] - sm[l][j-1] + sm[i-1][j-1]));
        }
    if(ans == linf) ans = -1;
    cout << ans << endl;


}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    // int t; cin >> t;
    t = 1;
    while(t--)
        solve();

    return 0;
}
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
const int N = 10 + 1e5, mod = 1e9 + 7;
char str[110][20];
int lowbit(int x){ return x & (-x);}
int count_one(int val)
{
    int res = 0;
    while(val)
    {
        val -= lowbit(val);
        res ++;
    }
    return res;
}
bool check(int x)
{
    while(x) 
    {
        if((x & 7) != lowbit(x & 7)) return true;
        x >>= 1;
    }
    return false;
}
void solve()
{
    int n, m; cin >> n >> m;
    rep(i, 1, n) cin >> str[i];
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(1 << m, vector<int>(1 << m, 0)));
    rep(i, 1, n)
    {
        int tmp = i;
        i = i & 1;
        rep(j, 0, (1 << m) - 1)
        {
            bool flag = false;
            rep(k, 0, m - 1)
                if(str[tmp][k] == 'H' and (j & (1 << k))) flag = true;
            if(flag) continue;
            rep(k, 0, (1 << m) - 1)
            {
                if(j & k) continue;
                else if(check(j) or check(k)) continue;
                rep(l, 0, (1 << m) - 1)
                    if(l & j) continue;
                    else dp[i][j][k] = max(dp[i][j][k], dp[i^1][k][l] + count_one(j));
            }
        }
        i = tmp;
    }
    int ans = 0;
    rep(i, 0, (1 << m) - 1)
        rep(j, 0, (1 << m) - 1)
            ans = max(ans, dp[n&1][i][j]);
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
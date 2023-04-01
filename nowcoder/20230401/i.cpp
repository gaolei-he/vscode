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
const int N = 10 + 1e3, mod = 1e9 + 7;
int a[N], b[N];
pair<int, pii> dp[N][N];
void solve()
{
    int n; cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    rep(i, 1, n)
    {
        if(a[i] == 0)
        {
            if(dp[i-1][0].first & 1) dp[i][0].first = dp[i-1][0].first + 1;
            else dp[i][0].first = dp[i-1][0].first + 2;
        }
        else
        {
            if(dp[i-1][0].first & 1) dp[i][0].first = dp[i-1][0].first + 2;
            else dp[i][0].first = dp[i-1][0].first + 1;
        }
        dp[i][0].second.first = dp[i][0].first;
    }
    rep(i, 1, n)
    {
        if(b[i] == 0)
        {
            if(dp[0][i-1].first & 1) dp[0][i].first = dp[0][i-1].first + 1;
            else dp[0][i].first = dp[0][i-1].first + 2;
        }
        else
        {
            if(dp[0][i-1].first & 1) dp[0][i].first = dp[0][i-1].first + 2;
            else dp[0][i].first = dp[0][i-1].first + 1;
        }
        dp[0][i].second.second = dp[i][i].first;
    }
    rep(i, 1, n)
    {
        rep(j, 1, n)
        {
            dp[i][j].first = max(dp[i-1][j].first, dp[i][j-1].first);
            if(a[i] == 0)
            {
                if(dp[i-1][j].second.first & 1) dp[i][j].second.first = dp[i-1][j].second.first + 1;
                else dp[i][j].first = dp[i-1][j].second.first + 2;
            }
            else if(a[i] == 1)
            {
                if(dp[i-1][j].second.first & 1) dp[i][j].second.first = dp[i-1][j].second.first + 2;
                else dp[i][j].first = dp[i-1][j].second.first + 1;
            }
            dp[i][j].second.first = dp[i][j].first;
            if(b[i] == 0)
            {
                if(dp[i][j-1].second.second & 1) dp[i][j].second.second = min(dp[i][j].second.second, dp[i][j-1].second.second + 1);
                else dp[i][j].first = min(dp[i][j].first, dp[i][j-1].second.second + 2);
            }
            else if(b[i] == 1)
            {
                if(dp[i][j-1].second.second & 1) dp[i][j].first = min(dp[i][j].first, dp[i][j-1].second.second + 2);
                else dp[i][j].first = min(dp[i][j].first, dp[i][j-1].second.second + 1);
            }
            dp[i][j].second.second = dp[i][j].first;
        }
    }
    rep(i, 0, n)
    {
        rep(j, 0, n)
            cerr << dp[i][j].first << ' ';
        cerr << endl;
    }
    cout << dp[n][n].first << endl;
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
/*

12 34 56 78 9,10 11,12 13,14 15,16 17,18 19,20 21,22
2 4  7 9, ,12 13,14 15,16 17,18 19,20 21,22
2 4   9, , 13, 15, 17, 19, 21,
*/
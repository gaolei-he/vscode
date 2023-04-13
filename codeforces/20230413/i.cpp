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
const int N = 10 + 2e3, mod = 1e9 + 7;
int k, d;
char str[N];
int dp[N][110];
int sm[N];
void solve()
{
    memset(sm, 0, sizeof(sm));
    memset(dp, 0, sizeof(dp));
    cin >> k >> d;
    cin >> str + 1;
    int n = strlen(str + 1);
    rep(i, 1, n)
        if(str[i] == '0') sm[i] = sm[i-1] + 1;
        else sm[i] = sm[i-1];
    
    rep(i, 1, n)
    {
        rep(j, 0, k)
        {
            if(i >= d && j >= (sm[i] - sm[i-d])) dp[i][j] = max(dp[i-1][j], dp[i-d][j-(sm[i] - sm[i-d])] + 1);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][k] << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}
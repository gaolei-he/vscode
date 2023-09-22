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
const int N = 10 + 1e5, mod = 998244353;
int dp[2][62][8], sm[2][8];
void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;
    int op = 1;
    function<int(char)> inconvert = [](char c) {
        if(c >= 'A' and c <= 'Z') return c - 'A';
        else if(c >= 'a' and c <= 'z') return c - 'a' + 26;
        else if(c >= '0' and c <= '9') return c - '0' + 52;
        else return 0;
    };
    if(s[1] >= 'A' and s[1] <= 'Z' or s[1] >= '0' and s[1] <= '9')
    {
        if(s[1] >= 'A') dp[1][inconvert(s[1])][1] = 1;
        else dp[1][inconvert(s[1])][4] = 1;
    }
    else if(s[1] >= 'a' and s[1] <= 'z')
    {
        dp[1][inconvert(s[1])][2] = 1;
        dp[1][inconvert(s[1] - 32)][1] = 1;
    }
    else if(s[1] == '?')
    {
        rep(i, 0, 61)
        {
            int k;
            if(i < 26) k = 1;
            else if(i < 52) k = 2;
            else k = 4;
            dp[1][i][k] = 1;
        }
    }
    rep(k, 0, 7) rep(i, 0, 61) sm[1][k] += dp[1][i][k];
    rep(i, 2, n)
    {
        int l = 0, r = 61;
        if(s[i] >= 'A' and s[i] <= 'Z' or s[i] >= '0' and s[i] <= '9') l = inconvert(s[i]), r = l;
        else if(s[i] >= 'a' and s[i] <= 'z') l = inconvert(s[i]) - 26, r = l;
        if(op) op--;
        else op ++;
        rep(j, 0, 61)
        {
            if(j < l or j > r)
            {
                rep(k, 0, 7)dp[op][j][k] = 0;
                continue;
            }
            rep(k, 0, 7)
            {
                dp[op][j][k] = (sm[op?0:1][k] + mod - dp[op?0:1][j][k]) % mod;
                int t;
                if(j < 26) t = 1;
                else if(j < 52) t = 2;
                else t = 4;
                if(!(t & k)) dp[op][j][k] = 0;
                else if(t & k) dp[op][j][k] = (dp[op][j][k] + sm[op?0:1][k^t] + mod - dp[op?0:1][j][k^t]) % mod;
            }
        }
        if(s[i] >= 'a' and s[i] <= 'z')
        {
            l += 26, r += 26;
            rep(j, 0, 61)
            {
                if(j < l or j > r)
                {
                    if(j != l - 26) rep(k, 0, 7)dp[op][j][k] = 0;
                    continue;
                }
                rep(k, 0, 7)
                {
                    dp[op][j][k] = (sm[op?0:1][k] - dp[op?0:1][j][k] + mod) % mod;
                    int t;
                    if(j < 26) t = 1;
                    else if(j < 52) t = 2;
                    else t = 4;
                    if(!(t & k)) dp[op][j][k] = 0;
                    else if(t & k) dp[op][j][k] = (dp[op][j][k] + sm[op?0:1][k^t] + mod - dp[op?0:1][j][k^t]) % mod;
                }
            }
        }
        rep(t1, 0, 7) sm[op][t1] = 0;
        rep(t1, 0, 7) rep(t2, 0, 61) sm[op][t1] = (sm[op][t1] + dp[op][t2][t1]) % mod;
    }
    cout << sm[op][7] << endl;
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
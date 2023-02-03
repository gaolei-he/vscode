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
const int N = 10 + 5e3, mod = 1e9 + 7;
int w[N], v[N];
int dpz[N][N], dpf[N][N];
int n, m;
int mxz[N], mxf[N];
void work(int dp[N][N])
{
    rep(i, 1, n)
        rep(j, 0, m)
        {
            dp[i][j] = dp[i-1][j];
            if(j>=w[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
        }
}
void solve()
{
    cin >> n >> m;
    rep(i, 1, n) cin >> w[i] >> v[i];
    work(dpz);
    reverse(w+1, w+n+1);
    reverse(v+1, v+n+1);
    work(dpf);
    reverse(w+1, w+n+1);
    reverse(v+1, v+n+1);
    rep(i, 1, n)
    {
        int vmx = 0, vmxi = 0;
        memset(mxz, 0, sizeof(mxz));
        memset(mxf, 0, sizeof(mxf));
        rep(j, 1, m) mxz[j] = max(mxz[j-1], dpz[i-1][j]);
        rep(j, 1, m) mxf[j] = max(mxf[j-1], dpf[n-i][j]);
        rep(j, 0, m)
        {
            vmx = max(vmx, mxz[j] + mxf[m-j]);
            if(m-j-w[i]>=0) vmxi = max(vmxi, mxz[j]+mxf[m-j-w[i]]+v[i]);
            if(m-j-w[i]>=0) vmxi = max(vmxi, mxf[j]+mxz[m-j-w[i]]+v[i]);
        }
        cout << max(vmx - vmxi + 1, 0ll) << endl;
    }
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
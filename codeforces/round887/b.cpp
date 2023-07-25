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
vector<vector<int>> mul(vector<vector<int>> a, vector<vector<int>> b)
{
    int n = a.size();
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a[i].size(); j++)
            for (int k = 0; k < a[i].size(); k++)
                {
                    res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
                }
    return res;
}
vector<vector<int>> qp(vector<vector<int>>& a, int b, int mod)
{
    int n = a.size();
    vector<vector<int>> res(n, vector<int>(n));
    for(int i=0;i<a.size();i ++) res[i][i] = 1;
    while(b)
    {
        if(b & 1) res = mul(res, a);
        b >>= 1;
        a = mul(a, a);
    }
    return res;
}
void solve()
{
    int n, k; cin >> n >> k;
    vector<int> f(40, 1);
    rep(j, 3, 30) f[j] = f[j-1] + f[j-2];
    rep(i, 1, 30) cout << f[i] << ' ';
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
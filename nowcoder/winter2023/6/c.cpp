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
const int N = 10 + 1e3, mod = 1e9 + 7;
int f[N][N];
void solve()
{
    int n; cin >> n;
    f[1][1] = 1;
    rep(i, 2, n)
        rep(j, 1, i)
            f[i][j] = (f[i-1][j] + f[i-1][j-1]) % mod;

    queue<int> q;
    stack<int> stk;
    rep(i, 1, n)
        if(i&1) q.push(i);
        else stk.push(i);
    vector<int> res;
    res.push_back(0);
    while(q.size()) {res.push_back(q.front()); q.pop();}
    while(stk.size()) {res.push_back(stk.top()); stk.pop();}
    int ans = 0;
    rep(i, 1, n) ans = (ans + res[i] * f[n][i]) % mod;
    cout << ans << endl;
    rep(i, 1, n) cout << res[i] << ' ';
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
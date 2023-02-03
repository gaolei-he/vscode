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
using PII = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
int f[N];
int a[N];
int tmp[N];
int tmp1[N];

void solve()
{
    int n;
    cin >> n;
    rep(i, 2, n) cin >> f[i];
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) tmp[i] = 1;
    vector<vector<int>> vec(n+1);
    rep(i, 2, n) vec[f[i]].push_back(i);

    function<void(int, int)> dfs = [&](int k, int cnt) {
        tmp[k] = cnt;

        if(vec[k].empty()) return;
        for(auto i:vec[k]) dfs(i, cnt+1);

    };
    dfs(1, 1);

    sort(tmp + 1, tmp + 1 + n);
    sort(a + 1, a + 1 + n);
    int ans = 0;
    rep(i, 1, n) ans += tmp[i] * a[i];
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
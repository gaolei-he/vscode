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
const int N = 10+1e5, mod = 1e9 + 7;
int a[N], b[N], c[N];
int d[N], f[N];
void solve()
{
    unordered_map<int, int> mp;
    memset(d, 0x3f, sizeof(d));
    int n; cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    rep(i, 1, n) mp[a[i]] = i;
    rep(i, 1, n) c[i] = mp[b[i]];
    int cnt = 0;
    rep(i, 1, n)
    {
        f[i] = 1;
        int l = 1, r = cnt;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(d[mid] > c[i]) r = mid - 1;
            else l = mid;
        }
        if(d[r] < c[i]) f[i] = r + 1;
        else f[i] = 1;
        d[f[i]] = min(d[f[i]], c[i]);
        cnt = max(cnt, f[i]);
    }
    int ans = 0;
    rep(i, 1, n) ans = max(ans, f[i]);
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
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
int a[N], s[N], n;
int f(int k)
{
    int l = k, r = k + n - 2;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(s[mid] - s[k-1] < s[n] - s[mid] + s[k-1]) l = mid + 1;
        else r = mid;
    }
    // cerr << l << endl;
    // cerr << s[n] << endl;
    int res = s[n] - s[l] + s[k-1];
    if(res >= s[l] - s[k-1]) return s[l] - s[k-1];
    if(l == k) return res;
    l--;
    res = max(res, s[l]-s[k-1]);
    return res;
}
void solve()
{
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) s[i] = s[i-1] + a[i];
    rep(i, n+1, n*2) s[i] = s[i-1] + a[i-n];
    int ans = 0;
    rep(i, 1, n) ans = max(ans, f(i));
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
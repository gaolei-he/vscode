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
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using PII = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 2e5, mod = 1e9 + 7;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, 0, n-1) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 2e9+1;
    int i = 0, j = 0;
    for(;i<n;i++)
    {
        while(i <= j && i + n - j - 1 + min(i, n-j-1) > m && j < n) j ++;
        if(j == n) j--;
        if(i+n-j-1+min(i, n-j-1) <= m) ans = min(ans, a[j]-a[i]);
        // cout << ans << endl;
        if(i == j) j++;
    }
    cout << ans;
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
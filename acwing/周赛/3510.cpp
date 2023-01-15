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
const int N = 10 + 1e6, mod = 1e9 + 7;
int a[N], id[N], f[N], tmp[N];
void solve()
{
    int n; cin >> n;
    rep(i, 1, n)
    {
        int x; cin >> x;
        id[x] = i;
    }
    int n1 = 0;
    rep(i, 1, n)
    {
        int x; cin >> x;
        int t = id[x];
        if(t) a[++n1] = t;
    }
    int cnt = 0;
    memset(tmp, 0x3f, sizeof(tmp));
    rep(i, 1, n1)
    {
        int l = 1, r = cnt;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(tmp[mid] > a[i]) r = mid - 1;
            else l = mid;
        }
        if(tmp[r] < a[i]) f[i] = r + 1;
        else f[i] = 1;
        tmp[f[i]] = min(tmp[f[i]], a[i]);
        cnt = max(cnt, f[i]);
    }
    int ans = 0;
    rep(i, 1, n1) ans = max(ans, f[i]);
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
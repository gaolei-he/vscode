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
const int N = 10 + 5e3, mod = 1e9 + 7;
int a[N];
int tmp[N], mp[N];
void solve()
{
    int n, p;
    cin >> n >> p;
    memset(tmp, 0, sizeof(tmp));
    memset(mp, 0, sizeof(mp));
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n)
        rep(j, 1, n)
        {
            if(i != j) mp[a[i]*a[j]%p] ++;
            if(i != j) tmp[(a[i]*a[j]+a[i]) % p] ++, tmp[(a[i]*a[j]+a[j]) % p] ++;
        }
    rep(x, 0, p-1)
    {
        int ans = 0;
        rep(k, 1, n)
            ans += mp[(p + x - a[k] % p) % p];

        cout << ans - tmp[x] << ' ';
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
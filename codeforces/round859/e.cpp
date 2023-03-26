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
const int N = 10 + 2e5, mod = 1e9 + 7;
int a[N], s[N];
void f(int l, int r)
{
    if(l >= r)
    {
        cout << "! " << l << endl << flush;
        return;
    }
    int mid = l + r >> 1;
    cout << "? " << mid - l + 1;
    rep(i, l, mid) cout << " " << i;
    cout << endl << flush;
    int sm; cin >> sm;
    if(sm > s[mid] - s[l-1]) f(l, mid);
    else f(mid + 1, r);
}
void solve()
{
    int n; cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) s[i] = s[i-1] + a[i];
    f(1, n);
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
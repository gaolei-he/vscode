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
int a[N], b[N], sa[N], sb[N];
void solve()
{
    int n;
    cin >> n;
    rep(i, 1, n)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b+1, b+n+1);
    rep(i, 1, n)
    {
        sa[i] = sa[i-1] + a[i];
        sb[i] = sb[i-1] + b[i];
    }
    int m;
    cin >> m;
    rep(i, 1, m)
    {
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1) cout << sa[r] - sa[l-1] << endl;
        else cout << sb[r] - sb[l-1] << endl;
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
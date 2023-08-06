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
int a[N], s[3][N];
void solve()
{
    int n, q; cin >> n >> q;
    rep(i, 1, n) cin >> a[i];
    int op = 0;
    rep(i, 1, n)
    {
        rep(j, 0, 2) s[j][i] = 0;
        if(a[i] & 1) s[2][i] = s[2][i - 1] + 1;
        else s[2][i] = s[2][i - 1];
        if(a[i] % 2 == 0) s[op][i] = s[op][i - 1] + 1, s[op^1][i] = s[op^1][i - 1];
        else s[op][i] = s[op][i - 1], op ^= 1, s[op][i] = s[op][i - 1];
        // rep(j, 0, 2) cerr << s[j][i] << " ";
        // cerr << endl;
    }
    while(q --)
    {
        int l, r, k; cin >> l >> r >> k;
        int val = s[2][r] - s[2][l - 1];
        if(val & 1)
        {
            cout << "NO" << endl;
            continue;
        }
        int mx = val / 2;
        if(s[2][l-1] & 1) mx += s[1][r] - s[1][l - 1];
        else mx += s[0][r] - s[0][l - 1];
        if(mx >= k) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
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
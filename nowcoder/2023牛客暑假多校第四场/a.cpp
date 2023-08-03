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
const int N = 10 + 3e3, mod = 1e9 + 7, P = 131;
char str[N];
ull h[N], p[N];
void solve()
{
    int n; cin >> n;
    cin >> str + 1;
    int len = strlen(str + 1);
    memset(str + 1 + len, '0', n);
    memcpy(str + 1 + len + n, str + 1, len);
    rep(i, 1, n + len + len) h[i] = h[i - 1] * P + str[i];
    auto has = [&](int l, int r) {
        return h[r] - h[l - 1] * p[r - l + 1];
    };
    rep(i, 2, len + n)
    {
        if(has(i, i + len - 1) != has(1, len)) continue;
        rep(j, 1, n) cout << '1';
        cout << endl;
        return;
    }
    rep(j, 1, n) cout << '0';
    cout << endl;
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    p[0] = 1;
    rep(i, 1, N - 5) p[i] = p[i - 1] * P;
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}
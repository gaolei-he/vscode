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
const int N = 10 + 1e3, mod = 1e9 + 7;
char str[N][N];
int n;
int calc(int x, int y)
{
    map<char, int> mp;
    mp[str[x][y]]++;
    mp[str[y][n - x + 1]] ++;
    mp[str[n - x + 1][n - y + 1]] ++;
    mp[str[n - y + 1][x]] ++;
    char c = mp.rbegin()->first;
    int res = 0;
    for(auto [k, v] : mp) res += (c - k) * v;
    return res;
}
void solve()
{
    cin >> n;
    rep(i, 1, n) cin >> str[i] + 1;
    int l = n / 2, r = n / 2, ans = 0;
    rep(i, 1, l)
        rep(j, 1, r)
            ans += calc(i, j);
    cout << ans << endl;
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
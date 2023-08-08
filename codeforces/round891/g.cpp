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
using ar3 = array<int, 3>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 998244353;
void solve()
{
    int n, S; cin >> n >> S;
    vector<ar3> vec(n-1);
    for(auto &[x, y, z] : vec) cin >> x >> y >> z;
    sort(vec.begin(), vec.end(), [](ar3 a, ar3 b) {
        return a[2] < b[2];
    });
    vector<int> p(n+1, 0), sz(n+1, 1);
    iota(p.begin(), p.end(), 0);
    function<int(int)> find = [&](int x) {
        if(x != p[x]) p[x] = find(p[x]);
        return p[x];
    };
    int ans = 1;
    auto quick_pow = [&](int a, int b) {
        int res = 1;
        while(b) {
            if(b & 1) res = res * a % mod;
            b >>= 1;
            a = a * a % mod;
        }
        return res;
    };
    for(auto [x, y, z] : vec)
    {
        int u = find(x), v = find(y);
        ans *= quick_pow(S - z + 1, sz[u] * sz[v] - 1);
        ans %= mod;
        p[u] = v;
        sz[v] += sz[u];
    }
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
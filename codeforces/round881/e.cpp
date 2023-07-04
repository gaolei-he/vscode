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
int a[N], s[N];
void solve()
{
    int n, m; cin >> n >> m;
    vector<pii> query(m);
    for(auto& [k,v]:query) cin >> k >> v;
    int q; cin >> q;
    vector<int> vec(q);
    for(auto& x:vec) cin >> x;
    int l = 0, r = q - 1;
    function<bool(int)> check = [&](int mid) {
        rep(i, 1, n) a[i] = s[i] = 0;
        rep(i, 0, mid) a[vec[i]] = 1;
        rep(i, 1, n) s[i] = s[i - 1] + a[i];
        for(auto& [k, v]:query)
            if(s[v] - s[k-1] > (v - k + 1) - s[v] + s[k-1]) return true;
        return false;
    };
    while(l < r)
    {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    if(!check(l)) cout << -1 << endl;
    else cout << l + 1 << endl;
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
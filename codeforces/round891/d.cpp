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
void solve()
{
    int n; cin >> n;
    vector<int> veca(n), vecb(n);
    for(auto& x : veca) cin >> x;
    for(auto& x : vecb) cin >> x;
    vector<int> query;
    rep(i, 0, n - 1)
        query.push_back(veca[i] - vecb[i]);
    sort(query.begin(), query.end());
    int ans = 0;
    vector<int> vec;
    rep(i, 0, n - 1)
    {
        int val = veca[i] - vecb[i];
        int idx = upper_bound(query.begin(), query.end(), val) - query.begin();
        if(idx == n) ans ++, vec.push_back(i + 1);
    }
    cout << ans << endl;
    for(auto x : vec) cout << x << ' ';
    cout << endl;
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
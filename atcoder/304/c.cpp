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
const int N = 10 + 2e3, mod = 1e9 + 7;
int p[N], n, d;
bool dis(pii a, pii b)
{
    int a1 = a.first, b1 = a.second;
    int a2 = b.first, b2 = b.second;
    return (a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2) <= d * d;
}
int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void solve()
{
    cin >> n >> d;
    rep(i, 1, n) p[i] = i;
    vector<pii> vec(n+1);
    rep(i, 1, n) cin >> vec[i].first >> vec[i].second;
    rep(i, 1, n)
        rep(j, i+1, n)
            if(dis(vec[i], vec[j]))
            {
                p[find(i)] = find(j);
                // cerr << i << ' ' << j << endl;
            }
    int t = find(1);
    rep(i, 1, n)
        if(t == find(i)) cout << "Yes" << endl;
        else cout << "No" << endl;
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
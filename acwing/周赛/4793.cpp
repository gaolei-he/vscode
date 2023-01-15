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
int p[60], sz[60];
int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void solve()
{
    int n, m;
    cin >> n >> m;
    rep(i, 1, 55) p[i] = i, sz[i] = 1;
    rep(i, 1, m)
    {
        int x, y;
        cin >> x >> y;
        int a = find(x);
        int b = find(y);
        if(a == b) continue;
        p[a] = b;
        sz[b] += sz[a];
    }
    set<int> st;
    rep(i, 1, n) st.insert(find(i));
    int ans = 0;
    for(auto i:st)
    {
        if(sz[i] == 1) continue;
        ans += sz[i] - 1;
    }
    cout << (1 << ans) << endl;
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
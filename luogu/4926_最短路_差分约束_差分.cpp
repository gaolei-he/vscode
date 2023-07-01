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
const int N = 10 + 1e5, mod = 1e9 + 7;
bool spfa(vector<vector<ar3>> &g, double t, vector<int>& score)
{
    
}
void solve()
{
    int n, s, t;
    cin >> n >> s >> t;
    vector<vector<ar3>> g(n + 1);
    rep(i, 1, s)
    {
        int o, A, B, k;
        cin >> o >> A >> B >> k;
        if(o == 1) g[A].push_back({B, 1, k});
        else g[B].push_back({A, -1, k});
    }
    double l = 0, r = 1e11;
    vector<int> score(n+1, mod);
    while(r-l>1e-6)
    {
        double mid = (l + r) / 2;
        if(spfa(g, mid, score)) l = mid;
        else r = mid;
    }
    cout << l << endl;
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
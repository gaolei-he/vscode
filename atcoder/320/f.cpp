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
    int n, h; cin >> n >> h;
    vector<pii> vec(N, {0, 0});
    vector<int> tmp(n);
    for(auto &x : tmp) cin >> x;
    for(auto x : tmp)
    {
        if(x == tmp.back()) break;
        int p, f;
        cin >> p >> f;
        vec[x] = {p, f};
    }
    vector<int> dp(tmp.back() + 1, mod);
    rep(i, 1, tmp.back())
    {
        rep(j, max(1, i - h), i - 1)
            if(vec[j].first != 0)
                
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
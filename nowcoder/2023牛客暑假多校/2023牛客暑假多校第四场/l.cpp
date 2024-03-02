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
using sis = tuple<string, int, string>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;
void solve()
{
    int n, m, q; cin >> n >> m >> q;
    vector<sis> vec(q);
    for(auto &[s, x, y] : vec) cin >> s >> x >> y;
    reverse(vec.begin(), vec.end());
    int sm = 0;
    set<int> str, stc;
    for(auto &[s, x, y] : vec)
    {
        if(s == "row")
        {
            if(str.count(x)) continue;
            n --;
            if(y == "on") sm += m;
            str.insert(x);
        }
        else
        {
            if(stc.count(x)) continue;
            m --;
            if(y == "on") sm += n;
            stc.insert(x);
        }
    }
    cout << sm << endl;
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
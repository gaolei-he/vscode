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
    int n, k; cin >> n >> k;
    vector<int> vec1(k), vec2(k);
    string s; cin >> s;
    s = " " + s;
    for(auto &x : vec1) cin >> x;
    for(auto &x : vec2) cin >> x;
    map<pii, vector<pii>> mp;
    rep(i, 0, k - 1) mp[{vec2[i], vec1[i]}] = vector<pii>();
    int q; cin >> q;
    while(q --)
    {
        int x; cin >> x;
        pii tmp = {x, 0};
        auto it = mp.lower_bound(tmp);
        tmp.first = min(x, it->first.first + it->first.second - x);
        tmp.second = max(x, it->first.first + it->first.second - x);
        it->second.push_back(tmp);
    }
    vector<int> ans(n + 10, 0);
    for(auto &[p, vec] : mp)
    {
        map<pii, int> tmpmp;
        for(auto p : vec) tmpmp[p] += 1;
        vec.clear();
        for(auto &[p, x] : tmpmp) if(x & 1) vec.push_back(p);
        if(vec.empty()) continue;
        int l = vec.front().first, r = vec.front().second;
        // for(auto [y, x] : vec) cerr << x << ' ' << y << endl;
        int val = 0;
        for(auto &[x, y] : vec)
        {
            while(l < x) ans[l ++] = ans[r --] = val;
            val ++;
        }
        while(l < r) ans[l ++] = ans[r --] = val;
        l = vec.front().first, r = vec.front().second;
        while(l < r)
        {
            if(ans[l] & 1) swap(s[l], s[r]);
            l ++, r --;
        }
    }
    // rep(i, 1, n) cerr << ans[i] << ' ';
    // cerr << endl;
    rep(i, 1, n) cout << s[i];
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
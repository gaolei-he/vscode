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
#define ll long long
#define int long long
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar3 = array<int, 3>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;
void solve()
{
    int n; cin >> n;
    map<int, pair<pii, int>> mp;
    int res = 1;
    rep(i, 1, n)
    {
        int color, k;
        char c;
        cin >> color >> c >> k;
        if(c == 'L') mp[color].first.first = k;
        else if(c == 'R') mp[color].first.second = k;
        else mp[color].second = k;
    }
    vector<int> ans;
    bool flag = false;
    for(auto&[k, a]:mp)
    {
        vector<int> tmp;
        tmp.push_back(a.first.first);
        tmp.push_back(a.first.second);
        tmp.push_back(a.second);

        res += max(a.first.first, a.first.second);
        if(!max(a.first.first, a.first.second)) res += 1;
        if(tmp[2] >= 2) flag = true;
        sort(tmp.begin(), tmp.end());
        if(tmp[1] && tmp[2]) flag = true;
    }
    if(!flag)
    {
        cout << -1 << endl;
        return;
    }
    for(auto x:ans) res += x;
    cout << res << endl;
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
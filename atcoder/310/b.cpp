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
    int n, m; cin >> n >> m;
    map<int, pair<int, set<int>>> mp;
    rep(i, 1, n)
    {
        int price, cnt; cin >> price >> cnt;
        int x;
        mp[i].first = price;
        rep(j, 1, cnt)
        {
            cin >> x;
            mp[i].second.insert(x);
        }
    }
    rep(i, 1, n)
    {
        rep(j, 1, n)
        {
            bool flag = true;
            if(mp[i].first > mp[j].first) continue;
            for(auto x:mp[j].second)
                if(!mp[i].second.count(x))
                    flag = false;
            if(flag and (mp[i].first < mp[j].first or mp[i].second.size() > mp[j].second.size()))
            {
                // cerr << i << ' ' << j << endl;
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
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
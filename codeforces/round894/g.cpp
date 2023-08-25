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
    map<int, int> mp, mp2;
    vector<int> vec;
    rep(i, 1, n)
    {
        int x; cin >> x;
        vec.push_back(x);
        mp[x]++;
    }
    int q; cin >> q;
    int mx = 0, lst = -1;
    for(auto [k, v] : mp)
    {
        if(lst != -1) mp2[k - lst]++;
        if(lst == -1) lst = k;
        else mx = max(mx, k - lst), lst = k;
    }
    while(q --)
    {
        int i, x; cin >> i >> x;
        int y = vec[i - 1];
        vec[i - 1] = x;
        if(mp.count(x)) mp[x] ++;
        else
        {
            auto it = mp.upper_bound(x);
            if(it == mp.end())
            {
                mp2[x - mp.rbegin()->first] ++;
            }
            else if(it == mp.begin())
            {
                mp2[it -> first - x] ++;
            }
            else
            {
                int r = it -> first, l = (--it) -> first;
                mp2[r - x] ++, mp2[x - l] ++;
                mp2[r - l] --;
                if(mp2[r - l] == 0) mp2.erase(r - l);
            }
            mp[x] ++;
        }
        if(mp[y] > 1) mp[y] --;
        else
        {
            mp.erase(y);
            auto it = mp.upper_bound(y);
            if(it == mp.end())
            {
                mp2[y - mp.rbegin()->first] --;
                if(mp2[y - mp.rbegin()->first] == 0) mp2.erase(y - mp.rbegin()->first);
            }
            else if(it == mp.begin())
            {
                mp2[it -> first - y] --;
                if(mp2[it -> first - y] == 0) mp2.erase(it -> first - y);
            }
            else
            {
                int r = it -> first, l = (--it) -> first;
                mp2[r - y] --, mp2[y - l] --;
                if(mp2[r - y] == 0) mp2.erase(r - y);
                if(mp2[y - l] == 0) mp2.erase(y - l);
                mp2[r - l] ++;
            }
        }
        int ans;
        if(mp2.size()) ans = mp.rbegin() -> first + mp2.rbegin() -> first;
        else ans = mp.begin() -> first;
        cout << ans << ' ';
    }
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
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
#include <unordered_map>
#include <unordered_set>
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
const int N = 10 + 5e7, mod = 1e9 + 7;
int son[N][2], idx;
void insert(string s)
{
    int p = 0;
    for(auto c : s)
    {
        int u = c - '0';
        if(!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
}
int query(string s)
{
    int p = 0, res = 0;
    for(auto c : s)
    {
        int u = c - '0';
        if(!son[p][u]) u = 1 - u;
        p = son[p][u];
        res *= 2;
        res += u;
    }
    return res;
}
void solve()
{
    int n, k; cin >> n >> k;
    while(idx) son[idx - 1][0] = son[idx - 1][1] = 0, idx --;
    vector<int> vec(n);
    int v1 = -1, v2 = -1;
    for(auto &x : vec) cin >> x;
    int mx = linf;
    map<int, vector<int>> mp;
    rep(i, 0, n - 1) mp[vec[i]].push_back(i+1);
    rep(i, 0, n - 1)
    {
        int x = vec[i];
        string s = "";
        rep(j, 0, k - 1) s.push_back(((x >> j) & 1) ? '1' : '0');
        reverse(s.begin(), s.end());
        if(!i)
        {
            insert(s);
            continue;
        }
        int val = query(s);
        if((val ^ x) < mx)
        {
            mx = val ^ x;
            v1 = val, v2 = x;
        }
        insert(s);
    }
    if(mp.count(v1) and mp.count(v2))cout << mp[v1].front() << ' ' << mp[v2].back() << ' ';
    int ans = (~(v1 ^ v2) ^ v1) & ((1 << k) - 1);
    cout << ans << endl;

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
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
const int N = 10 + 2e5, mod = 1e9 + 7;
int tr[2][N];
int lowbit(int x) { return x & -x; }
int n, q;
void add(int x, int v, int op)
{
    for (; x <= N - 5; x += lowbit(x))
        tr[op][x] += v;
}
int sum(int x, int op)
{
    int res = 0;
    for (; x; x -= lowbit(x))
        res += tr[op][x];
    return res;
}
void solve()
{
    cin >> n >> q;
    vector<pii> vec1(n), vec2(q);
    for(auto &[x, y] : vec1) cin >> x >> y;
    for(auto &[x, y] : vec2) cin >> x >> y;
    map<pii, int> mp;
    auto vec3 = vec1, vec4 = vec2;
    sort(vec3.begin(),vec3.end(), [](pii a, pii b){return a.second < b.second;});
    sort(vec4.begin(),vec4.end(), [](pii a, pii b){return a.second < b.second;});
    queue<pii> qq;
    for(auto p : vec3) qq.push(p);
    for(auto [l, r] : vec4)
    {
        if (l > r) continue;
        while(qq.size() and qq.front().second < r)
        {
            auto [ll, rr] = qq.front(); qq.pop();
            add(ll, 1, 0);
            add(rr, 1, 1);
        }
        int val = sum(l, 0);
        val -= sum(l - 1, 1);
        mp[{l, r}] = val;
    }
    qq = queue<pii>();
    sort(vec3.begin(), vec3.end(), [](pii a, pii b){return a.first > b.first;});
    sort(vec4.begin(), vec4.end(), [](pii a, pii b){return a.second > b.second;});
    for(auto p : vec3) qq.push(p);
    rep(i, 1, N - 5) tr[0][i] = tr[1][i] = 0;
    for(auto [l, r] : vec4)
    {
        if(l <= r) continue;
        swap(l, r);
        while(qq.size() and qq.front().first > l)
        {
            auto [ll, rr] = qq.front(); qq.pop();
            // cerr << ll << " " << rr << endl;
            add(ll, 1, 0);
            add(rr, 1, 1);
        }
        int val = sum(r, 0) - sum(l, 0);
        // cerr << val << endl;
        val -= sum(r - 1, 1) - sum(l - 1, 1);
        // cerr << val << endl;
        mp[{r, l}] = val;
        // cout << val << endl;
    }
    for(auto p : vec2) cout << mp[p] << endl;
    /*
    rep(i, 1, n) tr[0][i] = tr[1][i] = 0;
    sort(vec3.begin(), vec3.end(), [](pii a, pii b){return a.first > b.first;});
    sort(vec4.begin(), vec4.end(), [](pii a, pii b){return a.second > b.second;});
    qq = queue<pii>();
    for(auto p : vec3) qq.push(p);
    for(auto [l, r] : vec4)
    {
        if(l <= r) continue;
        swap(l, r);
        while(qq.size() and qq.front().first)
    }*/

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int t; cin >> t;
    // while(t--)
    // freopen("/home/mechrevo/Downloads/5131.in", "r", stdin);
    // freopen("/home/mechrevo/Downloads/5131.out1", "w", stdout);
        solve();

    return 0;
}
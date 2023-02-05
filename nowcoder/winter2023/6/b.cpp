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
#define int long long
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10, mod = 1e9 + 7;
int a[N];
vector<unordered_map<int, int>> vec(N);
vector<pii> v(N, {-1, 0});
int n, q;
unordered_map<int, int> mp;
vector<pii> s;

void f(int x)
{
    for(int j=1;j*j<=x;j++)
    {
        if(x%j || j == x) continue;
        if(v[j].first >= 0) v[j].first ++;
        if(j==1 || j*j==x)continue;
        if(v[x/j].first >= 0) v[x/j].first++;
    }
    if(v[x].first >= 0) v[x].second++;
    if(v[x].first >= 0) vec[x][v[x].second] = v[x].first + 1;
    v[x].first++;
}
void solve()
{
    cin >> n >> q;
    s.push_back({0, 0});
    rep(i, 1, n)
    {
        int x; cin >> x;
        f(x);
        if(mp.count(x)) s.push_back({x, ++mp[x]});
        else s.push_back({x, 0}), mp.insert({x, 0});
    }
    while(q--)
    {
        int op, x;
        cin >> op >> x;
        if(op == 1)
        {
            f(x);
            if(mp.count(x)) s.push_back({x, ++mp[x]});
            else s.push_back({x, 0}), mp.insert({x, 0});
        }
        else
        {
            int t = s[x].second;
            int ans = vec[s[x].first][t];
            ans = v[s[x].first].first -  ans;
            cout << ans << endl;
        }

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
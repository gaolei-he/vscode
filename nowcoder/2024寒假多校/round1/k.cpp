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
const int N = 10 + 1e5, mod = 998244353;
using pis = pair<int, string>;
void solve()
{
    int n; cin >> n;
    vector<pis> vec(n + 1);
    vector<vector<int>> g(n + 1);
    vector<int> f(n + 1);
    iota(f.begin(), f.end(), 0);
    function<int(int)> find = [&](int x) { return f[x] == x ? x : f[x] = find(f[x]); };
    rep(i, 1, n)
    {
        int a; string s;
        cin >> a >> s;
        vec[i] = {a, s};
        g[i].push_back(a);
        f[i] = find(a);
    }
    int ans = 1;
    unordered_set<int> st;
    unordered_set<int> tmp_st;
    auto get_point = [&](int x)
    {
        tmp_st.clear();
        while(!tmp_st.count(x))
        {
            tmp_st.insert(x);
            x = g[x][0];
        }
        return x;
    };
    auto check = [&](int ver, int val)
    {
        int tmp = val;
        int tmp_ver = ver;
        do
        {
            ver = g[ver][0];
            tmp = vec[ver].second[tmp] - 'A';
        } while(ver != tmp_ver);
        if(tmp == val) return true;
        return false;
    };
    rep(i, 1, n)
    {
        if(st.count(find(i))) continue;
        else st.insert(find(i));
        int point = get_point(i);
        int cnt = 0;
        rep(i, 0, 4)
            if(check(point, i)) cnt ++;
        ans = ans * cnt % mod;
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int t; cin >> t;
    int t = 1;
    while(t--)
        solve();

    return 0;
}
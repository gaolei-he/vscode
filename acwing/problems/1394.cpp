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
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 200, mod = 1e9 + 7;
int match[N];
bool st[N];
vector<vector<int>> g;
bool find(int x)
{
    for(auto v:g[x])
    {
        if(!st[v])
        {
            st[v] = true;
            if(match[v] == 0 || find(match[v]))
            {
                match[v] = x;
                return true;
            }
        }
    }
    return false;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    g.resize(max(n, m) + 1);
    rep(i, 1, n)
    {
        int t;
        cin >> t;
        while(t--)
        {
            int x;
            cin >> x;
            g[i].push_back(x);
        }
    }
    int ans = 0;
    rep(i, 1, n)
    {
        memset(st, 0, sizeof(st));
        if(find(i)) ans ++;
    }
    cout << ans << endl;

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
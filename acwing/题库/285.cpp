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
using PII = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 6e3, mod = 1e9 + 7;
bool has_father[N];
int val[N];
int f[N][2];
vector<vector<int>> vec;
void dfs(int i)
{
    f[i][1] = val[i];
    for(auto k:vec[i])
    {
        dfs(k);

        f[i][1] += f[k][0];
        f[i][0] += max(f[k][0], f[k][1]);
    }
}
void solve()
{
    int n; cin >> n;
    vec.resize(n+1);
    rep(i, 1, n) cin >> val[i];
    rep(i, 1, n-1)
    {
        int a, b;
        cin >> a >> b;
        vec[b].push_back(a);
        has_father[a] = true;
    }
    int root = 1;
    while(has_father[root]) root ++;
    dfs(root);
    cout << max(f[root][1], f[root][0]);

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
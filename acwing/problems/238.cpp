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
const int N = 10 + 3e4, mod = 1e9 + 7;
int p[N], d[N], sz[N];
int find(int x)
{
    if(x != p[x])
    {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}
void solve()
{
    int n; cin >> n;
    rep(i, 1, N-4) p[i] = i, sz[i] = 1;
    while(n --)
    {
        int op, i, j;
        cin >> op >> i >> j;
        if(op == 1)
        {
            int a = find(i), b = find(j);
            p[a] = b;
            d[a] += sz[a];
            sz[b] += sz[a];
        }
        else
        {
            int a = find(i), b = find(j);
            if(a != b) cout << -1 << endl;
            else cout << d[i] - d[j] + 1 << endl;
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
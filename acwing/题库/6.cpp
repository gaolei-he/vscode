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
const int N = 10 + 2e4, mod = 1e9 + 7;
int n, V;
int f[N], g[N];
void solve()
{
    deque<int> q;
    cin >> n >> V;
    int v, w, s;
    cin >> v >> w >> s;
    rep(i, 1, n)
    {
        memcpy(g, f, sizeof(g));
        cin >> v >> w >> s;
        rep(j, 0, v-1)
        {
            q.clear();
            for(int k=j;k<=V;k+=v)
            {
                f[k] = g[k];
                if(q.size()) f[k] = max(f[k], q.front() + w);
                // f[i][k] = f[i-1][k-v]+w, f[i-1][k-2*v]+2*w ...
                // f[i][k+v] = f[i-1][k+v], f[i-1][k]+w, f[i-1][k-v]+2*w ...
                // f[i][k+v] = f[i][k] + w;
                while(q.size() && q.back() < k-s*v) q.pop_back();
                q.push_back(k);
            }
        }
    }
    cout << f[V];
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
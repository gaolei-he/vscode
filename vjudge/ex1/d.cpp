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
const int N = (1<<20), mod = 1e9 + 7;
int a[N+10];
int p[N+10];
int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void solve()
{
    memset(a, -1, sizeof(a));
    rep(i, 1, N) p[i] = i;
    int q;
    cin >> q;
    while(q --)
    {
        int t, x;
        cin >> t >> x;
        if(t == 2) cout << a[x%N] << endl;
        else
        {
            int h = x;
            h %= N;
            if(a[h] == -1) a[h] = x;
            else
            {
                int t = (find(h) + 1) % N;
                while(a[t] != -1)
                {
                    p[find(h)] = find(t);
                    t = (find(h) + 1) % N;
                }
                a[t] = x;
            }
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
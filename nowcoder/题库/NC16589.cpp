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
const int N = 10 + 1e3, mod = 1e9 + 7;
int mem[N];
void solve()
{
    int n, m;
    cin >> m >> n;
    memset(mem, -1, sizeof(mem));
    int ip = 0;
    int ans = 0;
    int r = 0;
    rep(i, 1, n)
    {
        int x; cin >> x;
        bool flag = false;
        rep(j, 0, max(ip-1, r-1)) if(mem[j] == x) {flag = true; break;}
        if(flag) continue;
        ans ++;
        if(ip == m) ip = 0;
        mem[ip ++] = x;
        r = max(r, ip);
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
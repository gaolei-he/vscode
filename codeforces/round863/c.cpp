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
const int N = 10 + 2e5, mod = 1e9 + 7;
int b[N], a[N];
void solve()
{
    int n; cin >> n;
    rep(i, 1, n-1) cin >> b[i];
    int index = 0, mi = mod;
    rep(i, 1, n-1) mi = min(b[i], mi);
    bool flag = true;
    a[1] = b[1];
    rep(i, 1, n-1)
    {
        if(a[i] == b[i])
        {
            a[i+1] = b[i];
        }
        else
        {
            if(a[i] > b[i]) a[i] = b[i], a[i+1] = b[i];
            else a[i+1] = b[i];
        }
    }
    rep(i, 1, n) cout << a[i] << ' ';
    cout << endl;
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
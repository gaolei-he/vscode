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
const int N = 10 + 2e5, mod = 1e9 + 7;
int a[N];
void solve()
{
    int n; cin >> n;
    rep(i, 1, n) cin >> a[i];
    int sm = 0;
    rep(i, 1, n) sm += abs(a[i]);
    rep(i, 1, n)
    {
        if(a[i] == 0)
        {
            cout << sm << endl;
            return;
        }
    }
    int cnt = 0;
    rep(i, 1, n) if(a[i] < 0) cnt ++;
    if(cnt % 2 == 0)
    {
        cout << sm << endl;
        return;
    }
    int ma = 2e9;
    rep(i, 1, n) ma = min(abs(a[i]), ma);
    if(ma > -1e9+100) sm -= ma * 2;
    cout << sm << endl;
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
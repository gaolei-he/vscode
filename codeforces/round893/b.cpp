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
const int N = 10 + 1e5, mod = 1e9 + 7;
void solve()
{
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> vec;
    int op = 0;
    rep(i, 1, m)
    {
        int x; cin >> x;
        if(i == 1 and x != 1) vec.push_back(1), op = -1;
        vec.push_back(x);
    }
    m = vec.size();
    int cnt = 0, ans = 2;
    rep(i, 1, m - 2)
    {
        int l = vec[i - 1], r = vec[i + 1], mid = vec[i];
        int c1 = (r - l) / d + 1;
        if((r - l) % d) c1 ++;
        int c2 = (mid - l) / d + 1;
        if((mid - l) % d) c2 ++;
        c2 += (r - mid) / d + 1;
        if((r - mid) % d) c2 ++;
        c2 --;
        if(c1 < c2) cnt ++;
        ans += (mid - l) / d + 1;
        if((mid - l) % d == 0) ans --;
    }
    
    if(vec[m - 1] - vec[m - 2] >= d) ans += (vec[m-1] - vec[m-2]) / d;
    if((vec[m-1]-vec[m-2]) % d == 0) ans --;
    if(vec[m-1] != n) ans += (n - vec[m-1]) / d;

    int l = vec[m-2], r = vec[m-1];
    int c1 = (r - l) / d + 1;
    if((r - l) % d) c1 ++;
    c1 += (n - r) / d;
    int c2 = (n - l) / d + 1;
    if(c2 < c1) cnt ++;
    if(cnt == 0)
    {
        cout << ans << ' ' << m + op << endl;
        return;
    }
    cout << ans - 1 << ' ' << cnt << endl;
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
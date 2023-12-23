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
    int n; cin >> n;
    vector<int> vec(n);
    for(auto &x : vec) cin >> x;
    map<int, int> mpl, mpr;
    int vall = 0, valr = 0;
    int res = linf;
    for(int i=0;i<n;i++) mpr[vec[i] + 1 + i] ++;
    for(int i=0;i<n;i++)
    {
        int ans = 0;
        mpr[vec[i] + 1 + i] --;
        if(mpr[vec[i] + 1 + i] == 0) mpr.erase(vec[i] + 1 + i);
        valr --;
        if(mpr.size()) ans = max(ans, i + mpr.rbegin()->first + valr);
        if(mpl.size()) ans = max(ans, n - i - 1 + mpl.rbegin()->first + vall);
        mpl[vec[i] - vall] ++;
        vall ++;
        res = min(max(ans, vec[i]), res);
    }
    cout << res << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}
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
const int N = 10 + 2e5, mod = 1e9 + 7;
int a[N];
void solve()
{
    int n, k; cin >> n >> k;
    int ans = 0;
    vector<int> vec(n);
    for(auto &x : vec) cin >> x;
    sort(vec.begin(), vec.end());
    int x = 0;
    int val = 0;
    for(auto v : vec)
    {
        if(!x or v - x <= k)
        {
            x = v;
            val ++;
        }
        else
        {
            ans = max(ans, val);
            x = v;
            val = 1;
        }
    }
    ans = max(ans, val);
    cout << n - ans << endl;
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